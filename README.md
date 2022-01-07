# Fixed-Point-vs-Floating-point
## A Report Presented for the lab assignment on Comparison of Matrix multiplication using floating-point and fixed-point representation.

### Following task has been performed
```
- Made a project structure with following folders
  - Include
  - Lib
  - Src
  - Obj
- Written a ‘make’ file
- Implemented fixed point and floating-point matric multiplication
- Varied the size of matrix in each iteration
- In each iteration matrices were initialized with random floating point numbers.
- Time taken for each matrix multiplication was calculated for floating point and fixed point implementation.
- Following values have been written into a file for each iteration
- Log of Size of the matrix
- Time taken for Floating point Multiplication
- Time taken for Fixed point Multiplication
- A graph had been plotted using gnu plot
- Everything has been implemented such that if you type ‘make’ in the terminal window, the required graph will be generated.
- Finally, a graph has been plotted in MATLAB to compare with C program implementation
- Maximum size of the square matrix has been limited to 1000 because of high compilation time.
```
### THEORY
#### FIXED POINT MULTIPLICATION 

This representation has fixed number of bits for integer part and for fractional part. For example, if given fixed-point representation is IIII.FFFF, then you can store minimum value is 0000.0001 and maximum value is 9999.9999. There are three parts of a fixed-point number representation: The sign field, integer field, and fractional field.

                          ![image](https://user-images.githubusercontent.com/86975877/148544440-ea75cccd-951c-4ad5-ae3b-189995c75f90.png)

The advantage of using a fixed-point representation is performance and disadvantage is relatively limited range of values that they can represent. So, it is usually inadequate for numerical analysis as it does not allow enough numbers and accuracy.
Fixed-point numbers help control resource expense on hardware by eliminating the logic requirements for dynamic range shifts inherent in floating-point operations.
Many FPGAs either do not support floating-point arithmetic or cannot process floating-point operations efficiently. Without a dedicated Floating-Point Unit (FPU), floating-point arithmetic requires significant logic resources on hardware, increases the number of clock-cycles required per operation, and reduces the processing efficiency of the device.
Fixed-point numbers provide the following advantages:
- No need for logic to support dynamic shifts—Floating-point operations require a dynamic shift, or float, of the exponent used to scale the significand, or base number, at run time. With fixed-point numbers, the exponent value is defined by the fixed-point data type and is not computed at run time. Also fixed-point numbers eliminate the need for the hardware logic to calculate and perform dynamic shifts.
- Greater control of FPGA resource costs—The fixed-point data type allows you to exercise greater control of FPGA resources by specifying non-standard bit sizes and coercion options that can conserve memory and logic resources. By specifying the word lengths and coercion behaviors for all terminals and operators in code designed to run on hardware, you optimize the performance of your device or system.

### FLOATING POINT REPRESENTATION:
This representation does not reserve a specific number of bits for the integer part or the fractional part. Instead, it reserves a certain number of bits for the number (called the mantissa or significand) and a certain number of bits to say where within that number the decimal place sits (called the exponent).
The floating number representation of a number has two parts: The first part represents a signed fixed-point number called mantissa. The second part of designates the position of the decimal (or binary) point and is called the exponent. The fixed-point mantissa may be fraction or an integer. Floating point is always interpreted to represent a number in the following form: M x re Only the mantissa M and the exponent e are physically represented in the register (including their sign). A floating-point binary number is represented in a similar manner except that is uses base 2 for the exponent.


