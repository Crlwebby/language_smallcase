int searchInsert(int* nums, int numsSize, int target){
    int i = 0, j = numsSize-1;
    int mid;
    while(i <= j){
        mid = (i + j) / 2;
        if(nums[mid] >= target)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return i;
}

//2021.05.18 一大早的，被二分查找给弄自闭了……
//二分查找的变形题？
//以前下面那个必定是返回mid的，因为你是真的在查找一个确切的值，找到的就刚好是mid
//但是这题略微有点不太一样，就是右边的条件是<=，就是你找一个插入位置。这样的情况下必然是能找到一个准确位置的
//而此时，这个准确位置找到时，i和j两者就很重要了。
//算了算了，经典胡言乱语，反正就是比普通的二分要略有变型，多思考一下还是能明白几个条件为什么这么设置的，就是不如原本的清晰罢了。