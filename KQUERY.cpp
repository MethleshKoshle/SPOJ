/*
   AUTHOR  : Peeyush Yadav
   Problem : http://www.spoj.com/problems/KQUERY/en/
*/
#include<bits/stdc++.h>
using namespace std; typedef long long ll; typedef pair<int,int> grp;
inline ll power(ll a,ll b)     { ll r=1; while(b){ if(b&1) r=r*a    ; a=a*a    ; b>>=1;} return r;}
inline ll power(ll a,ll b,ll m){ ll r=1; while(b){ if(b&1) r=(r*a)%m; a=(a*a)%m; b>>=1;} return r;}
void fast(){	
	#ifdef Megamind
		freopen("inp.txt","r",stdin);
		//freopen("out.txt","w",stdout);
		#define trace(x)            cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
		#define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
		#define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
	#else
		#define trace(x)
		#define trace2(x,y)
		#define trace3(x,y,z)
	#endif
	
	#define fi 						first
	#define se 						second
	#define mp 						make_pair
	#define pb(x) 					push_back(x)
	#define s(x)                    scanf("%d",&x);
	#define sl(x)                   scanf("%lld",&x);
	#define p(x)                    printf("%d\n",x);
	#define f(a,b,c)                for(int a=b;a<c;a++)
	#define r(a,b,c)				for(int a=b;a>c;a--)
	#define p2(x,y)                 printf("%d %d\n",x,y);
	#define pl(x)                   printf("%lld\n",x);
	#define pl2(x,y)                printf("%lld %lld\n",x,y);
	#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
	#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
}
/*........................................................END OF TEMPLATES.......................................................................*/
#define sz 30012
#define sz1 200003
int tree[sz],n,ans[sz1]; 
grp p[sz1],query[sz1],inp[sz];

inline void update(int index){
	for(int i = index ; i < n+2 ; i +=i&-i ) tree[i]++;
}
inline int read (int index){
	int counter=0;
	while(index>0){
		counter+=tree[index];
		index-=index&-index;
	}
	return counter;
}

int main(){
	fast();
	int q,x,y,k;
	s(n)
	f(i,0,n) {
		s(inp[i].fi)
		inp[i].se = i+1;
		
	}
	sort(inp,inp+n);
	reverse(inp,inp+n);
	s(q)
	f(i,0,q){
		s(x) 
		s(y)
		s(k)
		p[i]= mp(k,i);
		query[i]= mp(x,y);
	}
	
	sort(p,p+q);
	reverse(p,p+q);
	x=0;
	f(qu,0,q){
		while(x < n && inp[x].fi > p[qu].fi){
			update(inp[x].se);
			x++;
			
		}
		ans[p[qu].se] = read(query[p[qu].se].se) - read(query[p[qu].se].fi - 1);
	}
	f(i,0,q) p(ans[i]);
	
	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif
}  
