<h1 align="center" style="color:#7B68EE; font-weight:bold;">Chapter 7: Templates</h1>

Imagine you have to create a simple swap function that can swap any data type given. Instead of duplicating this function for each type and waste your time, you can create a `template`!

## <span style="color:#007BFF; font-weight:bold;">I. Definition</span>

Templates allows you to write generic code that works accross different data types. 
In other words, you can now create one single function that will be reusable and flexible.


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

- When you send a specific type to the template function, the compiler generate a new instance of the function for that type at compile time, that's called `Template instantation`.

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

I know what you are thinking. Why bother creating a template when we can use a void* ?

- For safety : the compiler check the data type at compliation time ensuring the operations are always valid for the type given.
- For error detection : with void* the type information is lost which recquires manual casting which is prone to errors and bugs hard to diagnose.On the contrary, the compiler generates optimized code for the given type at runtime for templates.
- For quality : void* functions are usually cluttered with casts and checks that can easily be avoided with templates.

### <span style="color:#5DADE2;">c. Template argument deduction</span>

In this exemple :
```c++
int main {

    swap<int>(1, 2);
    return 0;
}
```
We specify the type we want to replace the `T` with. But, we do not always need to specify the actual type. Indeed, `template argument deduction` will have the compiler decide the actual type that should be used. 

This exemple will work just as well as the first one :
```c++
int main {

    swap(1, 2);
    return 0;
}
```

Specifying the type can be usefull for templates with a template class or function as parameters (see "II. Usage, a.Function templates").

> <span style= font-weight:bold;>NOTES</span>  
> It is important to note that `T` can only represent a single type ! 
> ```c++
> int main {
>
>    swap(1, 'A');
>    return 0;
>}
> ```
> This exemple wouldn't work because `T` can either be an int (1) or a char (A) not both.

## <span style="color:#007BFF; font-weight:bold;">II. Usage</span>

### <span style="color:#5DADE2;">a. Function templates</span>

As seen previously, templates can be used to define generic functions. 
Here are the main different syntaxes used :

- Templates with one parameter :
 ```c++
template <typename T>
void func(T param);
```

- Template with multiple type parameter, allow you to have different types within the same template :
 ```c++
template <typename T1, typename T2>
void func(T1 param, T2 param);
```

- Template with a template class parameter (see other chapter for classes (to do)) :
 ```c++
template <template <typename> class Container, typename T>
void func(const Container <T>& Container);
```

- Template with a template function parameter  :
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
Here we use a template (printText) inside another (test). In this case we must instantiate the function (printText) because we cannot pass a function template directly as a template parameter. Instead, you pass a function instantiated from that template :
 ```c++
int main  {
    test(printText<std::string>);
}
```

### <span style="color:#5DADE2;">a. Class templates</span>





## <span style="color:#007BFF; font-weight:bold;">V. Sources</span>

### a. Video Resources

https://www.youtube.com/watch?v=I-hZkUa9mIs&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=53

---

### b. Theory and Tutorials

https://www.learncpp.com/cpp-tutorial/function-template-instantiation/#google_vignette
http://ixodoi.expertscolumn.com/article/c-programming-void-vs-templates
https://www.geeksforgeeks.org/cpp/templates-cpp/

https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/



<h3 align="center" style="color:#7B68EE;">End of Chapter 7, Templates</h3>