<h1 align="center" style="color:#7B68EE; font-weight:bold;">Chapter 6: Casts</h1>

## <span style="color:#007BFF; font-weight:bold;">I. Conversion of Scalar Types</span>

Conversion of scalar types in C++ allows a value (like `int`, `float`, `char`, `bool`, etc.)  
to be interpreted and used as another type, either at compile time (automatic)  
or by the programmer (manually).

### <span style="color:#5DADE2;">a. Implicit or Explicit Conversions</span>

The compiler will convert a value to another compatible type when needed,
that’s an implicit conversion:

```cpp
1 + 'a';
// 'a' will automatically be converted to 97, its ASCII decimal value.
// 1 + 97 = 98
```

When the programmer intentionally changes the type of a value,  
that’s an explicit conversion:

```cpp
char x;
static_cast<int>(x);
// x is now treated as an int.
```

### <span style="color:#5DADE2;">b. To Handle With Care</span>

When converting types, follow the promotion order to avoid data loss:

```
bool → short → int → unsigned int → long → unsigned long → float → double → long double
```

This prevents truncation or rounding errors when precision matters.  
It’s not mandatory for simple casts, as long as the types are compatible.

### <span style="color:#5DADE2;">c. Execution</span>

For explicit conversions, the compiler adds CPU instructions  
to transform or reinterpret data bits at runtime.

```cpp
float num = 12.375f; // 1.546875₂ × 2³ in bits
static_cast<int>(num) = 12; // Fractional part discarded

int letter = 65; // 1000001 in bits
static_cast<char>(letter) = 'A'; // CPU pads bits to fit 8-bit char
```

> <span style= font-weight:bold;>NOTES</span>  
> IEEE Floating-Point Representation (IEEE 754): 
> - 1 bit → sign (0 = +, 1 = −)  
> - 8 bits → exponent (value − 127 = real exponent)  
> - 23 bits → mantissa (significant digits)  
> Example:  
> `2.5 = 10(2).1(0.5)₂ → 1.01₂ × 2¹` → normalized form  
> Mantissa = `01`

## <span style="color:#007BFF; font-weight:bold;">II. Converting a String</span>

### <span style="color:#5DADE2;">a. stringstream (<sstream>)</span>

`std::stringstream` creates a buffer containing a string `s`.  
The `>>` operator then parses and converts it according to the destination variable’s type:

```cpp
std::string s = "42";
double result;

std::stringstream ss(s);
ss >> result;

result = 42.0;
```

Useful functions:
- `ss.fail()` → true if conversion failed (e.g. `"Hello"` → int)  
- `ss.eof()` → true if characters remain after conversion (e.g. `"123abc"`)  
- `ss.peek()` → checks the next character (useful for decimals like `"9.6"`)

### <span style="color:#5DADE2;">b. inf and NaN</span>

- `inf` → represents infinity in floating-point computations (positive or negative)  
- `NaN` (Not a Number) → represents undefined floating-point results.  
  `NaN` is never equal to itself.

## <span style="color:#007BFF; font-weight:bold;">III. Converting an Object or Data Structure</span>

Sometimes, you want two pointers to refer to the same memory,  
even if they belong to unrelated types.  
This is where reinterpret_cast comes in.

### <span style="color:#5DADE2;">a. reinterpret_cast</span>

It converts one pointer type to another unrelated pointer type, bit by bit.

- A pointer stores an address as a pattern of bits.  
- You can copy these bits into a numeric variable like `uintptr_t`.  
- The bit pattern stays the same, only its interpretation changes.

```cpp
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
```

> <span style=font-weight:bold;>NOTES</span>  
> - You can only convert raw data members, not functions.  
> - Be mindful: manipulating reinterpreted data can cause undefined behavior when converting back.

## <span style="color:#007BFF; font-weight:bold;">IV. Dynamic Casts</span>

### <span style="color:#5DADE2;">a. Upcasting</span>

```cpp
Base* basePtr = new Derived();
```

- Moves up the inheritance chain (`Derived → Base`)  
- Converts a specific type to a general one  
- Always safe and can be implicit

### <span style="color:#5DADE2;">b. Downcasting</span>

Downcasting converts a base class pointer/reference  
back to a derived one, moving down the hierarchy.

Used to:
- Access class-specific functions or attributes  
- Identify the actual object type at runtime  
- Must be explicit

```cpp
void identify(Base* base) {
    Derived* derivedPtr = dynamic_cast<Derived*>(base);
    if (derivedPtr)
        derivedPtr->printClass();
}

void identify(Base& base) {
    try {
        Derived& derivedRef = dynamic_cast<Derived&>(base);
        derivedRef.printClass();
    } catch (const std::exception& e) {}
}
```

Why use `dynamic_cast`?
- Checks validity at runtime  
- Returns `nullptr` if pointer cast fails  
- Throws `bad_cast` if reference cast fails

> <span style= font-weight:bold;>NOTES</span>  
> - Requires virtual functions to enable RTTI (Run-Time Type Information).  
> - RTTI depends on the vtable, which keeps track of an object’s dynamic type.

## <span style="color:#007BFF; font-weight:bold;">V. Sources</span>

### a. Video Resources
- [Casts in C++ (YouTube)](https://www.youtube.com/watch?v=CiHfz6pTolQ)  
- [Type Casting and `reinterpret_cast` (YouTube)](https://www.youtube.com/watch?v=3ptV83oiv-8)

---

### b. Theory and Tutorials
- [Simplilearn – `static_cast` in C++](https://www.simplilearn.com/tutorials/cpp-tutorial/static-cast-in-cpp)  
- [GeeksforGeeks – `static_cast` in C++](https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/)  
- [GeeksforGeeks – `dynamic_cast` in C++](https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/)  
- [LearnCPlusPlus.org – How to Use `dynamic_cast`](https://learncplusplus.org/this-is-how-to-use-dynamic_cast-in-c/)  
- [StudyPlan.dev – Downcasting](https://www.studyplan.dev/intro-to-programming/downcasting)  
- [PrepInsta – Downcasting in C++](https://prepinsta.com/c-plus-plus/downcasting/)  
- [EmbeddedRelated – Understanding Type Casting](https://www.embeddedrelated.com/showarticle/532.php)

---

### c. Implementation and Examples
- [GeeksforGeeks – Serialize and Deserialize an Object](https://www.geeksforgeeks.org/cpp/serialize-and-deserialize-an-object-in-cpp/)  
- [StudyPlan.dev – String Streams in C++](https://www.studyplan.dev/pro-cpp/string-streams)

---

### d. Mathematical and Edge Cases
- [Stack Overflow – Infinity vs NaN Values](https://stackoverflow.com/questions/58167458/infinity-vs-nan-values)

<h3 align="center" style="color:#7B68EE;">End of Chapter 6, Casts in C++</h3>