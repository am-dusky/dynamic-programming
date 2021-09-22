#include<bits/stdc++.h>
using namespace std;

int lcs(string x,int n){
    int t[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
                t[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==x[j-1] && i!=j)
                t[i][j]=1+t[i-1][j-1];
            else 
                t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
    return t[n][n];
}


int main(){
    int k;
    cin>>k;
    while(k--){
        string s1;
        cout<<"Enter the first string : ";
        cin>>s1;
        int n=s1.length();
        int s= lcs(s1,n);
        cout<<s<<"\n";
    }
    return 0;
}
