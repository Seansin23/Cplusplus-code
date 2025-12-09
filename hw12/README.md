# Assignment 12 – Linear Least-Squares Fit with File I/O

**Source file:** `sean_sinchi_hw_12.cpp`  
**Course:** PHY 277 – Computational Physics 
**Language:** C++

## Purpose

Write a C++ program that:

1. Reads an arbitrary number of 2D data points (x_i, y_i) from a text file.
2. Sorts the points by increasing (x).
3. Fits a straight line
   y(x) = mx + b
   using the least-squares method.
4. Computes and prints the **slope** (m), **intercept** (b), and **chi-squared** of the fit.
5. Writes the sorted data and fitted values to a new file for plotting.

This assignment practices:

- Basic file I/O with `std::ifstream` and `std::ofstream`
- Dynamic memory allocation with `new[]` / `delete[]`
- Array manipulation and sorting
- Implementing the closed-form least-squares formulas

## What the program does

1. Prompts the user for:
   - The **input** file name (ASCII file, two columns: `x y`).
   - The **output** file name.
2. Opens the input file and counts how many data points it contains.
3. Dynamically allocates two arrays:
   - `x_array[num_pnts]`
   - `y_array[num_pnts]`
4. Reads all data points into the arrays.
5. Sorts the `(x, y)` pairs by increasing `x` using a **bubble sort**, keeping each pair together.
6. Computes the sums:
   - `sumx = Σ x_i`
   - `sumy = Σ y_i`
   - `sumxx = Σ x_i^2`
   - `sumxy = Σ x_i y_i`
7. Uses the standard least-squares formulas:
 
   m = (N * sumx_i y_i - sumx_i * sum y_i) / (N * sum x_i^2 - (sum x_i)^2
   
   b = (sumy_i - m * sumx_i) / N

   where (N) is the number of data points.
8. Computes chi-squared:
   
   chis = sum_i ( m * x_i + b - y_i )^2.
   
9. Prints `m`, `b`, and `chis` to `STDOUT`.
10. Writes the sorted data and fitted line values to the output file in **three columns**:

    ```text
    x_i   y_i   y_fit(x_i)
    ```

## How to compile and run

```bash
g++ -o sean_sinchi_hw_12 sean_sinchi_hw_12.cpp
./sean_sinchi_hw_12
