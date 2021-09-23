//minimum number of coins to get sum s;
#include<bits/stdc++.h>
using namespace std;

int get_min(int coin[],int sum,int n){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0)
                t[i][j]=0;
            if(i==0)
                t[i][j]=INT_MAX-1;
        }
    }
    for(int i=1;i<=sum;i++){
        if(i%coin[0]==0)
            t[1][i]=i/coin[0];
        else
            t[1][i]=INT_MAX-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1]<=j)
                t[i][j]=min(t[i][j-coin[i-1]],t[i-1][j]);
            else 
               t[i][j]= t[i-1][j];
        }
    }
    return t[n][sum];
}


int main(){
    int n,sum;
    cout<<"Enter total number of coins: ";
    cin>>n;
    int coins[n];
    cout<<"Enter the coins: ";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<"Enter the sum: ";
    cin>>sum;
    cout<<"The minimum number of coins to get "<<sum <<" is: "<<get_min(coins,sum,n);
    return 0;
}