func firstBadVersion(n int) int {
    return sort.Search(n, func(version int) bool { return isBadVersion(version) })
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/first-bad-version/solution/di-yi-ge-cuo-wu-de-ban-ben-by-leetcode-s-pf8h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//官方解法清新脱俗~这个sort.search是个什么东西……
