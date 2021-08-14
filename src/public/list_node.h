//
// Created by HN-LCF on 2021/8/14.
//

#ifndef LEETCODE_CPP_SRC_PUBLIC_LISTNODE_H_
#define LEETCODE_CPP_SRC_PUBLIC_LISTNODE_H_

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
typedef struct ListNode ListNode;

#endif //LEETCODE_CPP_SRC_PUBLIC_LISTNODE_H_
