# CPP

## 7. Diving In

### C++ Program Execution Model & Memory Model

![Alt text](image/program_execution.jpg)

## 9. Operations on Data

### Weird Integral Types

```
    short int x = 10;
    short int y = 20;
    auto z = x + y; // z will be integer because int is the smallest type for which we can support these arithmetic operations.
    std::cout << z;
```

## 10. Literals and Constants

## 13. Variable Lifetime and Scope

## 17. Pointers

### Pointer to char

```
char *str = "Hello";
str[0] = 'x'; // Not work because str here is pointed to a constant string => can not modify.
str = "Halo"' // It's work because str just point to another address, don't modify "Hello" string.
```

### Const pointer and pointer to const

#### Pointer to const:

```
int a = 5, b = 7;
const int *pa = &a; // pa here is a pointer to constant.
*pa = 10; // Not work, can not modify a through pa.
pa = &b; // It's work because a pointer to const can pointer to another variable.
```

#### Const pointer:

```
int a = 5, b = 6;
int *const pa = &a; // pa is a const pointer
pa = &b; // A const pointer can not point to another variable.
*pa = 7; // But a const pointer can modify value of a through pa.

```

#### Const pointer to const: Can not change either the pointer or the data in the pointer

```
int a = 5, b = 6;
const int *const pa = &a; // pa here is a const pointer to const.
pa = &b; // pa can not point to another variable.
*pa = 10; // Can not modify the value of a through pa.
```

#### NOTE

1. Can not set up a modifiable pointer to const data.

```
const int a = 4;
int *pa = &a; // Error: pa is a modifiable pointer. So, it can not point to a const variable.
const int *pa = &a; // work
const int *const pa = &a; // work
```

### Array of const pointer to const char

```
const char *students[] {
    "nguyen van a",
    "nguyen van b",
    "nguyen van c",
}; /* students is an array of const char. So each element of this array is a pointer to const */

// *students[0] = 'X'; // Not work
students[0] = "nguyen van x"; // work
```

### Dynamic Memory Allocation

```
RULES:
1. Don't try to use a pointer that didn't initialize.
2. Don't try to work with a pointer that is pointing to null.
```

![Alt text](image/mem_layout.jpg)

### Dangling Pointer

```
1. Uninitialized Pointer.
    Use Pointer before initialize => crash.
    -> Initialize pointer after using.
2. Deleted Pointer.
    Use Pointer after delete => crash.
    -> Reset pointer to null after delete.
3. Multiple Pointers pointing to same memory.
    int *pa = new int (83);
    int *pb = pa;
    std::cout << *pb; // work
    delete pa;
    std::cout << *pb; // not work
    After delete pa, pb currently points to deleted memory => crash.
    -> If using multiple pointers to the same address, make sure the owner pointer is very clear.
```

## 18. References

### Declaring and using references

```
1. The references can be use like the original variables.
    int a {5};
    int &ra = a;
    std::cout << (ra == a); // true
    std::cout << (&ra == &a); // true
    std::cout << (sizeof(int) == sizeof(int&)); // true
```

#### NOTE

```
1. Modify the value of the reference will reflect the value of the original variable.
2. Modify the value of the original variable will reflect the value of the reference.
3. The Reference is alias to the variable. It can be use pretty much the same way of using variable.
```

### Comparing pointers and references

![Alt text](image/pointer_reference.jpg)

```
int a = 5, b = 10;
int &ra = a;
ra = b; // ra here is not reference the variable b. ra is still reference the variable a.
```

```
int &ra; // Error, because reference must be initialized at declaration
```

```
References behave like constant pointers, because they can not reference another variable.
But they don't require dereferencing to read and write like constant pointers.
```

### References and const

1. Const Reference

```
int a = 5;
const int &ra = a;
ra = 10; // Error. Can not modify the original variable through reference in this case.

```

```
The Reference by default is just like a constant pointer. (&a ~ int *const pa).
=> const int &a ~ const int *const pa.
Const applies to reference variable name, not to the original variable.
    int a = 5;
    const int &ra = a;
    ra = 10; // Error.
    a = 10; // Work
```

## 20. Functions

### Pass by value

```
- Not recommended for relatively large types (user defined).
- Make copies: Can waste memory if the parameter is large type.
```

### Pass by reference

```
- Does not make copies.
- Change the parameter are reflected the original variable.
- Saves memory.
- Recommended for passing around large types (ex: user defined)

```

### Pass by pointer

```
- Can go through dereferencing the parameter and make the changes reflected outside the scope of the function.
- Avoid copies (a pointer is very cheap to copy).
- Recommended for passing around large types (user defined).
```

### Implicit conversions with references

### Implicit conversions with pointers

## 23. Getting things out of functions

### Return by value

![Alt text](image/return-by-val.jpg)

```
- If a function return by value like std::string. Suppose the string is returned has 1000 characters inside.
=> Copying this string would be a waste. So, the compiler will do some magic, compiler is not going to return
by value. It's going to do some kind of return by reference (not really return by reference).
```

### Return by reference

![Alt text](image/return-by-ref1.jpg)

#### References to local variables

![Alt text](image/return-by-ref2.jpg)

```
Local variables are destroyed when the function terminates or finishes executing. So, trying to use the reference
to theses local variable to do anything with the data that is referenced (ex: modifying) will cause undefined
behavior (crash) because the function and its memory are going to be destroyed, they are no longer exist.
```

### Return by pointer

#### Pointers to local variables

![Alt text](image/return-by-pointer.jpg)

```
This problem is the same with references to local variable.
```

### Type deduction

```

```

## 24. Function overloading

```
Function overloading is a mechanism in C++ to have multiple copies of the same function but taking different parameters.
```

## 25. Lambda Functions

![Alt text](image/lambda-functions.jpg)

```
A mechanism to set up anonymous functions (without names). Once, they can be given a name and can be called or can be used
to do things directly.
```
