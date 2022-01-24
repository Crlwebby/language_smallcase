func merge(nums1 []int, m int, nums2 []int, n int) {
	for i := 0; i < n; i++ {
		nums1[m+i] = nums2[i]
	}
	sort.Ints(nums1)
}

//虽然有点小波折，但是果然用sort函数还是最快乐的~ 不用手写排序的感觉真棒！