//有高级算法，但是我懒得考虑了……好像qsort()支持类似模板一样的东西，懒得学了……
//先记录一个自己的快排实现，再去学一下什么叫计数排序

void quicksort(int *nums, int begin, int end){
    if(begin >= end)
        return;
    int index = nums[begin];
    int i=begin,j=end - 1;
    while(i < j){
        while(i<j && nums[j] >= index){
            j--;
        }
        if(i < j)
            nums[i++] = nums[j];
        while(i < j && nums[i] < index){
            i++;
        }
        if(i < j)
            nums[j--] = nums[i];
    }
    nums[i] = index;
    quicksort(nums, begin, i);
    quicksort(nums, i+1, end);
}

