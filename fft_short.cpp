#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

const int BASE = 10;
const int MAXN = 4e6;
const double PI = 3.1415926535;

struct Complex
{
	double re, im;

	Complex() {}

	Complex(double _re, double _im): re(_re), im(_im) {}

	const Complex operator + (Complex b)
	{
		return Complex(re + b.re, im + b.im);
	}              
	const Complex operator - (Complex b)
	{
		return Complex(re - b.re, im - b.im);
	}              
	const Complex operator * (Complex b)
	{
		return Complex(re * b.re - im * b.im, re * b.im + im * b.re);
	}              
	const Complex operator * (double x)
	{
		return Complex(re * x, im * x);
	}
};                     

Complex af[MAXN];
Complex bf[MAXN];
Complex calcw[MAXN];
int rev[MAXN];

inline void cnt_rev(int szn)
{
	rev[0] = 0;
	for (int x = 1; x < (1 << szn); x++)
	{
		int k = 0;
                while ((x & (1 << k)) == 0)
                	k++;
		rev[x] = rev[x ^ (1 << k)] ^ (1 << (szn - 1 - k));                                                                
        }
}

void fft (Complex * a, int n)
{                           
	int szn = 0;
	while ((1 << szn) != n)
		szn++; 

        forn(i, n)
        	if (i < rev[i])
        		swap(a[i], a[rev[i]]);

        Complex v, u;
        for(int i = 0; i < n; i += 2)
	{                           		
		u = a[i + 1];
		a[i + 1] = a[i] - u;
		a[i] = a[i] + u;
	}                                                                       
                                                       
	for(int i = 0; i < n; i += 4)
	{                                    
        	u = a[i + 2];   
		a[i + 2] = a[i] - u;		
		a[i] = a[i] + u;                          
	}
        
	for(int i = 0; i < n; i += 4)
	{                       
		u = Complex(-a[i + 3].im, a[i + 3].re);
		a[i + 3] = a[i + 1] - u;
		a[i + 1] = a[i + 1] + u;   		
	}

        for (int len = 8; len <= n; len *= 2)
        {
       		double ang = 2 * PI / len;

		Complex w0(cos(ang), sin(ang));  

		calcw[0] = Complex(1, 0);

		for (int i = 0; i < len / 2; i++)
			calcw[i + 1] = calcw[i] * w0;

		for(int i = 0; i < n; i += len)
		{       
			Complex *p1 = a + i;
			Complex *p2 = a + i + len / 2;
			Complex *pend = a + i + len / 2;
			Complex *pw = calcw;
			for (;p1 != pend; p1++, p2++, pw++)
			{
				u = *p2 * *pw;
				*p2 = *p1 - u;
				*p1 = *p1 + u;
			}
               	}
        }
}

void multyply(vector <int> a, vector <int> b, vector <int> & res)
{
	int sz = 4;      
	while (sz < (int)a.size())
		sz <<= 1;
	while (sz < (int)b.size())
		sz <<= 1;
	sz <<= 1;
	int szn = 0;
	while ((1 << szn) != sz)
		szn++;
	cnt_rev(szn);
	a.resize(sz);
	b.resize(sz);
	res.resize(sz);
                     
        forn(i, sz)
		af[i] = Complex(a[i], 0), bf[i] = Complex(b[i], 0);
	fft(af, sz);
	fft(bf, sz);
	forn(i, sz)
		af[i] = af[i] * bf[i];
	fft(af, sz);

	reverse(af + 1, af + sz);
	forn(i, sz)
		af[i].re /= sz;
	forn(i, sz)
		res[i] = int(af[i].re + 0.5);
}

bool is_digit(char x)
{
	return '0' <= x && x <= '9';
}

void scan(vector <int> &res)
{
	char c = getchar();
	while (!is_digit(c))
		c = getchar();
      	do
       	{
       		res.push_back(c - '0');
       		c = getchar();
       	}
       	while (is_digit(c));
       	reverse(res.begin(), res.end());
}

void print(vector <int> &res)
{
	int mind = 0;
	forn(i, (int)res.size())
	{
		res[i] += mind;
		mind = res[i] / BASE;
		res[i] %= BASE;	                
	}
	assert(mind == 0);
	while (!res.empty() && res.back() == 0)
		res.pop_back();
	if (res.empty())
		res.push_back(0);
	reverse(res.begin(), res.end());
	forn(i, (int)res.size())
		putchar(res[i] + '0');
	putchar('\n');
}

int main()
{
	vector <int> a, b, c;
	scan(a);
	scan(b);
	multyply(a, b, c);
	print(c);
	cerr.precision(3);
	cerr << "time is " << (double)clock() / CLOCKS_PER_SEC  << "s.\n";
	return 0;
}