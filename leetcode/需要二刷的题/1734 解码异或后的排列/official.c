int* decode(int* encoded, int encodedSize, int* returnSize){
    *returnSize = encodedSize + 1;
    int total = 0,another = 0;
    for(int i = 1; i <= encodedSize+1; i++){
        total ^= i;
    }
    for(int i = 1; i < encodedSize; i += 2)
        another ^= encoded[i];
    int *result = (int *)malloc(sizeof(int) * (encodedSize + 1));
    result[0] = total ^ another;
    for(int i = 1; i < encodedSize + 1; i++){
        result[i] = encoded[i - 1] ^ result[i - 1];
    }
    return result;
}
//这题我是真不会……看了题解才模模糊糊明白在干啥的
//异或yyds，题目条件，原序列是1-n的一个排列，然后就把所有的数字异或一下
//后面编码过的序列是原序列每两两异或得到的，那么一定可以获得原序列除第一个数字外的异或集合
//两者异或获得原序列第一个数字，剩下的就简单了