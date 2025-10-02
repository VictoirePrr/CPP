## <h1 style="text-align:center;">Chapter 6 : Casts</h1>

## I. Conversion of scalar types
Conversion of scalar type in c++ allows a value (like int, float, char, bool...) to be interpreted and used as another tpe, either at compile time (automatic) or by the programmer (manually).

### a. Implicit or Explicit conversions
The compiler will convert a value to another compatible type when needed, that is an implicit conversion : 
```bash
1 + 'a' 
# 'a' will automaticaly be converted to 97, its ASCII decimal value.
1 + 97 = 98
``` 
When the programmer intentionnaly changes the type of a value, that is an explicit conversion :
```bash
char x;
static_cast<int>(x);
# x is now an int.
``` 
### b. To handle with care
When converting a type, a good practice is to follow the promotion order :
- bool -> short -> int -> unsigned int -> long -> long -> unsigned long -> float -> double -> long double

This prevents risks of data loss by truncation or rounding when precision matters. Nevertheless it is not required for simple casting as long as the types are compatible.

### c. Execution 
For explicit conversions the compiler inserts instructions for the CPU to perform data transformation or bit reinterpretation during program execution.

```bash
12.375f = 1.546875₂ x 2³

```


> **_NOTE:_**  
> IEEE floating point representation:  
> A `float` in C++ is a 32-bit binary value and its bit pattern is defined by the IEEE 754 standard. They are split as follows:  
> - 1 bit for sign (0 = + | 1 = -)  
> - 8 bits for exponent (without bias = exponent - 127), shows how far it had to move the point so that there is only one number left before the point.  
> - 23 bits for mantissa (holds the significant digits)  
>  ex :  
> 2.5 = 10(2).1(0.5) <sub>2</sub> → this is its binary representation  
> 1.01 <sub>2</sub> × 2<sup>1</sup> → this is normalized. The mantissa is 01.


