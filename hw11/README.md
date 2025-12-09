# Assignment 11 – Newton–Raphson Root Finder

**Source file:** `sean_sinchi_hw_11.cpp`  
**Course:** PHY 277 – Computational Physics  
**Language:** C++

## Purpose

Implement the Newton–Raphson method to find roots of the nonlinear function


f(x) = x + 3sin(2x)


The goal is to practice:

- Writing and calling functions in C++
- Using loops for iterative numerical methods
- Implementing a convergence criterion
- Handling potential numerical issues (small derivatives)

## What the program does

1. Prompts the user for an **initial guess** for the root.
2. Uses the Newton–Raphson update
   
   x_{n+1} = x_n - f(x_n) / f'(x_n)
   
   where  
   
   f(x) = x + 3sin(2x),  f'(x) = 1 + 6cos(2x).
   
3. Iterates until either:
   - \(|x_{n+1} - x_n| < epsilon * |x_n|\) with \(epsilon = 10^{-6}\), or  
   - a maximum number of iterations is reached.
4. Detects when \(|f'(x)|\) is too small and prints a warning that the method may overflow or fail.
5. Prints the approximated root to `STDOUT` or a failure message.

The header comment in the `.cpp` file also records:

- How many distinct roots were found for this function
- Approximate values of the roots
- Example initial guesses that lead to each root

## How to compile and run

```bash
g++ -o sean_sinchi_hw_11 sean_sinchi_hw_11.cpp
./sean_sinchi_hw_11
