/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

void merge(int *nums1, int m, int *nums2, int n)
{
    /*基本思想：将nums2中的每个元素依次在Nums1中找到合适位置插入*/
    int i, j, last = m - 1;
    for(i = 0; i < n; i++)
    {
        j = last + i;//插入新元素后，最末尾标志也要后移
        while(j >= 0 && nums2[i] < nums1[j])
        {
            nums1[j + 1] = nums1[j];//从后往前找，在比较的过程中就进行后移操作，把较大的元素移动到后面
            j--;
        }
        nums1[j + 1] = nums2[i];
    }
}