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

int main() {
  cout << "Reverse List\n";
  auto *a = new ListNode;
  auto *b = new ListNode;
  auto *c = new ListNode;
  auto *d = new ListNode;
  auto *e = new ListNode;
  a->val = 1;
  b->val = 2;
  c->val = 3;
  d->val = 4;
  e->val = 5;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = nullptr;

  ReverseList reverse_list;
  auto t1 = reverse_list.reverseList1(a);
  auto p = t1;
  while (p != nullptr) {
	cout << p->val << "\n";
	p = p->next;
  }
//  auto t2=reverse_list.reverseList2(a);
}
