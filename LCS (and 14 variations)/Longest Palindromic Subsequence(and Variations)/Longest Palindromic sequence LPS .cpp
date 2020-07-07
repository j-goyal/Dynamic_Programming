// LPS(a) =~ LCS(a,reverse a)

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001]; //global declaration

int LPS_bottom_up_DP(string a, int n)
{
	string b;
	for(int i=0;i<n;i++)
	{
		b=b+a[i];
	}
	reverse(b.begin(),b.end());
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)	
				dp[i][j]=0;
			
			else if(a[i-1]==b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else if(a[i-1]!=b[j-1])
				dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	// print LPS
	int p=n;
	int q=n;
	vector<char> v;
	
	while(p>0 && q>0)
	{
		if(a[p-1]==b[q-1])
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
	
	cout<<"Longest palindromic subsequence is = ";
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	
	cout<<endl<<"and  its length is = ";
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
	
	cout<<LPS_bottom_up_DP(a,n);
	
	return 0;

}
