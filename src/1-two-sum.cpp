//
// Created by HN-LCF on 2021/8/14.
//
/**
 * 给定一个整数数组 `nums`和一个整数目标值 `target`，请你在该数组中找出和为目标值 `target`的
 * 那两个整数，并返回它们的数组下标。
 *
 * 1. 可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 2. 可以按任意顺序返回答案。
 *
 * Input:
 * - nums = [2,7,11,15], target = 9
 *
 * Output:
 * - [0,1]
 *
 * Explanation:
 * - nums[0] + nums[1] == 0, return [0,1]
 *
 * */

#include <bits/stdc++.h>

using std::vector;
using std::unordered_map;

class TwoSum {
 public:
  /*暴力枚举法*/
  vector<int> twoSum1(vector<int> &nums, int target) {
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
	  for (int j = i + 1; j < n; ++j) {
		if (nums[i] + nums[j] == target) {
		  return {i, j};
		}
	  }
	}
	return {};
  }

  /*哈希表高效查找*/
  vector<int> twoSum2(vector<int> &nums, int target) {
	unordered_map<int, int> hashtable;
	for (int i = 0; i < nums.size(); ++i) {
	  auto it = hashtable.find(target - nums[i]);
	  if (it != hashtable.end()) {
//		std::cout << it->first << ": " << it->second << "\n";
		return {it->second, i};
	  }
	  hashtable[nums[i]] = i;
	}
	return {};
  }
};

using std::cout;

int main() {
  vector<int> num1 = {2, 7, 11, 15};
  int target1 = 9;
  vector<int> num2 = {3, 2, 4};
  int target2 = 6;
  vector<int> num3 = {3, 3};
  int target3 = 6;

  TwoSum two_sum;
  vector<int> num11, num22, num33;

  num11 = two_sum.twoSum1(num1, target1);
  num22 = two_sum.twoSum1(num2, target2);
  num33 = two_sum.twoSum1(num3, target3);
  for (auto num:num11) {
	cout << num << "\t";
  }
  cout << "\n";
  for (auto num:num22) {
	cout << num << "\t";
  }
  cout << "\n";
  for (auto num:num33) {
	cout << num << "\t";
  }
  cout << "\n";

  cout << "---------------------------------------\n";

  num11 = two_sum.twoSum2(num1, target1);
  num22 = two_sum.twoSum2(num2, target2);
  num33 = two_sum.twoSum2(num3, target3);
  for (auto num:num11) {
	cout << num << "\t";
  }
  cout << "\n";
  for (auto num:num22) {
	cout << num << "\t";
  }
  cout << "\n";
  for (auto num:num33) {
	cout << num << "\t";
  }
  cout << "\n";
}
