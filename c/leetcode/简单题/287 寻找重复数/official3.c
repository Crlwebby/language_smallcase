//原来快慢指针这么用的啊……也是，可以直接把数组看成链表，只是要对数组位到数组头的这个过程额外处理一下罢了
//建链表原来是这么个意思……就是把nums[nums[i]]当作i.next，nums[i]是i.value，这样子形成一个链表，秒啊


int findDuplicate(int* nums, int numsSize){
    int i = 0;
    int fast = 0, slow = 0;
    do{
        fast = nums[nums[fast]];
        slow = nums[slow];
    }while(fast != slow);
    int result = 0;
    while(result != slow){
        result = nums[result];
        slow = nums[slow];
    }
    return result;
}

//还是一次同余方程的问题，起码样例全过这个算法应该是正确的，但是却有某些测试样例需要用一次同余方程去证明一下，但我忘光了……
//下次有空好好补一补数论，也有可能是我想复杂了