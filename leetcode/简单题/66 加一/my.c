/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int remain = 0;
    for(int i = digitsSize - 1; i >= 0; i--){
        if(i == digitsSize - 1)
            digits[i] = 1 + remain + digits[i];
        else
            digits[i] = remain + digits[i];
        remain = 0;
        if(digits[i] >= 10){
            remain = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        else
            break;
    }
    if(remain != 0){
        int *result = (int *)malloc(sizeof(int) * (digitsSize + 1));
        result[0] = 1;
        for(int i = 0; i < digitsSize; i++)
            result[1+i]=digits[i];
        *returnSize = digitsSize+1;
        return result;
    }
    *returnSize=digitsSize;
    return digits;
}
//朴实无华的题目……虽然条件判断还写的蛮多的