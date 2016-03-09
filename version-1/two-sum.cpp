/********
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.(只考虑有一个答案时的情况)
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include "stdio.h"
int *twoSum(int *nums,int numSize,int target);
int main(){
    int nums[4]={2,7,11,15};
    int *p;
    p=twoSum(nums,4,17);
    printf("[%d,%d]\n",p[0],p[1]);
	return 1;
}
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
     int *result;
     for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
          if((nums[i]+nums[j])==target){
            result[0]=i;
            result[1]=j;
            return result;
            break;
          }
        }
     }
}
