#ifndef CONV_CORR_H
#define CONV_CORR_H

#include "defines.h"
#include "FFTW3_Class.h"
#include <vector>

class Conv_Corr
{
public:
    Conv_Corr(){}

    vector<c_double> FFT_Convolution(const vector<c_double>& input, vector<double> kernel);
};

#endif // CONV_CORR_H
