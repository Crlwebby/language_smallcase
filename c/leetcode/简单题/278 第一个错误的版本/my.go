/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
	start := 1
	end := n
	var mid int
	mid = start + (end-start)/2
	for start < end {
		if isBadVersion(mid) {
			end = mid
		} else {
			start = mid + 1
		}
		mid = start + (end-start)/2
	}
	return mid
}

//下次一定记住mid = start + (end - start) / 2……
//这个东西的溢出，给我整的不自信了，看了半天循环感觉没发生问题啊，怎么就死循环了