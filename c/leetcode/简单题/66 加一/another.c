/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i = digitsSize - 1; i >= 0; i--){
        digits[i] = 1 + digits[i];
        if(digits[i] >= 10){
            digits[i] = digits[i] % 10;
        }
        else{
            *returnSize=digitsSize;
            return digits;
        }
    }
    int *result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    result[0] = 1;
    for(int i = 0; i < digitsSize; i++)
        result[1+i]=digits[i];
    *returnSize = digitsSize+1;
    return result;
}
//参考了下大佬的答案，发现保持进位根本没必要，反正进位也只有1，如果有进位，下次循环加上就OK了，自己条件搞来搞去反而过于复杂了