// Name: Sean Sinchi
// Purpose: Gain experience with C++ loops
// Date: 11/30/25
/*
  Found 5 roots for function f(x) = x + 3sin(2x)
  Approximate root values: 
  2.61298, 1.9175, 0, -1.9175, -2.61298
  Initial guesses: 3.141, 3.0,1.7,2.0,1.0,1.5,0,-3.141,-1.9175
*/

#include <iostream>
#include <cmath>

double f(double x)               // Define function f(x)
{
  return x + 3.0 * sin(2.0*x);
}
double fprime(double x)         // Define function f'(x)
{
  return 1.0 + 6.0 * cos(2.0*x);
}

void newton_raphson()
{
  double xold{};                  // Old estimate of root
  double xnew{};                  // New estimate of root
  double epsilon{1.0e-8};         // Convergence of criterion
  bool converged = false;         // Convergence flag
  int niter{};                    // Number of iteration
  const int NITER_MAX{500};       // Max # iterations allowed

  std::cout << "Enter initial guess at root" << std::endl;//Prompt user 
  std::cin >> xold;               // Read in guess of root

  while(niter < NITER_MAX)        // Initiate loop
    {                             // Determine if method will overflow
      if(fabs(fprime(xold)) < 1.0) 
	{
	  if(fabs(f(xold)) > fabs(fprime(xold)))
	    {
	      std::cout << "Derivative is small and will overflow" <<
		std::endl;
	      return;
	    }
	}

      xnew = xold - f(xold) / fprime(xold); // Calculate new estimate

      if(xold != 0.0)                       // Check for convergence
	{
	  converged = fabs(xnew-xold) < epsilon*fabs(xold);
	}
      else
	{
	  converged = fabs(xnew-xold) < epsilon;
	}
      if (converged)
	{
	  std::cout << "Root is " << xnew << std::endl;
	  return;
	}
	
	xold = xnew;                     // Update old guess to new guess
	niter++;                         // Update iteration counter
    } 

  std::cout << "Method failed: Too many iterations!" << std::endl;
}

int main()
{
  newton_raphson();
  return 0;
}
