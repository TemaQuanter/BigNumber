# BigNumber
Get UNLIMITED integer numbers in c++!!!

**How to use it is 3 SUPER SIMPLE STEPS?!**


1. Unzip file and place it in the folder with your project (or just clone it to your project)
2. Open your _filename.cpp_ file and add the line <code>#include "BigNumber/BigNumber.hpp"</code>
3. Use it as you would use <code>int</code>:)

***Example***

_filename.cpp_

```
#include <iostream>
#include "BigNumber/BigNumber.hpp"

int main()
{
	BigNumber num1 = 10;
	BigNumber num2 = 34;
  
	std::cout << num1 + num2 << std::endl;
	std::cout << sqrt(num2) << std::endl;
	std::cout << num2 % num1 << std::endl;
}
 ```
 
 Output:
 ```
 44
 5
 4
 ```
