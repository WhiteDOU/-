#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int c;
	Node *lchild;
	Node *rchild;
} tree[105];

int loc;

Node *creat()
{
	tree[loc].lchild = tree[loc].rchild = NULL;
	return &tree[loc++];
}

void inOrder(Node *node)
{
	if (node->lchild)
	{
		inOrder(node->lchild);
	}
	cout << node->c << " ";
	if (node->rchild)
	{
		inOrder(node->rchild);
	}
}

void postOrder(Node *node)
{
	if (node->lchild)
		postOrder(node->lchild);
	if (node->rchild)
		postOrder(node->rchild);
	cout << node->c << " ";
}

void preOrder(Node *node)
{
	if (node->lchild)
		preOrder(node->lchild);
	if (node->rchild)
		preOrder(node->rchild);
	cout << node->c << " ";
}

Node *insert(Node *T, int x)
{
	if (T == NULL)
	{
		T = creat();
		T->c = x;
		return T;
	} else if (x < T->c)
	{
		T->lchild=insert(T->lchild,x);
	}
	else if(x>T->c)
	{
		T->rchild=insert(T->rchild,x);
	}
	return  T;
}
int main()
{
	int n;
	while (cin>>n)
	{
		loc=0;
		Node* T=NULL;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			T=insert(T,x);
		}
		preOrder(T);
		cout<<endl;
		inOrder(T);
		cout<<endl;
		postOrder(T);
		cout<<endl;
	}
	return 0;


}