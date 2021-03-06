/*
AUTHOR: Peeyush Yadav

Solution for www.spoj.com/problems/YODANESS

Algorithm: Binary Indexed Tree
*/
#include<bits/stdc++.h>
using namespace std;
#define max 40000
int tree[max],n;

int read(int index){                            //for adding content of tree from position 0 to index
        long long count1=0;
        while(index>0){
            count1+=tree[index];                // adding content of tree from (index-2^r+1) to (index) r(0-based)= position of 1st 1 from LSB
            index-=(index & (-index));
        }
        return count1;
}
void update(int index,int value){
        while(index<=n){
             tree[index]+=value;
             index+=(index & (-index));
        }
}
map<string,int> mymap;
int main(){

int a[max],b[max],pos,t,i;
char s1[30];
string s;
cin>>t;
while(t--){
    cin>>n;
    memset(tree,0,sizeof(tree));
    for (i=1;i<=n;i++) {
			scanf("%s",&s1);
			s=s1;
			mymap[s]=i;
    }
    for(i=1;i<=n;i++) {
			scanf("%s",&s1);
			s=s1;
			a[i]=mymap[s];
			b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        pos= lower_bound(b+1,b+1+n,a[i])-b-1;            //finding correct position of array element if sorted
        a[i]=++pos;                                      // now a[i] contains  position of initial a[i] if array was sorted
    }

    long long inversion=0;

    for(int i=n;i>=1;i--){
        inversion+=read(a[i]-1);                        //how many numbers less than a[i] have already occurred
        update(a[i],1);                                 // now a[i] will be added to tree

    }

    cout<<inversion<<endl;
}
}
