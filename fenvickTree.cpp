#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll; 
const int MAXN = 1e5; 
int arr[MAXN];

template <typename T>
struct FenwickTree
{
	T * tree;
	int n;

	FenwickTree () {}

	inline int f(int x)
	{
		return x & (-x);
	}

	void upd(int ind, T dx)
	{
		for (; ind < n; ind += f(ind + 1))
			tree[ind] += dx;
	}

	T get(int ind) const
	{
		T res = 0;

		for (;ind != -1; ind -= f(ind + 1))
			res = res + tree[ind];

		return res;
	}

	T seg(int l, int r)
	{
		return get(r) - get(l - 1);
	}

	FenwickTree (T * arr, int N)
	{
		n = N;
		tree = new T[n];
		fill(tree, tree + n, 0);                           
		for (int i = 0; i < n; ++i)
			upd(i, arr[i]);
        }
};

int main() {return 0;}
