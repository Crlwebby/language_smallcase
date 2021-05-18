int mySqrt(int x){
   int l = 0, r = x, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    return ans;
}

//这是官方的题解，和我自己的差别就是用了个额外变量ans来保存mid状态
//我直接用mid返回不行是因为，例子的8这种情况，l=2,r=3时，mid是2没错，然后l++变成3，下次还能再走一趟循环，l变成3，mid也变成3了
//这样子就不正确了。官方题解的这种，用ans保存了一下上一次mid的状态，可以保存最大的小于目标值的下标。
//我后来改的用右边返回，玄学过了……我也不知道为啥，可能刚遇到第一个大于的值，然后减一后刚好满足吧