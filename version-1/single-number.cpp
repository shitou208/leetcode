//算法复杂度不满足leetcode的要求，待改进
int singleNumber(int* nums, int numsSize) {
    int result,i,j;
    bool flag=true;
    for(i=0;i<numsSize;i++){
       flag=true;
       for(j=i+1;j<numsSize;j++){
	   if(nums[i]==nums[j]){
	   	flag=false;
	   	continue;
	   }
	   }
	   if(flag){
	   	result=nums[i];
	   	break;
	   }
	}
	return result;
}