
 # Conv C++ Implementation

## Overview

This repository contains a C++ Implementation of matlab conv(input, kernel) function using the FFTW3 library.

## Dependencies
Make sure you have the FFTW3 library installed. You can find more information about FFTW3 [here](https://fftw.org).

Download fftw from website and place in  Pwelch folder.

## Usage
### Pwelch Class
The Conv_Corr class is the core of this implementation. It includes a function FFT_Convolution with the following parameters:

- input: The input signal represented as std::complex<double>.
  
- kernel: the polynomial coefficients


### Example

```c++
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
```

## Building
1. create new project in Visual Studio.
2. Configure the project settings if needed.
3. add header and library file of fftw3 to project
4. Build the project using the "Build" menu or by pressing `Ctrl + Shift + B`.
5. Run the executable generated in the output directory or run in Visual Studio.
6. make sure that libfftw3-3.dll is in project directory

## Contributing
Feel free to contribute to this project by submitting issues or pull requests. Your feedback and contributions are highly appreciated.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.


 
 
 # Fast-Convolution-CPP
 Implementation of matlab conv(input, kernel) function.
First download FFTW fftw-3.3.5 at https://www.fftw.org/download.html.
Second, add these files to your project.
