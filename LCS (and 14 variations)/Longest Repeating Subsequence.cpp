// abnab    vxxy
// abnab    vxxy

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001]; //global declaration

int LRS_bottom_up_DP(string a, int n)
{
	string b;
	for(int i=0;i<n;i++)
	{
		b=b+a[i];
	}
	
	for (int i=0; i<=n; i++) 
        for (int j=0; j<=n; j++) 
        {
           	if(i==0 || j==0)
           		dp[i][j]=0;
		} 
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(a[i-1]==b[j-1] && i!=j)
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else
				dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	/*int p=n;
	int q=n;
	vector<char> v;
	
	while(p>0 && q>0)
	{
		if(dp[p][q] == 1 + dp[p-1][q-1])
		{
			v.push_back(a[p-1]);         //store that character
			p--;
			q--;
		}
		else 
		{
			if (dp[p-1][q] > dp[p][q-1]) 
        		p--; 
			else
        		q--; 	
		}
	}
	
	reverse(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++)
		cout<<v[i];

	*/
	return dp[n][n];
}

int main() 
{ 

	string a;
	cin>>a;
	//getline(cin,a);
	//getline(cin,b);
	
	int n = a.length();

	memset(dp,-1,sizeof(dp));
	
	cout<<LRS_bottom_up_DP(a,n);
	
	return 0;

}

