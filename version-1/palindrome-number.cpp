/*
Determine whether an integer is a palindrome. Do this without extra space.
����ע��㣺�����ǻ������������֮ǰreverse-integer��������һ���⣬ֻҪ��
�����ȷ�ת��Ȼ����ԭ�������бȽϣ����������ǻ������� 
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
	//��֮ǰ��reverse-integer���һ�ޣ�ʱ�临�ӶȽ��ˣ����ռ临�ӶȲ�����Ҫ�� 
	//���̽������ռ临�Ӷȵ��㷨���� 
	//����һ����������ǽ�������ת����ܷ��������������Ӧ�ö������������� 
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
 
