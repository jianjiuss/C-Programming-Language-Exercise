//练习1-15 重新编写1.2节中的温度转换程序,使用函数实现温度转换计算。
#include <stdio.h>

float convertToCelsius(float fahr);

main()
{
 float fahr, celsius;
 float lower, upper, step;
 lower = 0;      /* lower limit of temperatuire scale */
 upper = 300;    /* upper limit */
 step = 20;      /* step size */
 fahr = lower;
 printf("%3s %6s\n", "fahr", "celsius");
 while (fahr <= upper) {
	 celsius = convertToCelsius(fahr);
	 printf("%3.0f %6.1f\n", fahr, celsius);
	 fahr = fahr + step;
 }
}

float convertToCelsius(float fahr){
	return (5.0/9.0) * (fahr-32.0);
}