int maxArea(int* height, int heightSize){
    int max = 0;
    int left=0,right=heightSize-1;
    int i = 1;
    while(left < right){
        int temp;
        if(height[left] >= i && height[right] >= i){
            i++;
            continue;
        }
        else{
            temp = (right - left) * (height[left] > height[right] ? height[right] : height[left]);
            if(height[left] > height[right])
                right--;
            else{
                left++;
            }
        }
        max = temp > max ? temp : max;
    }
    return max;
}
//出息了呀，中等题一遍过hhhhhh，很高兴
//应该是上次接雨水看题解的影响吧，隐隐约约记得一些比较好的思路，然后想到了适合这道题的，就解决咯
//官方题解一样的思路啊，双指针，果然看过类似题目的就是不一样，居然和官方答案对上了~