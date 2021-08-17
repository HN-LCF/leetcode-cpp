//
// Created by HN-LCF on 2021/8/16.
//
/**
 * 给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照**逆序**的方式存储的，
 * 并且每个节点只能存储**一位**数字。
 *
 * 1. 请将两个数相加，并以相同形式返回一个表示和的链表。
 * 2. 可以假设除了数字 0 之外，这两个数都不会以 0开头。
 *
 * Input:
 * - l1 = [2,4,3], l2 = [5,6,4]
 *
 * Output:
 * - [7,0,8]
 *
 * Explanation:
 * - 342 + 465 = 807
 *
 * */

#include <bits/stdc++.h>
#include "../public/list_node.h"

using std::vector;
using std::cout;
using std::cin;
using std::sort;

class AddTwoNumbers {
 public:
  /*老实人做法--错误--易导致溢出*/
  static ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) {
	vector<int> t1, t2;
	int n1, n2, sum;
	n1 = n2 = 0;
	for (ListNode *p = l1; p != nullptr; p = p->next) {
	  t1.push_back(p->val);
	}
	for (ListNode *p = l2; p != nullptr; p = p->next) {
	  t2.push_back(p->val);
	}
	for (auto it = t1.rbegin(); it != t1.rend(); it++) {
	  n1 = n1 * 10 + *it;
	}
	for (auto it = t2.rbegin(); it != t2.rend(); it++) {
	  n2 = n2 * 10 + *it;
	}

	sum = n1 + n2;
	auto *res = new ListNode;
	auto *p = res;
	while (sum != 0) {
	  p->val = sum % 10;
	  sum /= 10;
	  if (sum != 0) {
		p->next = new ListNode;
		p = p->next;
	  }
	}
	return res;
  }

  /*为什么也有溢出*/
  static ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
	int len1 = 1;    // 记录l1的长度
	int len2 = 1;    // 记录l2的长度
	ListNode *p = l1;
	ListNode *q = l2;
	while (p->next != nullptr)// 获取l1的长度
	{
	  len1++;
	  p = p->next;
	}
	while (q->next != nullptr)// 获取l2的长度
	{
	  len2++;
	  q = q->next;
	}
	if (len1 > len2)    // l1较长，在l2末尾补零
	{
	  for (int i = 1; i <= len1 - len2; i++) {
		q->next = new ListNode(0);
		q = q->next;
	  }
	} else    // l2较长，在l1末尾补零
	{
	  for (int i = 1; i <= len2 - len1; i++) {
		p->next = new ListNode(0);
		p = p->next;
	  }
	}
	p = l1;
	q = l2;
	bool count = false;//记录进位
	auto *l3 = new ListNode(-1);//存放结果的链表
	ListNode *w = l3;//l3的移动指针
	int i = 0;//记录相加结果
	while (p != nullptr && q != nullptr) {
	  i = count + p->val + q->val;
	  w->next = new ListNode(i % 10);
	  count = i >= 10 ? true : false;
	  w = w->next;
	  p = p->next;
	  q = q->next;
	}
	if (count)//若最后还有进位
	{
	  w->next = new ListNode(1);
	  w = w->next;
	}
	return l3->next;
  }

  /*递归*/
  static ListNode *addTwoNumbers3(ListNode *l1, ListNode *l2) {
	return dfs(l1, l2, 0);
  }

  static ListNode *dfs(ListNode *l, ListNode *r, int i) {
	if (!l && !r && !i) return nullptr;
	int sum = (l ? l->val : 0) + (r ? r->val : 0) + i;
	auto *node = new ListNode(sum % 10);
	node->next = dfs(l ? l->next : nullptr, r ? r->next : nullptr, sum / 10);
	return node;
  }
};

int main() {
  cout << "Input List:\n";
  auto *a = new ListNode;
  auto p = a;
  int value1 = 0;

  while (cin >> value1) {
	p->next = new ListNode(value1);
	p = p->next;
  }

  cin.clear();    // 重置错误输入
  cin.sync();    // 清空缓冲区

  cout << "-------------------------------\n";
  auto *b = new ListNode;
  auto q = b;
  int value2 = 0;
  while (cin >> value2) {
	q->next = new ListNode(value2);
	q = q->next;
  }

  cout << "-------------------------------\n";

  auto l = AddTwoNumbers::addTwoNumbers3(a->next, b->next);
  cout << "Output List:\n";
  while (l != nullptr) {
	cout << l->val << "\t";
	l = l->next;
  }
}