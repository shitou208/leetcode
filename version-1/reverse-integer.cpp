/*Reverse digits of an integer.
   Example1: x = 123, return 321
   Example2: x = -123, return -321
*/
#include "stdio.h"
int reverse(int x);
int main(){
	int x=123456;
	printf("result is: %d",reverse(x));
	return 1;
}
int reverse(int x){
	bool neg=false;
	if(x<0){
		x=-x;
		neg=true;
	}
	int sum=0;
	while(x){
		sum*=10;
		sum+=x%10;
		x=x/10;
	}
	if(x<2147483648&&x>-2147483648)//添加是否overflow的判断，当越界时返回值设为0 
	  {
	  return neg?(-sum):sum;
	  }
	else{
		return 0;
	}
}

