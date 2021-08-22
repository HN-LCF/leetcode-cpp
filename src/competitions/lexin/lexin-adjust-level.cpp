//
// Created by HN-LCF on 2021/8/21.
//
/**
 * 乐鑫科技专场竞赛 2. 调整电平
 * 题目详见 `docs/competition/lexin/lexin-competition.md`
 */

#include <bits/stdc++.h>
#include <windows.h>

using std::vector;
using std::count;

class AdjustLevel {
 public:
  /*
   * 正确解
   */
  static int adjustLevel1(int cnt) {
	return floor(sqrt(cnt));
  }

  /*
   * Disabled
   * 错误解--未明白题目要点，超时
   */
  static int adjustLevel2(int cnt) {
	if (cnt <= 0)
	  return 0;
	vector<bool> allStatus(cnt, false);
	for (int i = 1; i < cnt; ++i) {
	  for (int j = 1; j <= cnt; ++j) {
		if (j % i == 0)
		  allStatus[j - 1] = !allStatus[j - 1];
	  }
	}
	allStatus[cnt - 1] = !allStatus[cnt - 1];
	return static_cast<int>(count(allStatus.begin(), allStatus.end(), true));
  }
};

using std::cout;
using std::cin;

int main() {
  int value = 99999;

  DWORD start, end;
  start = GetTickCount();

  auto p = AdjustLevel::adjustLevel1(value);
  cout << "Input is: " << value << "\n" << "Output is: " << p << "\n";

  end = GetTickCount() - start;
  cout << "Time is: " << end;
}