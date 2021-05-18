int mySqrt(int x){
   int l = 0, r = x;
   int mid;
   while(l <= r){
       mid = l + (r - l) / 2;
       if((long long)mid * mid <= x){
           l = mid + 1;
       }
       else{
           r = mid - 1;
       }
   }
   return r;
}

//今天第二次遇见了，狗日的二分查找找范围
//二分好像有点难……我裂开了，两次都是位置模糊不定，人有点麻