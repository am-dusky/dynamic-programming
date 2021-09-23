#include<bits/stdc++.h>
using namespace std;

int solve(int e,int f){
    if(f==0||f==1 ||e==1){
        return f;
    }
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int temp=1+max(solve(e-1,k-1),solve(e,f-k));
        mn=min(mn,temp);
    }
    return mn;
}


int main(){
    int k;
    cin>>k;
    while(k--){
        int e,f;
        cout<<"Enter the number of eggs and floor: ";
        cin>>e>>f;
        cout<<"The minimum number of ways are: "<<solve(e,f)<<"\n";
    }
    return 0;
}