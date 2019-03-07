#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node
{
	Node *lchild;
	Node *rchild;
	char c;
} Tree[50];
int loc;

Node *creat()
{
	Tree[loc].rchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

char str1[30], str2[30];

void postOrder(Node *T)
{
	if (T->lchild != NULL)
		postOrder(T->lchild);
	if (T->rchild != NULL)
		postOrder(T->rchild);
	cout << T->c;

}

Node *build(int s1, int e1, int s2, int e2)
{
	Node *ret = creat();
	ret->c = str1[s1];
	int rootIndex;
	for (int i = s2; i <= e2; ++i)
	{
		if (str2[i] == str1[s1])
		{
			rootIndex = i;
			break;
		}
	}
	if (rootIndex != s2)
	{
		ret->lchild=build(s1+1,s1+(rootIndex-s2),s2,rootIndex-1);
	}
	if (rootIndex != e2)
	{
		ret->rchild = build(s1+(rootIndex-s2)+1,e1,rootIndex+1,e2);
	}
	return  ret;
}

void inOrder(Node *tree)
{
	if (tree->lchild != NULL)
		inOrder(tree->lchild);
	if (tree->rchild != NULL)
		inOrder(tree->rchild);
	return;
}

int main()
{
	while (scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		loc=0;
		int l1=strlen(str1);
		int l2=strlen(str2);
		Node* T=build(0,l1-1,0,l2-1);
		postOrder(T);
		cout<<endl;
	}
	return 0;
}