func merge(nums1 []int, m int, nums2 []int, n int) {
	result := make([]int, 0, m+n)
	i := 0
	j := 0
	for i < m || j < n {
		if j == n {
			result = append(result, nums1[i:]...)
			/*for i < m{
			    result[i+j]=nums1[i]
			    i++
			}*/
			break
		}
		if i == m {
			/*for j < n{
			    result[i+j]=nums2[j]
			    j++
			}*/
			result = append(result, nums2[j:]...)
			break
		}
		if nums1[i] < nums2[j] {
			//result[i+j]=nums1[i]
			result = append(result, nums1[i])
			i++
		} else {
			//result[i+j]=nums2[j]
			result = append(result, nums2[j])
			j++
		}
	}
	//nums1 = result
	copy(nums1, result)
}

//看不懂为什么make第二个参数是0，切片为空？也不是赋初值啊……
//看不懂中间那一坨，为什么用append可以，用i+j就不行，又没越界=。=
//切片的长度是很有限的，make([]int,0,m+n)意味着切片的最大容量可以到达m+n，但是目前的容量只是0，所以i+j会越界，要append扩容
//就离谱 辣鸡Go……还我简单干净C语言…………不是 为什么GO非要把类型名的定义写在变量名后面啊？这不是很反人类吗？？？太离谱了