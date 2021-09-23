// count number of subarray with given sum s;
#include<bits/stdc++.h>
using namespace std;

int count_sum(int arr[],int sum,int n){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                t[i][j]=((t[i][j-arr[i-1]]+(t[i-1][j])));
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
    int n,sum;
    cout<<"Enter the number of items: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter sum: ";
    cin>>sum;
    int ans= count_sum(arr,sum,n);
    cout<<"The number of subsets are: "<<ans<<"\n";
    }
    return 0;
}
