int findDuplicate(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != i+1){
            if(nums[nums[i]-1] == nums[i])
                return nums[i];
            int temp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = temp;
            i--;
        }
    }
    return 0;
}
//感觉似曾相识的样子，反正是从1-n,那么正确的数字放在正确的位置上，如果往上放的时候发现坑被占了，肯定就重复了
//这种写法真的折磨人……nums[nums[i]]这种东西，越少越好！这就是两层索引吗，扛不住了哇！
//去看看官方双指针怎么写，我觉得可以练练手写个快排，排序完了再找不是方便的一批……