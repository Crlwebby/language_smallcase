func sortColors(nums []int) {
	len := len(nums)
	i, j := 0, len-1
	quicksort(nums, i, j)
}

func quicksort(nums []int, start int, end int) {
	if start >= end {
		return
	}
	index := nums[start]
	i := start
	j := end
	for i < j {
		for i < j && nums[j] >= index {
			j--
		}
		if i < j {
			nums[i] = nums[j]
			//这里之所以这样搞，是因为刚开始的分界点用的是nums[start]标记的
			//如果交换nums[i],nums[j]的话，第一个数据会重复，或者说反复赋值比较复杂？
			//好像直接交换，最后一步没有赋值也不是不行……
			i++
		}
		for i < j && nums[i] < index {
			i++
		}
		if i < j {
			nums[j] = nums[i]
			j--
		}

	}
	nums[i] = index
	quicksort(nums, start, i-1)
	quicksort(nums, i+1, end)
}

//不知道这题目什么意思……感觉就是个很垃圾的排序……莫名其妙
//噢，自己快排又不会写了，写了几遍了已经，还是记不住，可恶啊……
//快排的思想就是分治的思想。先整体的分开，左边相对较小，右边相对较大
//然后每一小部分再继续上面那个顺序。然后怎么搞小部分的排序呢？
//答案是递归，然后搞个start和end的标记，用于标记每一部分的内容。在一部分的内容里，从开始遍历到结尾，然后比较每一个关键字和选定的key大小关系
//这里的这个遍历挺巧妙的。先选取了第一个元素，然后从后往前遍历，把不符合条件的往前覆盖掉，再从前往后遍历。
//其它的写法应该也可以

//为什么快排最差是O(n^2)？如果数据是有序的，无论是升序的还是降序的，关键字一般选两边的（方便放到合适的位置），然后分治法就只能变成治一边
//原本是以除2的进度往下降低遍历的数量，结果变成线性的，最后还是n^2