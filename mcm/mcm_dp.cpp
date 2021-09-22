#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n){
    int t[n][n];
    for(int i=1;i<n;i++){
        t[i][i]=0;
    }
    int j;
    for (int L=2;L<n;L++)
    {
        for (int i=1;i<n-L+1;i++)
        {
            j=i+L-1;
            t[i][j]=INT_MAX;
            for (int k=i;k<=j-1;k++)
            {
                int q = t[i][k] + t[k + 1][j]+arr[i - 1]*arr[k]*arr[j];
                if (q<t[i][j])
                    t[i][j] = q;
            }
        }
    }
 
    return t[1][n-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The minimum cost is : "<<solve(arr,n);
    cout<<endl;
    }
    return 0;
}
