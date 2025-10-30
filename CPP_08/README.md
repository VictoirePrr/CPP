# <h1 align="center" style="color:#7B68EE; font-weight:bold;">Chapter 8: Templated Containers, Iterators, and Algorithms</h1>

## <span style="color:#007BFF; font-weight:bold;">I. The Standard Template Library (STL)</span>

The Standard Template Library (STL) provides a collection of template-based container classes designed to store and manage collections of objects efficiently.

### <span style="color:#5DADE2;">a. What Are STL Containers</span>

STL containers are class templates that hold multiple objects, known as elements.  
They allow you to access, modify, insert, or remove elements through **member functions** and **iterators**.

When you instantiate a container, you specify the type of the elements it will store:

```c++
std::vector<int> numbers;   // a vector storing integers
std::list<std::string> names;  // a list storing strings
```

Because they are **templates**, containers can hold any type of element : integers, strings, or even user-defined classes.


### <span style="color:#5DADE2;">b. The Four Types of STL Containers</span>

The STL provides four major types of containers, each with its own internal structure and use cases.


#### 1. Sequence Containers

These containers store elements **in a linear order**, according to their **insertion sequence**.  
They behave much like arrays or linked lists.

**Examples:**
- **`std::vector`**: a dynamic array that grows automatically when needed.  
- **`std::deque`**: similar to a vector but allows fast insertion and deletion at both ends.  
- **`std::list`**: a doubly linked list allowing quick insertion/removal anywhere.  
- **`std::array`**: a fixed-size array wrapper.  
- **`std::forward_list`**: a singly linked list, lighter but with fewer operations.

```c++
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
```


#### 2. Associative Containers

These containers store elements **in a sorted order** using **keys**.  
They are typically implemented as balanced binary trees (usually Red-Black Trees).  
The elements are automatically kept in order based on the comparison criteria.

**Examples:**
- **`std::set`**: stores unique elements in sorted order.  
- **`std::multiset`**: similar to set, but allows duplicates.  
- **`std::map`**: stores key-value pairs with unique keys.  
- **`std::multimap`**: allows multiple pairs with the same key.

```c++
#include <map>
#include <iostream>

int main() {
    std::map<std::string, int> ages;
    ages["Alice"] = 25;
    ages["Bob"] = 30;

    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
        std::cout << it->first << " is " << it->second << " years old." << std::endl;
    }
}
```


#### 3. Unordered Associative Containers

These containers store elements **without any particular order**, using **hash tables** for extremely fast lookups (average constant time complexity).  
Instead of sorting by keys, they use a hash function to determine where each element is stored internally.

**Examples:**
- **`std::unordered_set`**
- **`std::unordered_multiset`**
- **`std::unordered_map`**
- **`std::unordered_multimap`**

```c++
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> values;
    values.insert(42);
    values.insert(100);
    values.insert(7);

    for (std::unordered_set<int>::iterator it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
```


#### 4. Container Adapters

Adapters do not introduce new containers but rather **adapt existing sequence containers** to provide a specific interface.  
They hide most of the underlying container’s operations, exposing only what is necessary for their purpose.

**Examples:**
- **`std::stack`**: provides LIFO (Last-In, First-Out) access.  
- **`std::queue`**: provides FIFO (First-In, First-Out) access.  
- **`std::priority_queue`**: always keeps the largest (or smallest) element at the top, based on comparison.

```c++
#include <stack>
#include <iostream>

int main() {
    std::stack<int> s;
    s.push(5);
    s.push(10);
    s.push(15);

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}
```


---

## <span style="color:#007BFF; font-weight:bold;">II. Iterators</span>

Usually used to iterate through data structures, iterators are usefull tools when working with STL Containers.

### <span style="color:#5DADE2;">a. Definition</span>

An **iterator** is an object that behaves like a pointer, referring to elements within a container.  
You can use it to move from one element to another and to access or modify the element’s value.

```c++
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::vector<int>::iterator it = vec.begin();  // points to the first element
    std::vector<int>::iterator end = vec.end();    // points just after the last element

    while (it != end) {
        std::cout << *it << std::endl;  // dereference iterator to access value
        ++it;                           // move to next element
    }
}
```

Iterators are usually obtained through **member functions** like `.begin()` and `.end()`.  
They overload operators such as `*` (dereference) and `++` (increment) to behave like pointers, providing additionnal safety as it stays an object even when manipulating elements rather than using raw pointer that are error-prone.

```c++
*it;     // Access the value the iterator points to
++it;    // Move to the next element
--it;    // Move to the previous element
```

Iterators come in several types, such as:
- **Input/Output iterators** (basic read/write)
- **Forward iterators**
- **Bidirectional iterators**
- **Random-access iterators** (used by `vector`, `deque`, etc.)
