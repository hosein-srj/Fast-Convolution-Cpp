#include "Conv_Corr.h"

vector<c_double> Conv_Corr::FFT_Convolution(const vector<c_double>& input, vector<double> kernel) {
    int nfft = 4096;
    vector<c_double> frame(nfft), X, kernel_Fft;
    FFTW3_Class fft_obj;

    vector<c_double> state(kernel.size()-1);
    vector<c_double> input_temp(input.size());
    std::copy(input.begin(), input.end(), input_temp.begin());
    vector<c_double> convoleved;


    kernel_Fft = fft_obj.Fft_R2C(kernel,nfft);

    input_temp.resize(input_temp.size() + kernel.size() -1);

    int blockLen = nfft - (kernel.size() - 1);
    int numBlocks = input_temp.size() / blockLen;
    convoleved.resize(input_temp.size());


    for (int i{}; i < numBlocks; ++i) {
        std::copy(state.begin(), state.end(), frame.begin());
        std::copy(input_temp.begin() + i * blockLen, input_temp.begin() + (i + 1) * blockLen, frame.begin() + state.size());
        std::copy(frame.end() - (kernel.size() - 1), frame.end(), state.begin());

        X = fft_obj.Fft_C2C(frame, nfft);
        for (int k{}; k < nfft; ++k)
            frame[k] = (X[k] * kernel_Fft[k]) / (double)nfft;

        frame = fft_obj.iFft_C2C(frame, nfft);
        std::copy(frame.begin() + (kernel.size() - 1), frame.end(), convoleved.begin() + i * blockLen);
    }
    if (input_temp.size() % blockLen != 0) {
        std::copy(state.begin(), state.end(), frame.begin());
        std::copy(input_temp.begin() + numBlocks * blockLen, input_temp.end(), frame.begin() + state.size());
        X = fft_obj.Fft_C2C(frame, nfft);
        for (int k{}; k < nfft; ++k)
            frame[k] = (X[k] * kernel_Fft[k]) / (double)nfft;

        frame = fft_obj.iFft_C2C(frame, nfft);
        std::copy(frame.begin() + (kernel.size() - 1), frame.begin() + (kernel.size() - 1) + (convoleved.size() - numBlocks * blockLen), convoleved.begin() + numBlocks * blockLen);
    }

    return convoleved;
}
