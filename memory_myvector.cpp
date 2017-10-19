#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)  
#define all(a) a.begin(), a.end()

#ifdef LOCAL   
#define pv(a) cout << #a << " = " << a << '\n';
#else
#define pv(a) ;                                 
#endif	
                           
using namespace std;
typedef long long ll;

const int MAXN = 100500;


char mem[(int)4e8];

int memptr;

void * operator new (size_t s)
{
	memptr += s;
	return mem + memptr - s;
}

void operator delete (void *) {}


template <typename T>
struct vec
{
	vector <T> arr;


	vec () {}

	T &operator [] (int ind) 
	{
		assert(0 <= ind && ind < sz(arr));
		return arr[ind];
	}

	void resize(int x)
	{
		arr.resize(x);
	}
};

int main()
{

/*	vector <vector <int> > arr(1e6);

     	for (int i = 1e6 - 1; i >= 0; i--)
      	{
       		forn(j, 10)
       			arr[i].push_back(j);
       	}

       	forn(i, 1e6)
       	{
       		forn(j, 10)
       			arr[i].pop_back();
       	}
  */
       	cout.precision(3);

       	cout << (double) clock() / CLOCKS_PER_SEC << '\n'; 
	
	for (int i = 0; i < 10; i++)
	{
		string s = "echo ";
		s = s + (char)(i + '0') + '\n';
//		cout << s;
		system(s.c_str());
	}
	return 0;
}
