int findRepeatNumber(int* nums, int numsSize){
    for(int i = 0;i<numsSize;i++){
        int temp = 0;
        //是这样的，如果长度为n,数字大小也在0~n-1范围之内，那么如果没有数字重复进行排序的话，nums[i]应该是等于i的
        if(i == nums[i])
            continue;
        //此刻情况发生了，nums[i] != i ，如果同样的，nums[i]的值所在的位置也与应该存在的数字不符，就把nums[i]的数据换到它该有的地方去，也就是nums[nums[i]]
        //判断情况，如果nums[nums[i]]也不等于nums[i]，相当于鸠占鹊巢，于是与那里进行交换，把nums[i]的数字回归原位；
        if(nums[i] != nums[nums[i]]){
            temp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = temp;
        }
        else{//但是有可能发现那个地方的数字已经正确了，说明有重复数字了，于是直接返回当前的重复数字即可
            return nums[i];
        }
    }
    return NULL;
}

//仅leetcode上看运行结果区别不大，但是分析来看这个原地置换的方法时间复杂度为O(n),空间复杂度为O(1)
//还是比我桶排好哈哈哈哈哈
//原地置换思路很巧，当然看个乐呵就行了