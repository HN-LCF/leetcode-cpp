//
// Created by HN-LCF on 2021/8/27.
//
/*
 * 题目
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * [English]: Given a string s, return the longest palindromic substring in s.
 *
 * Example 1:
 * - Input: s = "babad"
 * - Output: "bab"
 * - Note: "aba" is also a valid answer
 *
 * Example 2:
 * - Input: s = "cbbd"
 * - Output: "bb"
 *
 * Example 3:
 * - Input: s = "a"
 * - Output: "a"
 *
 * Example 4:
 * - Input: s = "ac"
 * - Output: "a"
 */

#include <bits/stdc++.h>
using std::string;
using std::vector;
using std::cout;
using std::cin;

class LongestPalindrome {
 public:
  /*
   * 动态规划
   */
  static string longestPalindrome1(string str) {
	int n = str.size();
	if (n < 2)
	  return str;
	int begin = 0, maxLength = 1;
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
	  dp[i][i] = true;
	}
	for (int l = 2; l <= n; ++l) {
	  for (int i = 0; i < n; ++i) {
		int j = l + i - 1;
		if (j >= n)
		  break;
		if (str[i] != str[j]) {
		  dp[i][j] = false;
		} else {
		  if (j - i < 3) {
			dp[i][j] = true;
		  } else {
			dp[i][j] = dp[i + 1][j - 1];
		  }
		}
		if (dp[i][j] && j - i + 1 > maxLength) {
		  maxLength = j - i + 1;
		  begin = i;
		}
	  }
	}
	return str.substr(begin, maxLength);
  }
};

int main() {
  cout << "Longest palindromic substring\n" << "- Please enter a string: \n";
  string str;
  cin >> str;

  auto p = LongestPalindrome::longestPalindrome1(str);
  cout << "Output: " << p;
}