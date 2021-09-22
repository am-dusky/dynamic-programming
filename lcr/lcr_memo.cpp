#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];
int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m]!=-1)
        return t[n][m];
    if(x[n-1]==y[m-1])
        return t[n][m]=(1+lcs(x,y,n-1,m-1));
    else 
        return t[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
}

int main(){
    int k;
    cin>>k;
    while(k--){
        memset(t,-1,sizeof(t));
        string s1,s2;
        cout<<"Enter the first string : ";
        cin>>s1;
        cout<<"Enter the second string : ";
        cin>>s2;
        int n=s1.length();
        int m=s2.length();
        int s= lcs(s1,s2,n,m);
        cout<<s<<"\n";
    }
    return 0;
}