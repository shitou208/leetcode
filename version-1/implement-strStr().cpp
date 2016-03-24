/**
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int strStr(char* haystack, char* needle) {
     int len1=strlen(haystack);
     int len2=strlen(needle);
     int j,count=0;
     bool isstr=false;
     if(len1<len2){
     	return -1;
     }
     else{
     for(int i=0;i<=len1-len2;i++)    {
            j=0;
            count=0;
            while(j<len2){
              if(needle[j]==haystack[i+j]){
              	j++;
              	count++;
              }
              else{
               break;
              }
            }
        if(count==len2){
        	isstr=true;
        	return i;
        	break;
        }
     }
     if(!isstr){return -1;}
     }
}