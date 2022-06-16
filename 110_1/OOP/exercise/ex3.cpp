//============================================================================
//============================================================================
// Name        : OOPexercise2.cpp
// Author      : William Chen
// Description : Reverse Linked List
//============================================================================
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

//============================================================================
// structure   : ListNode
// Goal        : Definition for singly-linked list.
//============================================================================
struct ListNode {
int val; // val: the value of the node.
ListNode *next; // next: pointer to next node.
ListNode(int x) : val(x), next(NULL) {} // initial every node
};

//============================================================================
// Function    : traverseNode
// Goal        : Print and traverse linked list.
// Return   : No return, but print the result.
//============================================================================
void traverseNode(ListNode* head)
{
	// The code is to fit our output format.
	cout << "[";
	while(head!=NULL)
	{
		if (head->next == NULL){
			cout << head->val;
			head = head->next;
		} else {
			cout << head->val;
			head = head->next;
			cout << ",";
		}
	}
	cout << "]" << endl;
}

//============================================================================
// Function    : reverseList
// Goal        : reverse the linked list.
// Return   : ListNode*
//============================================================================
ListNode* reverseList(ListNode* head) {
	ListNode* newHead = NULL;
	while(head != NULL){
		ListNode* newNode = new ListNode(head->val);
		newNode->next = newHead;
		newHead = newNode;
		head = head->next;
	}
	return newHead;
}

int main()
{

	int tmp;
	// Using queue to storage the cin (tmp) because we don't know the length of the input.
	queue<int> q;
	while(!cin.eof()){
		cin >> tmp;
		q.push(tmp);
	}
	// Set variable total length for the following step by queue.
	int total_Length = q.size();

	// Transform queue to list for the next step.
	int list[total_Length];
	for (int i = 0; i < total_Length; ++i){
		list[i] = q.front();
		q.pop();
	}

	// You can use the example for testing.
	// int list[5] = {1,2,3,4,5};
	// int total_Length = sizeof(list)/sizeof(list[0]); // Set variable total length for the following step.
	ListNode* head[total_Length]; // Initial a linked list(ListNode) array.

	// Initial linked list: put every value in "list" to "head"(array to linked list).
	for (int i = 0; i < total_Length; ++i){
		head[i] = new ListNode(list[i]);

	}

	// Initial link for every node: head[0] --> head[1] --> head[2]...head[last one] --> NULL
	for (int i = 0; i < total_Length; ++i){
		if (i != total_Length-1){
			head[i]->next = head[i+1];
		} else {
			head[i]->next = NULL;
		}
	}

	// Print linked list. (only for testing)
	// traverseNode(head[0]);

	// Reverse the linked list.
	ListNode* newHead = reverseList(head[0]);

	// Print linked list.
	traverseNode(newHead);

	return 0;
}
