#include "FFTW3_Class.h"


vector<std::complex<double>> FFTW3_Class::Fft_C2C(const vector<c_double>& input, const int& nfft) {
    vector<c_double> input_sig(nfft);
    vector<c_double> output_sig(nfft);
    std::copy(input.begin(), input.begin() + input.size(), input_sig.begin());

    fftw_plan plan = fftw_plan_dft_1d(nfft, reinterpret_cast<fftw_complex*>(input_sig.data()), reinterpret_cast<fftw_complex*>(output_sig.data()), FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return output_sig;
}

vector<std::complex<double>> FFTW3_Class::iFft_C2C(const vector<c_double>& input, const int& nfft) {
    vector<c_double> input_sig(nfft);
    vector<c_double> output_sig(nfft);

    std::copy(input.begin(), input.end(), input_sig.begin());

    fftw_plan plan = fftw_plan_dft_1d(nfft, reinterpret_cast<fftw_complex*>(input_sig.data()), reinterpret_cast<fftw_complex*>(output_sig.data()), FFTW_BACKWARD, FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return output_sig;
}

vector<std::complex<double>> FFTW3_Class::Fft_R2C(const vector<double>& input, const int& nfft) {
    vector<c_double> input_comp(nfft);
    for (int i{}; i < (int)input_comp.size(); ++i) {
        if (i < (int)input.size())
            input_comp[i].real(input[i]);
    }

    std::vector<std::complex<double>> output_sig(nfft);

    fftw_plan plan = fftw_plan_dft_1d(nfft, reinterpret_cast<fftw_complex*>(input_comp.data()),
                                          reinterpret_cast<fftw_complex*>(output_sig.data()),
                                          FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return output_sig;
}
