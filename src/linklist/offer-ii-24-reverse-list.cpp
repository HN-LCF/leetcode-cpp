//
// Created by HN-LCF on 2021/8/14.
//

/**
 * 给定单链表的头节点 `head`，请反转链表，并返回反转后的链表的头节点。
 *
 * Input:
 * - head = [1,2,3,4,5]
 * - head = [1,2]
 * - head = []
 *
 * Output:
 * - [5,4,3,2,1]
 * - [2,1]
 * - []
 *
 * */

#include <bits/stdc++.h>
#include "../public/list_node.h"

class ReverseList {
 public:
  /*迭代--原地翻转*/
  ListNode *reverseList1(ListNode *head) {
	if (!head || !head->next)
	  return head;
	ListNode *pre = nullptr;
	while (head != nullptr) {
	  ListNode *next = head->next;
	  head->next = pre;
	  pre = head;
	  head = next;
	}
	return pre;
  }

  /*递归翻转*/
  ListNode *reverseList2(ListNode *head) {
	if (!head || !head->next)
	  return head;
	ListNode *next = head->next;
	ListNode *pre = reverseList2(next);
	head->next = nullptr;
	next->next = head;
	return pre;
  }
};

using std::cout;
using std::cin;

int main() {
  cout << "Input List:\n";
  auto *a = new ListNode;
  auto p = a;
  int value1 = 0;

  while (cin >> value1) {
	p->next = new ListNode(value1);
	p = p->next;
  }

  ReverseList reverse_list;
  auto l = reverse_list.reverseList1(a->next);
  while (l != nullptr) {
	cout << l->val << "\n";
	l = l->next;
  }
}
