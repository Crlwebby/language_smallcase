  public int longestPalindrome(String s) {
        // 找出可以构成最长回文串的长度
        int[] arr = new int[128];
        for(char c : s.toCharArray()) {
            arr[c]++;
        }
        int count = 0;
        for (int i : arr) {
            count += (i % 2);
        }
        return count == 0 ? s.length() : (s.length() - count + 1);
    }

//这个感觉也挺巧妙的哈
//如果是奇数，就把count+1，记录一下有多少个字符是奇数个的。
//然后后面作为一个整体去减掉即可。但是因为要取一个奇数，于是+1处理一下。
//如果全是偶数，那就直接返回原字符串的长度即可。