int clumsy(int N){
    int sum = 0;    //最终的输出
    int temp_sum = 0;   //每个局部和，先乘除再加的那一部分和
    int flag = 0;       //记录在局部和中的第几个数，前三个运算就好，第四个要额外处理
    int eflag = 0;      //看是否是第一组数，第一组数是加，其它组都是减
    while(N > 0){
        switch(flag){
            case 0:
                temp_sum = N--;
                flag++;
                break;
            case 1:
                temp_sum *= N--;
                flag++;
                break;
            case 2:
                temp_sum /= N--;
                flag++;
                break;
            case 3:     //一组中最后一个数的时候，把* / 的三个数减掉，加上最后一个数，然后把标志位清零
                sum += eflag==0?temp_sum:(-temp_sum);
                sum += N--;
                eflag = 1;
                flag = 0;
                temp_sum = 0;
        }
    }
    if(temp_sum > 0){   //处理非4的倍数的情况
        sum += eflag==0?temp_sum:(-temp_sum);
    }
    return sum;
}
//颇费一番波折……看这挺长的代码就明白了
//额，好像哪里出了岔子，是vscode变大了吗？怎么感觉看着有点不太适应23333
//回到原题，代码感觉也不算很罗嗦吧，答题感觉还可以~除了switch case 用的特别少很陌生以外，都还行