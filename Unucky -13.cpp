//Done by Yash Kumar Singh

#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;


ll mod=1e9+9;


void product(ll a[3][3],ll b[3][3], ll c[3][3]){  //Product of matrixs a and b, stored in matrix c
	int i , j , k;
	ll result[3][3];
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			result[i][j]=0;
			for (k=0;k<3;++k){
				result[i][j]+=(a[i][k]*(b[k][j]))%mod;
			}
		result[i][j]=result[i][j]%mod;
		}
	}
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			c[i][j]=result[i][j];
		}
	}
	return;
}




int main() {
  ll n;
  int t;
  ll a[31][3][3];               //stack of all 2^30 matrix 
  a[0][0][0]=8;                 //values of first matrix
  a[0][0][1]=8;
  a[0][0][2]=8;

  a[0][1][0]=1;
  a[0][1][1]=1;
  a[0][1][2]=1;

  a[0][2][0]=1;
  a[0][2][1]=0;
  a[0][2][2]=1;
  for(int i=1;i<31;++i){
	    product(a[i-1],a[i-1],a[i]);
  }
  
  scanf("%d",&t);
  while(t--){
	  
  scanf("%lld",&n);
  
	ll result[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	int j=0;
	while(n>0){
		if(n%2==1){
			  product(result,a[j],result);
		}
		j++;
		n/=2;
	}
	printf("%lld\n",(result[0][0]+result[1][0]+result[2][0])%mod);
}
return 0;
}
