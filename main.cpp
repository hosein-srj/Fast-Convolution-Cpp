#include "Conv_Corr.h"
#include "defines.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Conv_Corr conv;
    vector<c_double> inp(50000);
    for(int i=0;i< (int)inp.size();i++){
        inp[i].real(i*2);
        inp[i].imag(i*2+1);
    }
    vector<double> kernel(512);
    for(int i=0; i< (int)(kernel.size());i++){
        kernel[i] = i;
    }

    vector<c_double> out = conv.FFT_Convolution(inp, kernel);    
    return ;
}
