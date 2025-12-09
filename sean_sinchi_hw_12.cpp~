// Name: Sean Sinchi
// Purpose: Gain experience with c++ arrays and file I/O
// Date: 12/2/25
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
  std::ofstream output_file;// output file stream
  std::ifstream in_file;    // input file stream
  std::string fileNameIn;   // String for input file declared
  std::string fileNameOut;  // String for output file declared
  int num_pnts{};           // Number of points
  int j, k;                 // Loop indices for bubble sort
  double *x_array{nullptr}, *y_array{nullptr}; // Dynamic array pointers
  double x, y;              // Data point variables
  double tempvx, tempvy;    // Temp variables for swapping in bubble sort
  double m, b;              // Variables to hold slope & intercept respectively
  double chis{};            // Variable to hold Chi-squared value
  double sumx{0}, sumy{0}, sumxx{0}, sumxy{0}; // Variables to hold sums to 
                                               // calculate m, b, & chis
  
  std::cout << "Enter name of file to be read in:" << std::endl; // Prompt user
  std::cin >> fileNameIn;   // Read in name of input file from user
  
  std::cout << "Name of input file is: " << fileNameIn << std::endl
	    <<"Enter name of file to output data:";
  std::cout.flush();
  std::cin >> fileNameOut;  // Read in name of output file from user

  in_file.open(fileNameIn); // Open input file for reading

  while(in_file.good())     // Count # of data points (stop on read failure)
    {
      in_file >> x >> y;    // Read x & y from each line of file
      if(in_file.fail())    // If read failure, exit loop
	{
	  break;
	}
      num_pnts++;           // Increment data counter
    }

  in_file.clear();                // Clear file stream error
  in_file.seekg(0,std::ios::beg); // Move read position back to beginning 

  x_array = new double[num_pnts]; // Allocate space for array of size num_pnts
  y_array = new double[num_pnts]; // Allocate space for array of size num_pnts

  for(int i=0; i < num_pnts; i++) // Read data from file to arrays
    {
      in_file >> x_array[i] >> y_array[i];
    }

  in_file.close();                // Close file
  in_file.clear();                // Clear any file stream error 
  
  // Bubble sort---------------------------------------------------------------
  for(k=1; k < num_pnts; k++)       // Repeat bubble pass n-1 times
    {
      for(j=0; j < num_pnts-1; j++) // Loop over elements
	{
	  if(x_array[j] > x_array[j+1] )   // If ith element > i+1th in x_array
	    {
	      tempvx       = x_array[j+1]; // then swap the elements
	      x_array[j+1] = x_array[j];
	      x_array[j]   = tempvx;
	    
	      tempvy       = y_array[j+1]; // Also swap y components to keep
	      y_array[j+1] = y_array[j];   // pairs together
	      y_array[j]   = tempvy;
	    }
	}                                 // End of inner loop over j
    }                                     // End of outer loop over k

  // Slope and intercept calculation-------------------------------------------
  for(int i=0; i < num_pnts; i++)   // Loop to calculate sums for least-squares 
    {                               // technique and linear regression formulas
      sumx  = sumx  + x_array[i];             // Sum of all x components
      sumy  = sumy  + y_array[i];             // Sum of all y components
      sumxx = sumxx + pow(x_array[i],2);      // Sum of all x^2
      sumxy = sumxy + x_array[i]*y_array[i];  // Sum of all products of x*y
    }
  
  const double N = static_cast<double>(num_pnts);// Declare variable N and
                                                 // convert num_pnts to double
                                                  
  m = (N * sumxy - sumx * sumy) / (N * sumxx - pow(sumx,2)); // Calculate m
  b = (sumy - m * sumx) / N;                                 // calculate b

  // Chi-squared calculation---------------------------------------------------
  for(int i=0; i < num_pnts; i++)         // loop to calculate chi-squared
    {
      double yfit = m * x_array[i] + b;   // Calculate linear regression at xi
      double diff = yfit - y_array[i];    // Subtract yi from linear regression
      chis = chis + pow(diff, 2);         // Calculate chi-squared by summing
    }                                     // all the differences of yfit and  
                                          // yi squared
  // Write out stats to STDOUT
  std::cout << " Slope: " << m << std::endl
	    << " Intercept: " << b << std::endl
            << " Chi-squared: " << chis << std::endl;

  output_file.open(fileNameOut);          // Open output file to place data
  output_file.setf(std::ios::fixed);      // Turn on fixed point notation
  
  // Place headers in output file 
  output_file << std::setw(10) << "x" << std::setw(10) << "y"
	      << std::setw(10) << "y(x)" << std::endl;
  
  for(j=0; j < num_pnts; j++)             // Loop over all elements to write
    {                                     // out x, y, and y(x)
      double yfit = m * x_array[j] + b;
      output_file << std::setw(10) << x_array[j] 
		  << std::setw(10) << y_array[j]  
	          << std::setw(10) << yfit << std::endl;
    }

  output_file.close();                    // Close output file
  output_file.clear();                    // Clear file stream errors

  delete [] x_array;                      // Delete memory for x array
  x_array = nullptr;                      // Nullify x array pointer
  delete [] y_array;                      // Delete memory for y array
  y_array = nullptr;                      // Nullify y array pointer

  return 0;                               // Return a zero error code
}
