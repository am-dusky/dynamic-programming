#include<bits/stdc++.h>
using namespace std;

int rod_cutting(int length[],int val[],int len,int n){
    int t[n+1][len+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=len;j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=len;j++){
            if(length[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i][j-length[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][len];
}


int main(){
    int n,len;
    cout<<"Enter the length of rod: ";
    cin>>len;
    n=len;
    int length[n],price[n];
    for(int i=0;i<n;i++){
        length[i]=i+1;
    }
    cout<<"Enter the value of different lengths: ";
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<"The total value earned is : "<<rod_cutting(length,price,len,n);
    return 0;
}