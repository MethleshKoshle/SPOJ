#include <bits/stdc++.h>
#define MAX 200010
using namespace std;


int tree[MAX+1],N,x=0;
long b[MAX],tmp[MAX];
bool DD[MAX]={false};

void update(int index, int value){
    while(index<=MAX) {
        tree[index]+=value;
        index+=(index&-index);

    }
}
int read(int index){
    int ans=0;
    while(index>0) {
        ans+=tree[index];
        index-=(index&-index);
    }
    return ans;
}
pair <char,long> a[MAX];
set <int> myset;
set<int>::iterator it;
int main(){
int pos,h=0,fst,lst,num,ans,i;
char C;
scanf("%d",&N);
for(i=0;i<N;i++){
        scanf("%c",&C);
        scanf("%c%ld",&C,&num);
        a[i]= make_pair(C,num);
        if(C=='I'){
            it=myset.find(num);
            if(it==myset.end()) {
                    myset.insert(num);
                    b[++h]=num;
            }
        }
}
sort(b+1, b+h+1);

for(i=0;i<N;i++){
        if(a[i].first=='I'){
            pos=lower_bound(b+1,b+h+1,a[i].second)-b;
            if (DD[pos]==0) update(pos,1);
            DD[pos]=true;
        }
        else if(a[i].first=='D'){
            pos=lower_bound(b+1,b+h+1,a[i].second)-b;
            if(DD[pos] && b[pos]==a[i].second){
                    update(pos,-1);
                    DD[pos]=false;
            }
        }
        else if(a[i].first=='C'){
            pos=lower_bound(b+1,b+h+1,a[i].second)-b;
            ans=read(pos-1);
            printf("%d\n",ans);
        }
        else{
           fst=1;
           lst=h;
            while(fst<=lst){
                int m=(fst+lst)>>1;
                if(read(m)>=a[i].second) lst=m-1;
                else fst=m+1;
            }
            if(fst>h) printf("invalid\n");
            else printf("%ld\n",b[fst]);
        }
}
    return 0;
}
