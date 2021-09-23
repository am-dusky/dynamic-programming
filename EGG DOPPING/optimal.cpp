#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];
int solve(int e,int f){
    if(f==0||f==1||e == 1)
		return f;
	if (t[e][f]!=-1)
		return t[e][f];

	int ans=INT_MAX,temp,l = 1,h = f;
	while(l<=h)
	{
		int mid=(l+h)/2;
		int left=solve(e-1,mid-1);
		int right=solve(e,f-mid) ;
		temp =1+max(left,right);
		if(left<right)
			l=mid+1;
		else
			h=mid-1;
		ans =min(ans,temp);
	}
	return t[e][f]=ans;
}


int main(){
    int k;
    cin>>k;
    while(k--){
        memset(t,-1,sizeof(t));
        int e,f;
        cout<<"Enter the number of eggs and floor: ";
        cin>>e>>f;
        cout<<"The minimum number of ways are: "<<solve(e,f)<<"\n";
    }
    return 0;
}