#ifndef FFTW3_CLASS_H
#define FFTW3_CLASS_H

#include <vector>
#include <complex>
#include <QDebug>
#include "defines.h"
#include "fftw3.h"
using namespace std;

class FFTW3_Class
{
public:
    FFTW3_Class(){}

    vector<c_double>  Fft_C2C(const vector<c_double>& input, const int& nfft);
    vector<c_double> iFft_C2C(const vector<c_double>& input, const int& nfft);
    vector<c_double>  Fft_R2C(const vector<double>  & input, const int& nfft);
};

#endif // FFTW3_CLASS_H
