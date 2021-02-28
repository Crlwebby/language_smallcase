bool isMonotonic(int* A, int ASize){
    if(ASize <= 1)
        return true;
    int flag = -1;
    for(int i = 1; i < ASize; i++){
        if (A[i - 1] < A[i]){
            if (flag == -1){
                flag = 0;
            }
            else if(flag == 1)
                return false;
        }
        else if(A[i - 1] > A[i]){
            if (flag == -1)
                flag = 1;
            else if(flag == 0)
                return false;
        }
        else{

        }
    }
    return true;
}

//看了下官方题解，发现只用一个flag好像蛮蠢的……就会像我这样异常麻烦，简单思路直接一个inc(increase)，一个dec(decrease)