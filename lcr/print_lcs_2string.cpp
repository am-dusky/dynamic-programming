//printing the lcs of two string
#include<bits/stdc++.h>
using namespace std;

string print(string x,string y,int n,int m){
    int t[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                t[i][j]=1+(t[i-1][j-1]);
            else 
                t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
    string s="";
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1])
                i--;
            else 
                j--;
        }
    }
    reverse(s.begin(),s.end());
    return s;
}


int main(){
    int k;
    cin>>k;
    while(k--){
        string s1,s2;
        cout<<"Enter the first string : ";
        cin>>s1;
        cout<<"Enter the second string : ";
        cin>>s2;
        int n=s1.length();
        int m=s2.length();
        string  s= print(s1,s2,n,m);
        cout<<s<<"\n";
    }
    return 0;
}