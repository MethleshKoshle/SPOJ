/*
   AUTHOR  : Peeyush Yadav
   Problem : http://www.spoj.com/problems/DQUERY/en/
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
int a[sz],pre[1000002],tree[sz],n,ans[200045]; 
pair<pair<int,int>,int> p[200045];

inline void update(int index ,int val){
	for(int i = index ; i < n+2 ; i +=i&-i ) tree[i]+=val;
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
	int q,x,y;
	s(n)
	f(i,1,n+1) s(a[i])
	s(q)
	f(i,0,q){
		s(x);s(y)
		p[i]= mp(mp(y,x),i);
	}
	
	sort(p,p+q);
	x=0;
	f(i,1,n+1){
		
		if(pre[a[i]]) update(pre[a[i]],-1);
		
		update(i,1);
		pre[a[i]]=i;
	
		while(x<q && p[x].fi.fi == i){
			ans[p[x].se] = read(p[x].fi.fi) - read(p[x].fi.se -1);
			x++;
		}	
	}
	f(i,0,q) p(ans[i]);
	
	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif
}  
