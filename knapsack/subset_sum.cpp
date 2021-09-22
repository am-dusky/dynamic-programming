//any subset present whose sum is s

#include<bits/stdc++.h>
using namespace std;

bool subset(int arr[],int sum,int n){
    //initialization
    bool t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
        }
    }

    //code
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                t[i][j]=((t[i-1][j-arr[i-1]])|| (t[i-1][j]));
            else 
                t[i][j]=t[i-1][j];
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=sum;j++){
    //             cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return t[n][sum];
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int arr[n],sum;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the sum: ";
    cin>>sum;
    bool ans= subset(arr,sum,n);
    if(ans==true){
        cout<<"Possible!!!!\n";
    }
    else{
        cout<<"Not possible!!\n";
    }
    }
    return 0;
}
