//
// Created by HN-LCF on 2021/8/22.
//

#include <bits/stdc++.h>
#include <windows.h>

using std::string;
using std::to_string;

class GetKthNum {
  using ll = long long;
 public:
  static ll longPow(ll base, ll power) {
	// 快速幂，求 base ^ power
	ll result = 1;
	while (power) {
	  if (power & 1)
		result = (result * base);
	  base = (base * base);
	  power >>= 1;
	}
	return result;
  }

  static int getKthNum1(int k) {
	int n;
	for (n = 1; n < 9; n++) {
	  // 当前 n 位数的全部长度
	  ll currentLength = longPow(10, n - 1) * 9 * n;
	  if (currentLength >= k)
		break;
	  k -= currentLength;
	}

	// 已知 n 位数和 k，求第几个数的第几位
	ll q = (k + n - 1) / n, b = (k + n - 1) % n;
	// 第 q 个数
	ll num = longPow(10, n - 1) + q - 1;

	string s = to_string(num);
	return s[b] - '0';
  }

  /*
   * Disabled
   */
  static int getKthNum2(int k) {
	string str;
	for (int i = 1; i <= k; ++i) {
	  str += to_string(i);
	}
	auto p = str[k - 1];
	return p - '0';
  }
};

using std::cout;

int main() {
  int value = 20;

  DWORD start, end;
  start = GetTickCount();

  auto p = GetKthNum::getKthNum1(value);
  cout << "Input is: " << value << "\n" << "Output is: " << p << "\n";

  end = GetTickCount() - start;
  cout << "Time is: " << end;
}