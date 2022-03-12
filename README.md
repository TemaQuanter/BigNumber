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
	// Option 1: If you want to use really tremendous numbers, you should initialize BigNumber the following way

	BigNumber num1 = "2873645892367482126347821638412012934127894872164981293871276472563467158189327459827045902543";
	BigNumber num2 = "-23947528737782";
  	
	// Option 2: Otherwise, it is possible to use another aproach
	
	BigNumber num3 = 3285333232948;
	BigNumber num4 = -23452;

	std::cout << num1 + num2 << std::endl;
	std::cout << sqrt(num1) << std::endl;
	std::cout << num2 % num1 << std::endl;
	std::cout << max(num2, num4) << std::endl;
	std::cout << num1 / num3 << std::endl;
}
 ```
 
 Output:
 ```
2873645892367482126347821638412012934127894872164981293871276472563467158189327435879517164761
53606397867861650664229279807513224483331158450
-23947528737782
-23452
874689320263837592575054681896226317321795600229060436708274583503200278414951849

 ```
