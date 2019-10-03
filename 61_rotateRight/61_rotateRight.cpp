// 61_rotateRight.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
/**
* Definition for singly-linked list.
*/
 struct ListNode {     
	 int val;     
	 ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* rotateRight(ListNode* head, int k) {
	if (k == 0||head==NULL||head->next==NULL)return head;
	int n = k;
	ListNode* tmp = head;
	while (n--&&tmp->next)
	{
		tmp = tmp->next;
	}
	if (n==0&&tmp->next==NULL)
	{
		return head;
	}
	//链表长度小于偏移长度,算出偏移长度，再次偏移
	if (n>0)
	{
		n = k % (k - n);
		if (n==0)
		{
			return head;
		}
		tmp = head;
		while (n--&&tmp->next != NULL)
		{
			tmp = tmp->next;
		}
	}
	ListNode* endPos = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		endPos = endPos->next;
	}
	ListNode* newHead = endPos->next;
	endPos->next = NULL;
	tmp->next = head;
	return newHead;

}

int main()
{
// 	for (int i = 0; i < 20; i++)
// 	{
		ListNode* head = new ListNode(1);
		ListNode* tmp = head;
		for (int i = 2; i < 8; i++)
		{
			tmp->next = new ListNode(i);
			tmp = tmp->next;
		}

		tmp = rotateRight(head, 7);
		while (tmp)
		{
			cout << tmp->val << "->";
			tmp = tmp->next;
		}
		cout << endl;
//	}
	
    return 0;
}

