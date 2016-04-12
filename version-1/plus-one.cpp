/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
*/

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
函数功能正确，但是最后的返回值int *有点问题，一直错误，why??
**/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if(digits==NULL){
    	return NULL;
    }
    int size=digitsSize+1;
    bool flag=false;//进位标识
    int res[size];//用于存放结果
    for(int n=0;n<size;n++){
    	res[n]=0;
    }
    int temp=digits[digitsSize-1]+1;
    if(temp>9){
    	res[size-1]=0;
    	flag=true;
    }
    else{
         res[size-1]=temp;
         flag=false;
    }
    int i=digitsSize-2;
    int j=size-2;
    while(i>=0&&j>=0){
    	if(flag){
    		temp=digits[i]+1;
    		if(temp>9){
    			flag=true;
    			res[j]=0;
    		}
    		else{
    			flag=false;
    			res[j]=temp;
    		}
    	}
    	else{
           res[j]=digits[i];
           flag=false;
    	}
        //temp=flag?((int)digits[i]-48+1):

    	i--;
    	j--;
    }
    if(flag){
    	res[0]=1;
    	return res;
    }
    int *p;
    p=res+1;
    return p;
}