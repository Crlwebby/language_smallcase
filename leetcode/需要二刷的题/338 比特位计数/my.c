/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int *result = malloc(sizeof(int) * (num + 1));
    for(int i = 0; i <= num; i++){
        int temp = i;
        result[i] = 0;
        while(temp){
            result[i] += temp % 2;
            temp = temp / 2;
        }
    }
    *returnSize = num + 1;
    return result;
}

//最暴力的解法……不考虑啥动态不动态的，每个数求就完事儿了！
//坦白讲，是我没能想出来怎么把之前计算过的东西利用一下……数学太烂，对二进制不够敏感呐