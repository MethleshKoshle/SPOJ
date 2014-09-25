#include <bits/stdc++.h>
using namespace std;
int array1[1000005];
int cal(int i){
    int count1=1,n=i;
    if(array1[i]>0) return array1[i];
    while(i!=1) {
        if(i<1000004 && array1[i]>0){
            count1+=array1[i]-1;
            break;
        }
        if(i&1){
                i=(3*i+1)>>1;
                count1++;
        }
        else i>>=1;

        count1++;
    }

    return array1[n]=count1;
}

int main(){
int i,j,a,b,max1;
memset(array1,-1,sizeof(array1));
while(scanf("%d%d",&a,&b)!=EOF){
    max1=-1;
    for(i=min(a,b);i<=max(a,b);i++) max1 = max(max1,cal(i));
    printf("%d %d %d\n",a,b,max1);
}

return 0;
}
