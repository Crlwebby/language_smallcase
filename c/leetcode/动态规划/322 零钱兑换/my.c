int coinChange(int* coins, int coinsSize, int amount){
    int num[amount+1];  //amount是钱，为了让钱和数组下标一一对应，空出钱为0的情况
    num[0] = 0;
    for(int i = 1; i <= amount; i++)    //默认-1，即无法兑换
        num[i] = -1;
    for(int i = 0; i < coinsSize; i++){ //已有的硬币面额可以1兑1
        if(coins[i] > amount){  //如果硬币面额比需要的钱还大，肯定是不需要用的
            continue;
        }
        else
            num[coins[i]] = 1;
    }
    for(int i = 2; i <= amount; i++){   //1块钱的情况，如果有1块硬币，那上面就已经赋值了；如果没有1块硬币，那就是-1，也不需要遍历
        int min = INT_MAX;              //初始化min为INT_MAX 避免真的比需要的还小
        for(int j = 0; j < coinsSize; j++){ //遍历只需要遍历这样几种情况，因为已有的硬币就那么几种，多的也还是从前的组合（未证明）
            if(i >= coins[j] && num[i-coins[j]] != -1)   //确保i-coins[j]还大于0，别越界；还要保证i-coins[j]是一个能被表示的金额
                min = min < (1 + num[i-coins[j]]) ? min : (1 + num[i-coins[j]]);    //数量最小，肯定是用的硬币面额越大越好，就是这里的1+num[i-coins[j]]
        }
        if(min != INT_MAX){//如果i能被表示，就把表示的数量赋回去
            num[i] = min;
        }    
    }
    return num[amount];
}
//董立豪永远滴神！
//我这榆木脑袋，咋就没想到第15行用硬币金额去进行遍历呢？这不是快得多嘛！
//除此之外，思路还算好想？毕竟和钢条切割太像太像了