# Chapter 10. Generic Algorithms

## [Exercise 10.1](https://github.com/Direct-Leo/CppPrimer/blob/main/ch10/ex10_1.cpp)

## [Exercise 10.2](https://github.com/Direct-Leo/CppPrimer/blob/main/ch10/ex10_2.cpp)

## [Exercise 10.3](https://github.com/Direct-Leo/CppPrimer/blob/main/ch10/ex10_3.cpp)

## Exercise 10.14

> <font size=4>Write a lambda that takes two ints and returns their sum.</font>

```c++
//version1:
[](int a,int b) ->return int {a+b};
//version2:
auto sum = [](int lhs,int rhs){return lhs + rhs; };
```

## Exercise 10.15

> <font size=4>Write a lambda that captures an int from its enclosing function and takes an int parameter. The lambda should return the sum of the captured int and the int parameter.</font>

```c++
int capt = 5
auto val = [capt](int temp){return capt + temp; };
```

