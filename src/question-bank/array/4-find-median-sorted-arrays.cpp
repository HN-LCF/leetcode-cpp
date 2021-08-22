//
// Created by HN-LCF on 2021/8/17.
//
/**
 * 给定两个大小分别为`m`和`n`的正序（从小到大）数组`nums1`和`nums2。请你找出并返回这两个正序数组的**中位数**。
 *
 * Example1:
 * - Input: nums1 = [1,3], nums2 = [2]
 * - Output: 2.00000
 * - Explanation: MergedArray = [1,2,3], Median = 2
 *
 * Example2:
 * - Input: nums1 = [1,2], nums2 = [3,4]
 * - Output: 2.50000
 * - Explanation: MergedArray = [1,2,3,4], Median = (2 + 3) / 2 = 2.5
 *
 * Example3:
 * - Input: nums1 = [0,0], nums2 = [0,0]
 * - Output: 0.00000
 *
 * Example4:
 * - Input: nums1 = [], nums2 = [1]
 * - Output: 1.00000
 *
 * */

#include <bits/stdc++.h>

using std::vector;
using std::sort;

class FindMedianSortedArrays {
 public:
  static double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2) {
	double median = 0.0;
	for (auto num:nums2) {
	  nums1.push_back(num);
	}
	sort(nums1.begin(), nums1.end());
	auto n = nums1.size();
	if (n % 2 == 1) {
	  median = nums1[(n + 1) / 2 - 1];
	} else {
	  std::cout << nums1[n / 2 - 1] << "\t" << nums1[n / 2] << "\n";
	  median = (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
	}
	return median;
  }

  static double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
	return 0.0;
  }
};

using std::cout;
using std::cin;

int main() {
  cout << "Find Median in Sorted Arrays\n";
  int value;
  vector<int> num1, num2;

  cout << "----------------------------------------\n";
  while (cin >> value) {
	num1.push_back(value);
  }
  cin.clear();    // 重置错误输入
  cin.sync();    // 清空缓冲区

  cout << "----------------------------------------\n";
  while (cin >> value) {
	num2.push_back(value);
  }

  cout << "----------------------------------------\n";
  auto p = FindMedianSortedArrays::findMedianSortedArrays1(num1, num2);
  cout << "Median of MergedArray is: " << p;
}
