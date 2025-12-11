/* Purpose: Build a calculator that converts fahrenheit to celcius
   Author: Sean Sinchi
   Date: 11/16/2025*/
#include <iostream>
#include <cmath>
int main(){
  double tempf{};
  double tempc{};
  int x{};

  while(std::cout << " Enter 1 to go from f->c or 2 to go from c->f: ",
	std::cin >> x)
  {
   if(x==1)
    {
    std::cout << "Enter temperature in fahrenheit" << std::endl;
    std::cin >> tempf;
    tempc = (tempf - 32.0)*5.0 / 9.0;
    std::cout << " Temperature in degrees celcius is: " << tempc << std::endl;
    }
  else if(x==2)
    {
      std::cout << "Enter temperature in celcius" << std::endl;
    std::cin >> tempc;
    tempf = (9.0/5.0 * tempc)+32.0;
    std::cout << " Temperature in degrees fahrenheit is: " << tempf << std::endl;
    }
    }
  return 0;

}
