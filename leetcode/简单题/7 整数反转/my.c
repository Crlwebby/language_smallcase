int reverse(int x){
    long result = 0;
    while(x != 0){
        result = result * 10 + x % 10;
        if(result > INT_MAX || result < INT_MIN){
            return 0;
        }
        x = x / 10;
    }
    return (int)result;
}

//确实是道简单题，简单的有点点离谱……
//不过用long似乎是偷懒了，因为总有数据会超过long long，这种情况你又要怎么办呢？请看官方题解