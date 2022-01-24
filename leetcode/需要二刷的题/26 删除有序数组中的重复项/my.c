int removeDuplicates(int* nums, int numsSize){
    for(int i = 0; i < numsSize - 1; i++){
        //外圈循环，找出所有重复的数字
        if(nums[i] == nums[i+1]){
            for(int j = i + 1; j <numsSize - 1; j++){
                //内圈循环，进行数组的移动
                nums[j] = nums[j + 1];
            }
            //数组移动完毕后numsSize变小一位，而i要保持原地不动
            numsSize--;
            i--;
        }
    }
    return numsSize;
}

//哈哈哈哈哈哈，不愧是我，每次有重复的直接整个数组移动，太刺激了。
//原地算法嘛，内存消耗击败96.2%，但执行击败5.23%，又一个时间换空间的鲜活例子
//不行，得去看看双百的怎么搞的
//话说中文力扣社区确实8行，我记得英文力扣社区里基本每个题都有双百的题解来着，而且用起来还好用很多