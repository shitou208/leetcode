/**
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
**/
void rotate(int* nums, int numsSize, int k) {
	if(k<=0||k>numsSize){
     k=k%numsSize;
	}
    int right[numsSize-k];
    int i;
    for(i=0;i<numsSize-k;i++){
    	right[i]=nums[i];
    }
    for(i=0;i<k;i++){
    	nums[i]=nums[numsSize-k+i];
    }
    for(i=k;i<numsSize;i++){
    	nums[i]=right[i-k];
    }
}