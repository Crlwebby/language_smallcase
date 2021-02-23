int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X){
	int n= customersSize;
	int m= grumpySize;
	int dp1[20001],dp2[20001],i,j;
	dp2[0]=customers[0];
	dp1[0]=grumpy[0]==0?customers[0]:0;
	for(i=1;i<n;i++){
		dp1[i]=grumpy[i]?dp1[i-1]:dp1[i-1]+customers[i];
	}
	for(i=1;i<n;i++){
		dp2[i]=dp2[i-1]+customers[i];
	}
	int sum=0,max=0,z=0;
	for(i=0;i<n;i++){
		sum=0;
		if(grumpy[i]){
			if(X+i-1>=n)z=n-1;
			else z=i+X-1;
			if(i>=1)
			sum=dp2[z]-dp2[i-1]-(dp1[z]-dp1[i-1]);
			else
			sum=dp2[z]-dp1[z];			
		}
		if(sum>max)max=sum;
	}
	return max+dp1[n-1];
}

作者：hei-shan-mie
链接：https://leetcode-cn.com/problems/grumpy-bookstore-owner/solution/yong-dpjie-jue-gai-wen-ti-pao-liao-40ms-kx6x8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//据说是用DP写的，40ms，我写的1000ms，真就这么恐怖的效率吗……有空学习一下