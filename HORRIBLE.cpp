//AUTHOR: Peeyush yadav
#include<bits/stdc++.h>
using namespace std;

#define max1 100010
#define ll long long

ll tree2[max1],tree1[max1];
ll read(ll tree[],int index){                           
        ll count1=0;
        while(index>0){
            count1+=tree[index];
            index-=(index & (-index));
        }
        return count1;
}
void update(ll tree[],int index,ll value){
        while(index<max1){
             tree[index]+=value;
             index+=(index & (-index));
        }
}

int main(){
int t,n,q,x,y,l,r,v;
scanf("%d",&t);
while(t--){
    scanf("%d%d",&n,&q);
    memset(tree1,0,sizeof(tree2));
    memset(tree2,0,sizeof(tree2));
    while(q--){
        scanf("%d%d%d",&x,&l,&r);
        if(x)   printf("%lld\n",read(tree1,r)*r+read(tree2,r)-read(tree1,l-1)*(l-1)-read(tree2,l-1));
        else{
                scanf("%d",&v);
                update(tree1,l,v);
                update(tree1,r+1,-v);
                update(tree2,l,-(ll)v*(l-1));
                update(tree2,r+1,(ll)v*r);
        }
    }
}



return 0;
}
