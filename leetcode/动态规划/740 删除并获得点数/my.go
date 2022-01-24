import "sort"
func deleteAndEarn(nums []int) int {
    len_nums := len(nums)
    if len_nums == 1{
        return nums[0]
    }
    dict := make(map[int] int)
    index := make([]int,0,len_nums)
    res := make(map[int] int)
    for i := 0; i < len_nums; i++{
        if _,ok := dict[nums[i]];ok{
            dict[nums[i]] += nums[i]
        }else{
            dict[nums[i]] = nums[i]
            res[nums[i]] = 0
            index = append(index,nums[i])
        }
    }
    sort.Ints(index)
    res[index[0]] = dict[index[0]]
    if index[0] + 1 == index[1]{
        res[index[1]] = max(res[index[0]],dict[index[1]])
    }else{
        res[index[1]] = res[index[0]] + dict[index[1]]
		len_index := len(index)
    for i := 2; i < len_index;i++{
        if index[i] - 1 == index[i-1]{
            res[index[i]] = max(res[index[i-1]],res[index[i-2]] + dict[index[i]])
        }else{
            res[index[i]] = res[index[i-1]] + dict[index[i]]
        }
    }
    return res[index[len_index - 1]]
}

func max(a int, b int) int{
    if a > b{
        return a
    }
    return b
}

//虽然确实能理解是个什么思路，但是未免也太绕了一点吧……给自己绕晕了