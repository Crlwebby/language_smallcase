import "sort"

func threeSum(nums []int) [][]int {
	len := len(nums)
	var res [][]int
	if len < 3 {
		return nil
	}
	sort.Ints(nums)
	for i := 0; i < len; i++ {
		if nums[i] > 0 {
			break
		}
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		L := i + 1
		R := len - 1
		for L < R {
			sum := nums[i] + nums[L] + nums[R]
			if sum == 0 {
				res = append(res, []int{nums[i], nums[L], nums[R]})
				for L < R && nums[R] == nums[R-1] {
					R--
				}
				R--
				for L < R && nums[L] == nums[L+1] {
					L++
				}
				L++
			} else if sum > 0 {
				for L < R && nums[R] == nums[R-1] {
					R--
				}
				R--
			} else {
				for L < R && nums[L] == nums[L+1] {
					L++
				}
				L++
			}
		}
	}
	return res
}

//哎呀写题写的好难受，感觉到瓶颈了？不太想写了……感觉好麻木，好多东西都不会，却只能在这里写题写题的。。。
//这道题的思路挺值得借鉴的，就是使用双指针，固定一个数，然后移动两个数来满足三数之和。
//就是去重复这件事情，搞得怪麻烦的。每次都要把重复的数跳过去然后再来下一次判断。你看看我这满满的if else就知道有多难受了。