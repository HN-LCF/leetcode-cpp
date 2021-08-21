//
// Created by HN-LCF on 2021/8/21.
//
/**
 * 乐鑫科技专场竞赛 2.
 */
#include <bits/stdc++.h>
#include <windows.h>
using std::vector;
using std::count;

class AdjustLevel {
 public:
  int adjustLevel(int cnt) {
//	if (cnt <= 0)
//	  return 0;
//	vector<bool> allStatus(cnt, false);
//	for (int i = 1; i < cnt; ++i) {
//	  for (int j = 1; j <= cnt; ++j) {
//		if (j % i == 0)
//		  allStatus[j - 1] = !allStatus[j - 1];
//	  }
//	}
//	allStatus[cnt - 1] = !allStatus[cnt - 1];
//	return count(allStatus.begin(), allStatus.end(), true);
	return sqrt(cnt);
  }
};

using std::cout;
using std::cin;

int main() {
  int value = 99999;
  AdjustLevel adjust_level;

  DWORD start, end;
  start = GetTickCount();

  auto p = adjust_level.adjustLevel(value);
  cout << "Input is: " << value << "\n" << "Output is: " << p << "\n";

  end = GetTickCount() - start;
  cout << "Time is: " << end;
}