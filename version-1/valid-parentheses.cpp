/****
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**/

bool isValid(char* s) {
    //先判断字符串长度，若为奇数，肯定不是匹配的
    
    int length=strlen(s),i=0,size=0;
    char p[length];//这样定义竟然可以在leetcode上AC，why？
    //p=(char *)malloc(sizeof(char)*length);
    //if(length%2!=0||length==0){
    //	return false;
    //}
    //else{
    	while(i<length){
    	if(s[i]=='('||s[i]=='['||s[i]=='{'){
    		p[size++]=s[i++];
    	}
    	else{
    	  switch (s[i]){
    		case ')':{
	                 if(size==0||p[size-1]!='('){return false;}
	                 else{
                         i++;
                         size--;
	                  }
	                  break;
	                 }
            case ']':{
	                 if(size==0||p[size-1]!='['){return false;}
	                 else{
                         i++;
                         size--;
	                  }
	                  break;
	                 }
            case '}':{
	                 if(size==0||p[size-1]!='{'){return false;}
	                 else{
                         i++;
                         size--;
	                  }
	                  break;
	                 }
               }
            }
    	}
    	return size?false:true;
   // }

}