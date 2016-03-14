/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
For example, 
Given s = "Hello World",
return 5.
*/

#include "stdio.h"
#include "string.h"
int lengthOfLastWord(char* s);
int maxLengthOfWord(char* s);
int main(){
	char* str="Today is a nice daydayt";
	printf("last is : %d\n",lengthOfLastWord(str));
	printf("max is : %d\n",maxLengthOfWord(str));
	return 1;
}
int lengthOfLastWord(char* s) {
    int i=0,last_size=0,temp_size=0;
    while(s[i]!='\0'){
      	if(s[i]!=' '){ temp_size++;}
        if(s[i]==' ') {
		if(temp_size){
		last_size=temp_size;//如果一个单词后面全是空格，那就忽略 
		} 
		temp_size=0;
		}	
		i++;	
	} 
	
	return temp_size?temp_size:last_size;
}
//根据这个思路，这题可以改造成求一个字符串中最大的单词的长度，如下：
int maxLengthOfWord(char* s){
	int i=0,max_size=0,temp_size=0;
	while(s[i]!='\0'){ 
	 if(s[i]!=' '){
	 	temp_size++;
	 } 
	 if(s[i]==' '){
	  if(max_size<temp_size){
	  max_size=temp_size;
	  }
	  temp_size=0;	
	  }
	  i++;
	} 
	return max_size>temp_size?max_size:temp_size;
}

