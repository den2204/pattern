#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;
 
typedef long long ll;
 
#define NONE(K) (1ULL << K)
 
template <unsigned K> struct VebTree
{
	ll T_min, T_max;
	
	VebTree <K / 2> *T[1ULL << (K / 2)], *aux;
    
	VebTree(): T_min(NONE(K)), aux(NULL)
	{
		memset(T, 0, sizeof(T));
    	}
	
	bool empty() 
	{
		return T_min == NONE(K);
    	}
	
	ll high (ll key)
	{
		return key >> (K / 2);
    	}
 
    	ll low (ll key) 
	{
		return key & ((1ULL << (K / 2)) - 1ULL);
    	}
 
    	ll merge (ll high, ll low) 
	{
		return (high << (K / 2)) + low;
    	}
 
    	void insert(ll key)
	{
		if (empty())
		{
			T_min = T_max = key;
			return;
		}
		
		if (key < T_min)
			swap(key, T_min);

		if (key > T_max) 
			T_max = key;
			
		if (K != 1) 
		{
	            	ll key_high = high(key);
			ll key_low = low(key);

            		if (T[key_high] == NULL) 
				T[key_high] = new VebTree<(K / 2)>();
                
            		if (T[key_high]->empty()) 
			{
				if (aux == NULL)
					aux = new VebTree<(K / 2)>();
                		aux->insert(key_high);
            		}

            		T[key_high]->insert(key_low);
		}
	}
 
    	ll find_next (ll key)
	{
		if (key <= T_min) 
			return T_min;
		
		if (empty() || key > T_max) 
			return NONE(K);
		
		if (K == 1) 
			return T_max == key ? key : NONE(K);
		
		ll key_high = high(key);
		ll key_low = low(key);
		
		if (T[key_high] != NULL && key_low <= T[key_high]->T_max) 
			return merge(key_high, T[key_high]->find_next(key_low));
		
		if (aux != NULL) 
		{
			ll next_high = aux->find_next(key_high + 1);
			if (next_high != NONE(K / 2)) 
				return merge(next_high, T[next_high]->T_min);
		}

		return NONE(K);
    	}
 
    	bool lookup(ll key) 
	{
		if (key == T_min || key == T_max) 
			return true;
        
		ll key_high = high(key);
        	ll key_low = low(key);
        	return T[key_high] != NULL && T[key_high]->lookup(key_low);
    	}
};
 
int main() 
{
        VebTree<32> T;
 
        T.insert(5);
        T.insert(10);
        T.insert(3);
 
        assert(T.lookup(5));
        assert(T.lookup(10));
        assert(!T.lookup(15));
 
        assert(T.find_next(3) == 3);
        assert(T.find_next(4) == 5);
        assert(T.find_next(7) == 10);
        assert(T.find_next(100) == NONE(32));
 
        return 0;
}
