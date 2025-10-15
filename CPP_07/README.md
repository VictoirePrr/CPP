<h1 align="center" style="color:#7B68EE; font-weight:bold;">Chapter 7: Templates</h1>

Imagine you need to create a simple swap function that can swap any data type given. Instead of duplicating this function for each type and wasting your time, you can create a `template`!

## <span style="color:#007BFF; font-weight:bold;">I. Definition</span>

Templates allow you to write generic code that works across different data types. 
In other words, you can now create one single function or class that will be reusable and flexible.

### <span style="color:#5DADE2;">a. How templates work in code</span>

- Defined by the `template` keyword followed by its parameter `typename` :

```c++
template <typename T>
```

- Now `T` can be used instead of a specific type :

```c++
template <typename T>
void swap(T a, T b);
```

- When you send a specific type to the template function, the compiler generates a new instance of the function for that type at compile time, that's called template instantiation.

```c++
template <typename T>
void swap(T a, T b);

int main {
    swap<int>(1, 2);
    swap<char>(a, b);
    return 0;
}
```

### <span style="color:#5DADE2;">b. Templates vs void*</span>

I know what you are thinking. Why bother creating a template when we can use a void*?

- For safety: the compiler checks the data type at compilation time, ensuring the operations are always valid for the given type.
- For error detection: with `void*`, the type information is lost, which requires manual casting, prone to errors and hard-to-diagnose bugs. On the contrary, the compiler generates optimized code for the given type at compile time for templates.
- For quality: `void*` functions are usually cluttered with casts and checks that can easily be avoided with templates.

### <span style="color:#5DADE2;">c. Template argument deduction</span>

In this example:
```c++
int main {
    swap<int>(1, 2);
    return 0;
}
```
We specify the type we want to replace the `T` with. But, we do not always need to specify the actual type. Indeed, `template argument deduction` will have the compiler decide the actual type that should be used. 

This example will work just as well as the first one:
```c++
int main {
    swap(1, 2);
    return 0;
}
```

Specifying the type can be useful for templates with a template class or function as parameters (see "II. Usage, a.Function templates").

> <span style= font-weight:bold;>NOTES</span>  
> It is important to note that `T` can only represent a single type! 
> ```c++
> int main {
>    swap(1, 'A');
>    return 0;
> }
> ```
> This example wouldn't work because `T` can only be one type, either `int` (1) or `char` ('A'), not both.

## <span style="color:#007BFF; font-weight:bold;">II. Usage</span>

### <span style="color:#5DADE2;">a. Function templates</span>

As seen previously, templates can be used to define generic functions. 
Here are the main different syntaxes used:

- Templates with one parameter:
```c++
template <typename T>
void func(T param);
```

- Template with multiple type parameters, allowing you to have different types within the same template:
```c++
template <typename T1, typename T2>
void func(T1 param, T2 param);
```

- Template with a template class parameter (see another chapter for class templates, to do):
```c++
template <template <typename> class Container, typename T>
void func(const Container <T>& Container);
```

- Template with a template function parameter:
```c++
template <typename F>
void test(F func) {
    std::string text = "Hello";
    func(text);
}

template <typename T>
void printText(T &str) {
    std::cout << str << std::endl;
}
```
Here we use a template (`printText`) inside another (`test`). In this case, we must instantiate the function (`printText`) because we cannot pass a function template directly as a template parameter. Instead, we pass a specific instantiation of that template:
```c++
int main  {
    test(printText<std::string>);
}
```

### <span style="color:#5DADE2;">b. Class templates</span>

Just like functions, you can create class templates! These classes can work with any data type, making them far more flexible.  
In terms of declaration, it is pretty similar to functions:

- Template with one parameter:
```c++
template <typename T>
class Array {
    // your implementation
}
```

- Template with multiple type parameters:
```c++
template <typename T1, typename T2>
class Array {
    // your implementation
}
```

- Template with a non-type parameter (a value known at compile time):
```c++
template <int N, typename T>
class Array {
    private : 
        T array[N];
    public :
       N getSize() const { return N };
}

int main() {
    Array<5, int> array;
}
```

As you can see here, we can use the class template parameters in variables and member functions. 
When creating the object `array`, you must specify the desired type or value.

### <span style="color:#5DADE2;">c. About .tpp file and compilation</span>

Templates are not compiled independently like normal classes or functions, they are only compiled when instantiated with a specific type.

```c++
template <typename T>
void swap(T a, T b) {
    //implementation
}

int main {
    swap<int>(1, 2);
    swap<char>(a, b);
    return 0;
}
```

With this example we have, at compilation, this result:

```c++
template <typename T>
void swap(T a, T b) {
    //implementation
}
void swap(int a, int b) {
    //implementation
}
void swap(char a, char b) {
    //implementation
}

int main {
    swap<int>(1, 2);
    swap<char>(a, b);
    return 0;
}
```

As you can see, the compiler created an entirely new function for each specified type. If the template was used in other .cpp files, they will also have their own copy of the template in the type they use.

Unlike non-template functions or classes, the "real" code isn't generated until the compiler sees a concrete type usage.

If the implementation of the template is in, say, a `template.cpp`, the compiler sees the definition template, but no one uses it there, so it doesn’t instantiate anything (templates only instantiate when used!). It creates a `template.o`, but that object file contains no machine code for any specialization.

When compiling the `main.cpp`, it will try to instantiate `swap<int>` but the implementation of that function lives inside the `template.cpp` and the main.cpp doesn't include it.

When linking, the linker will find no compiled definition of that swap template, and you will have a linker error.

To fix this problem, you have two options:

- Put your implementation directly in the header:
```c++
#ifndef SWAP_HPP
#define SWAP_HPP 

template <typename T>
void swap(T a, T b) {
    //implementation
}
```

- Put your implementation in a .tpp file:
```c++
//swap.hpp
#ifndef SWAP_HPP
#define SWAP_HPP 

template <typename T>
void swap(T a, T b);

#include "swap.tpp"

//swap.tpp
template <typename T>
void swap(T a, T b) {
    //implementation
}
```

The file extension `.tpp` (`Template PreProcessor` or `Template Private Parts`) is not special to the compiler, it can be `.tpp`, `.ipp`, `.inl`, or even something else. The most important thing is that your implementation is included in the header.

## <span style="color:#007BFF; font-weight:bold;">V. Sources</span>

Here are the main resources I used to understand and write about templates.  
They include detailed tutorials, articles, and a video that helped me visualize how template instantiation and compilation work !

### a. Video Resources

**The Cherno - C++ Templates Explained Simply**  
https://www.youtube.com/watch?v=I-hZkUa9mIs&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=53

---

### b. Theory and Tutorials

**LearnCPP - Template Instantiation**  
https://www.learncpp.com/cpp-tutorial/function-template-instantiation/#google_vignette  

**ExpertsColumn - void* vs Templates**   
http://ixodoi.expertscolumn.com/article/c-programming-void-vs-templates  

**GeeksforGeeks - Templates in C++**   
https://www.geeksforgeeks.org/cpp/templates-cpp/  

**LearnCPP - Multiple Template Types**  
https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/  

**LearnCPP - Templates in Multiple Files**  
https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/  

**Stack Overflow - Why use .tpp files**  
https://stackoverflow.com/questions/44774036/why-use-a-tpp-file-when-implementing-templated-functions-and-classes-defined-i


<h3 align="center" style="color:#7B68EE;">End of Chapter 7, Templates</h3>
