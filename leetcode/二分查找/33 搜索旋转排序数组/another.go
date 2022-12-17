func search(nums []int, target int) int {
	length := len(nums)
	i, j := 0, length-1
	mid := 0
	for i <= j {
		mid = (i + j) / 2
		if nums[mid] == target {
			return mid
		}
		if nums[mid] >= nums[i] {
			//判断i-mid这段数据是否是升序的；之所以加等号，是有可能i=mid，也就是旋转点为nums[1]的情况下，此时左边只有一个元素，右边都是升序；
			if target <= nums[mid] && target >= nums[i] {
				j = mid - 1
			} else {
				i = mid + 1
			}
		} else {
			if target >= nums[mid] && target <= nums[j] {
				i = mid + 1
			} else {
				j = mid - 1
			}
		}
	}
	return -1
}

//参照过题解的思路，但是为什么还没顺序查找速度快……就离谱
//怎么说呢，除了只有两个元素的样例旋转一下成为降序，把我震撼了以外，其它的都是按着预想的思路来的；
//因为有旋转点的存在，划mid一刀，旋转点要么在左边要么在右边（中间也没关系）
//然后肯定一边有序一边无序，那就四个if都判断一下，如果左边有序且target在内，否则遍历右边；如果左边无序且target在内，否则右边；
//就四种情况i、j的变化不一样，难不算难吧，思路不容易想到。