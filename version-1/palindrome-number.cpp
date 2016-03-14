/*
Determine whether an integer is a palindrome. Do this without extra space.
几个注意点：负数是回文数、这题跟之前reverse-integer基本算是一个题，只要将
整数先翻转，然后与原整数进行比较，如果相等则是回文数。 
*/

#include "stdio.h"
bool isPalindrome(int x);
int main(){
	int num;
	printf("input a test number: ");
	scanf("%d",&num);
	if(isPalindrome(num)){
	printf("yes\n");
	}
	else{
		printf("no\n");
	}
	return 1;
}

bool isPalindrome(int x) {
	//跟之前的reverse-integer如出一辙，时间复杂度降了，但空间复杂度不满足要求 
	//如何探索满足空间复杂度的算法？？ 
	//还有一种情况，就是将整数反转后可能发生溢出，代码中应该对溢出情况做处理 
    int origin_x=x;
    int sum=0;
    if(x<0){
    	return false;
	} 
	else{
    while(x){
    	sum*=10;
    	sum+=(x%10);
    	x/=10;
	}
	if(origin_x==sum) {return true;}
    else {return false;}
    	}
}
 
