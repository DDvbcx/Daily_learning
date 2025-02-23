// 回文数，https://leetcode.cn/problems/palindrome-number/description/
// 给定一个整数，判断是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// Method 1
// 将整数转换为字符串，然后判断字符串是否是回文字符串

#include <string>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;  // 负数不是回文数
    string num2str = to_string(x);
        int n = num2str.size();
        int l = 0, r = n -1;
        while (l < r) {
            if (num2str[l] != num2str[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
// Method 2 
// 通过取整和取余操作获取整数中对应的数字进行比较
bool isPalindrome(int x) {
    // 如果 x 小于 0 或者是以 0 结尾但不是 0 本身，直接返回 false
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int rt_num = 0;
    while (x > rt_num) {
        rt_num = rt_num * 10 + x % 10;  // 将 x 的最后一位数字加到 rt_num 上
        x /= 10;  // 去掉 x 的最后一位
    }

    // 比较 x 和 rt_num
    return x == rt_num || x == rt_num / 10;
}
