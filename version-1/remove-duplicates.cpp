/******
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
***/
//关键点，sorted array
//不仅要返回最后得到的length，还要将原数组进行去冗余(前提是不借助于额外定义的数组)
int removeDuplicates(int* nums, int numsSize) {
    int i,length=1;
    if(numsSize==1||numsSize==0){ //考虑链表元素为0或1的情况   
      return numsSize?1:0;
    } 
    else{
    for(i=0;i<numsSize-1;i++){
        if(nums[i]!=nums[i+1]){
        	length++;
        	nums[length-1]=nums[i+1];
            }
        else{
        nums[length-1]=nums[i+1];
        }
        }
     return length;
    }
}