#include <stdio.h>
/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
main()
{
 float fahr, celsius;
 float lower, upper, step;
 lower = -20;      /* lower limit of temperatuire scale */
 upper = 150;    /* upper limit */
 step = 10;      /* step size */
 celsius = lower;
 printf("%6s %3s\n", "celsius", "fahr");
 while (celsius <= upper) {
	 fahr = celsius * (9.0 / 5.0) + 32.0;
	 printf("%6.0f %3.1f\n", celsius, fahr);
	 celsius += step;
 }
}