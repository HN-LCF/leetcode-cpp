//
// Created by HN-LCF on 2021/8/17.
//
/**
 * 给定一个字符串`s`，请你找出其中不含有重复字符的**最长子串**的长度。
 *
 * Input:
 * - s = "abcabcbb"
 *
 * Output:
 * - 3
 *
 * Explanation:
 * - 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 * */
#include <bits/stdc++.h>

using std::string;
using std::unordered_set;
using std::max;

class LengthOfLongestSubstring {
 public:
  static int lengthOfLongestSubstring(string str) {
	if (str.size() < 2)
	  return str.size();
	// 哈希集合，记录每个字符是否出现过
	unordered_set<char> occ;
	int n = str.size();
	// 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
	int rk = -1, ans = 0;
	// 枚举左指针的位置，初始值隐性地表示为 -1
	for (int i = 0; i < n; ++i) {
	  if (i != 0) {
		// 左指针向右移动一格，移除一个字符
		occ.erase(str[i - 1]);
	  }
	  while (rk + 1 < n && !occ.count(str[rk + 1])) {
		// 不断地移动右指针
		occ.insert(str[rk + 1]);
		++rk;
	  }
	  // 第 i 到 rk 个字符是一个极长的无重复字符子串
	  ans = max(ans, rk - i + 1);
	}
	return ans;
  }
};

using std::cout;
using std::cin;

int main() {
  cout << "**Length Of Longest Substring**\n" << "Please enter a string: \n";
  string str;
  cin >> str;

  auto p = LengthOfLongestSubstring::lengthOfLongestSubstring(str);
  cout << "Max length is: " << p;
}
