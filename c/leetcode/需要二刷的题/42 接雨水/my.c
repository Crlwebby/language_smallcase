int trap(int* height, int heightSize){
    int sum = 0;
    for(int i = 0; i < heightSize; i++){
        int j = i + 1;
        for(int j = i + 1; j < heightSize; j++){
            if(height[j] >= height[i]){
                for(int t = i + 1; t < j; t++){
                    sum += height[i] - height[t];
                }
                i = j - 1;
                break;
            }
        }
        for(int j = i + 1; j < heightSize; j++){
            if(height[j] > height[j - 1]){
                if(j + 1 < heightSize && height[j + 1] > height[j])
                    continue;
                else{
                    while(i < heightSize - 1 && height[i + 1] < height[i] && height[i + 1] > height[j])
                        i++;
                    int min = height[i] > height[j] ? height[j] : height[i];
                    for(int t = i + 1; t < j; t++){
                        sum += min - height[t];
                    }
                    i = j - 1;
                    break;
                }
            }
        }
        printf("%d\n",sum);
    }
    return sum;
}

//看这密密麻麻的条件判断，你就知道什么叫绝望了……
//而且！我还没做出来呢……不愧是老题目啊，42，难题，三百多的测试用例，真刺激
//肯定有更好的思路去解啊！不然每次做个算法面向样例编程，写这么复杂的条件写一堆，还要不要开发了！