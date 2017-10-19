#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)  
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)

#ifdef LOCAL   
#define pv(a) cout << #a << " = " << a << '\n';
#else
#define pv(a) ;                                 
#endif	
                           
using namespace std;
typedef long long ll;

const int MAXN = 100;

struct Card
{
	int nominal;
	int suit;

	Card() {} 

	Card(int _nominal, int _suit): nominal(_nominal), suit(_suit) {}


	void print()
	{                           
		cout << '[';
		if (nominal == 10)
			cout << 'T';
		if (nominal == 11)
			cout << 'J';
		if (nominal == 12)
			cout << 'Q';
		if (nominal == 13)
			cout << 'K';
		if (nominal == 14)
			cout << 'A';
		if (nominal < 10)
			cout << nominal;

		cout << (char)(259 + suit);
		                    
		cout << ']';
	}                   
};

bool cmp(Card a, Card b)
{
	return a.nominal > b.nominal;
}

int number(vector <Card> &a)
{
	assert(sz(a) == 5);

	sort(all(a), cmp);

	bool flush = true;
	bool straight = true;


	forn(i, 4)
		flush &= a[i].suit == a[i + 1].suit;

	forn(i, 4)
		straight &= a[i].nominal == a[i + 1].nominal + 1;

	if (flush && straight)
	{
		return 15;		
	}

	vector < vector <Card> > cnt(15);

	forn(i, 5)
		cnt[a[i].nominal].push_back(a[i]);

	vector < vector <int> > c(5);

	forn(i, 15)
		c[sz(cnt[i])].push_back(i);
			

	if (sz(c[4]) == 1)
	{
		int ptr = 0;
		for (int i = sz(c) - 1; i >= 0; --i)
			for(int j = sz(c[i]) - 1; j >= 0; j--)
				forn(k, sz(cnt[c[i][j]]))
					a[ptr++] = cnt[c[i][j]][k];			


		return 14;
	}

	if (sz(c[3]) == 1 && sz(c[2]) == 1)
	{

		int ptr = 0;
		for (int i = sz(c) - 1; i >= 0; --i)           
			for(int j = sz(c[i]) - 1; j >= 0; j--)
				forn(k, sz(cnt[c[i][j]]))
					a[ptr++] = cnt[c[i][j]][k];

		return 13;
	}

	if (flush)
	{
		return 12;
	}

	if (straight)
	{
		return 11;
	}

	if (sz(c[3]) == 1)
	{
		int ptr = 0;
		for (int i = sz(c) - 1; i >= 0; --i)
			for(int j = sz(c[i]) - 1; j >= 0; j--)
                         	forn(k, sz(cnt[c[i][j]]))
					a[ptr++] = cnt[c[i][j]][k];
		
		return 10;
	}

	if (sz(c[2]) == 2)                                            
	{                                           		
                                                   
		int ptr = 0;
		for (int i = sz(c) - 1; i >= 0; --i)
			for(int j = sz(c[i]) - 1; j >= 0; j--)
                         	forn(k, sz(cnt[c[i][j]]))
					a[ptr++] = cnt[c[i][j]][k];
		

		return 9;
	}

	if (sz(c[2]) == 1)
	{
		int ptr = 0;
		for (int i = sz(c) - 1; i >= 0; --i)
			for(int j = sz(c[i]) - 1; j >= 0; j--)
                         	forn(k, sz(cnt[c[i][j]]))
					a[ptr++] = cnt[c[i][j]][k];
		
		return 8;
	}
	
	return 7;

}

int best_combination(vector <Card> &a, vector <Card> &b)
{                          
	int as = number(a);
	int bs = number(b);
	if (as != bs)
	{
		if (as > bs)
			return -1;
		else
			return 1;	
	}

	forn(i, 5)
		if (a[i].nominal != b[i].nominal)
		{
			if (a[i].nominal > b[i].nominal)
				return -1;
			else
				return 1;
		}

       return 0;
}



struct Player
{
	Card a, b;
	string name;
};
                       

bool used[MAXN][MAXN];

struct Combination
{
	vector <Card> cards;




};

int main()
{

	forn(iter, 30)
	{
		forn(i, MAXN)
			forn(j, MAXN)
				used[i][j] = false;

		vector <Card> a, b;

		forn(ind, 5)
		{
			int i = rand() % 13 + 2;
			int j = rand() % 4;

			while (used[i][j])
			{
				i = rand() % 13 + 2;
				j = rand() % 4;
                        }

                        a.push_back(Card(i, j));
		}

		forn(ind, 5)
		{
			int i = rand() % 13 + 2;
			int j = rand() % 4;

			while (used[i][j])
			{
				i = rand() % 13 + 2;
				j = rand() % 4;
                        }

                        b.push_back(Card(i, j));
		}
                                     
		forn(ind, 5)
			a[ind].print();
		
		cout << '\n';
		
		forn(ind, 5)
			b[ind].print();

		cout << '\n';

		cout << best_combination(a, b) << '\n';

		forn(ind, 5)
			a[ind].print();
		
		cout << '\n';
		
		forn(ind, 5)
			b[ind].print();

		cout << "\n\n\n";

	}

	

	return 0;
}
