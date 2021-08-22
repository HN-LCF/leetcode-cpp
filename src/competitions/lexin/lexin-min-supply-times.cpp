//
// Created by HN-LCF on 2021/8/22.
//

#include <bits/stdc++.h>
#include <windows.h>
#define valueName(x) #x

using std::vector;
using std::cout;

class MinSupplyTimes {
 public:
  static int minSupplyTimes(int num, int initWater, vector<vector<int>> &supplyStations) {

	return 0;
  }
};

void vectorsShow(const vector<vector<int>> &vec) {
  for (const auto &nums:vec) {
	cout << "\t";
	for (const auto &num:nums) {
	  cout << num << "\t";
	}
	cout << "\n";
  }
}

int main() {
  int num = 200, initWater = 11;
  vector<vector<int>> supplyStations = {{5, 5}, {6, 100}, {10, 189}, {11, 30}};

  DWORD start, end;

  start = GetTickCount();
  auto p = MinSupplyTimes::minSupplyTimes(num, initWater, supplyStations);
  end = GetTickCount() - start;

  cout << "Input is:\n" << "- num = " << num << "\n- initWater = " << initWater << "\n";
  cout << "- supplyStations is:\n";

  vectorsShow(supplyStations);

  cout << "Output is: " << p << "\n";
  cout << "Time is: " << end << "\n";
//  cout << valueName(supplyStations);
}