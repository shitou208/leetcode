/*Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/

#include "stdio.h"
int addDigits(int num);
int main(){
	int n=38;
	printf("result is: %d",addDigits(n));
	return 1;
}
int addDigits(int num){
	if(num<10&&num>-1){
		return num;
	}
	else{
	int sum=0;
	while(num){
	sum+=num%10;
	num/=10;
	}
	//使用递归方式 
	return addDigits(sum);
	}
}
