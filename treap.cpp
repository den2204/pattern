#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <ctime>
using namespace std;
typedef long long ll;

struct Node
{
	int x;
	int y;
	Node * l;
	Node * r;
	Node(int x, int y):
		x(x), y(y), l(NULL), r(NULL) {}
	Node() {}
};

typedef Node * TNode;

struct Treap
{
	TNode root;

	TNode merge(TNode a, TNode b)
	{
		if (a == NULL)
			return b;
		if (b == NULL)
			return a;
		if (a->y > b->y)
		{
			a->r = merge(a->r, b);
			return a;
		}
		else
		{
			b->l = merge(a, b->l);
			return b;
		}
	}

	void split(TNode v, int value, TNode &a, TNode &b)
	{
		if (v == NULL)
		{
			a = b = NULL;
			return;
		}
		else
		{
			if (v->x <= value)
			{
				split(v->r, value, v->r, b);
				a = v;
			}
			else
			{
				split(v->l, value, a, v->l);
				b = v;
			}
		}
	}
};

int main()
{
	return 0;
}
