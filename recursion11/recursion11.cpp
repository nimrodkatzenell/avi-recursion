#include <iostream>
#include <string.h>
using namespace std;
struct Node
{
	Node* next;
	char data;
};
bool compareListToStr(char* str, Node* head);
bool compareListToStr(char* str, Node* head, int maxDiff);
int main()
{
	char str[] = "halo";
	Node a;
	Node b;
	Node c;
	Node d;
	a.data = 'h';
	b.data = 'o';
	c.data = 'l';
	d.data = 'a';
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;

	cout << compareListToStr(str,&a,0);
	

}
bool compareListToStr(char* str, Node* head, int maxDiff)
{
	if (maxDiff < 0)
	{
		return false;
	}
	if (*str == '\0' || head == NULL)
	{
		return true;
	}
	Node* temp = head;
	if (*str == temp->data)
	{
		return compareListToStr(str + 1, head->next, maxDiff);
	}
	else
	{
		return compareListToStr(str + 1, head->next, maxDiff - 1);
	}

}
bool compareListToStr(char* str, Node* head)
{
	Node* temp = head;
	if (temp == NULL || *str == '\0')
	{
		return true;
	}
	if (temp->data == *str)
	{
		return compareListToStr(str + 1, head->next);
	}
	else
	{
		return false;
	}


}