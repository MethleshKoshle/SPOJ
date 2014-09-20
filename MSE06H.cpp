#include<bits/stdc++.h>

using namespace std;
#define max1 1010
#define lll int

lll tree[max1],n,k,m;
pair<lll,lll> a[1000009];

lll read(lll index){                              //for adding content of tree from position 0 to index
        lll count1=0;
        while(index>0){
            count1+=tree[index];                // adding content of tree from (index-2^r+1) to (index) r(0-based)= position of 1st 1 from LSB
            index-=(index & (-index));
        }
        return count1;
}
void update(lll index){
        while(index<max1){
             tree[index]++;
             index+=(index & (-index));
        }
}

int main(){
lll pos,t,x,y,w,s1=0;
long long ans=0;
scanf("%d",&t);
while(t--){
    ans=0;
    scanf("%d%d%d",&n,&m,&k);
    memset(tree,0,sizeof(tree));

    for(int i=0;i<k;i++){
        scanf("%d%d",&x,&y);
        a[i]=make_pair(x,y);
    }
    sort(a,a+k);

    for(int z=k-1; z>=0; z--){
        for( w=z ; w>=0 && (a[z].first==a[w].first) ; w--) ans+=read((a[w].second)-1);
        for( w=z ; w>=0 && (a[z].first==a[w].first) ; w--) update(a[w].second);
        z=w+1;
    }
    s1++;
    printf("Test case %d: %lld\n",s1,ans);
}
return 0;
}

