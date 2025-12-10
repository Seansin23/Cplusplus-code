//Author: Sean Sinchi
//Date 11/17/25
//Purpose: Gain experience with c++ syntax

#include <iostream>
#include <cmath>

int main()
{
  double a{};                   // Variable to hold coefficient a
  double b{};                   // Variable to hold coefficient b
  double c{};                   // Variable to hold coefficient c
  double x1{};                  // Variable to hold root 1
  double x2{};                  // Variable to hold root 2
  double disc{};                // Variable to hold discriminant
  double realPart{};            // Variable to hold real part of complex #
  double imagPart{};            // Variable to hold imaginary part of complex #

  std::cout << " Enter real values for coefficients a, b, & c "  << std::endl;
  std::cin >> a >> b >> c;
  std::cout << " You entered: a = " << a << " b = " << b << " c = " << c <<
    std::endl;
  
  disc = b*b - 4.0*a*c;         // Discriminant in the quadratic formula
  
  if(a == 0.0)
    {                           // Case 1: a = 0
    x1 = -c / b;
    std::cout << " Since a = 0, the equation is linear; one real root exists: "
	      << std::endl;
    std::cout << " x = " << x1 << std::endl;
    }
  
  else if(disc == 0.0)                     // Case 2: one real root
    {
      x1 = -b / (2.0*a);
      std::cout << " There is one single real root:" << std::endl;
      std::cout << " x = " << x1 << std::endl;
    }

  else if(disc > 0.0)                     // Case 3: two distinct real roots
    {
    x1 = ( -b + sqrt ( disc) ) / (2.0*a); // Quadratic formula 
    x2 = ( -b - sqrt ( disc) ) / (2.0*a);
      
    std::cout << " There are two distinct real roots: " << std::endl;
    std::cout << " x_1 = " << x1 << std::endl;
    std::cout << " x_2 = " << x2 << std::endl;
    }
  
  else                                  // Case 4: two distinct complex roots
    {
    realPart = -b / (2.0*a);
    imagPart = sqrt (-disc) / abs (2.0*a);// Neg discriminant since a negative
                                        // number in sqrt function outputs NAN
    std::cout << " There are two distinct complex roots: " << std::endl;
    std::cout << " x_1 = " << realPart << " + " << imagPart << "i" <<
	std::endl;
    std::cout << " x_2 = " << realPart << " - " << imagPart << "i" <<
	std::endl;
    }
   
  return 0;
}
