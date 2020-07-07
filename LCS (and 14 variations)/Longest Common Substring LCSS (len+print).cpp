//find length of longest common substring(continous pattern)

// SEE MAINLY BOTTOM UP SOLUTION

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;


int dp[1001][1001]; //global declaration
/*
int LCS(string a, string b, int n, int m, int count)         // recursion
{
	if(n==0 || m==0)
		return count;
	
	if(a[n-1]==b[m-1])
		return LCS(a,b,n-1,m-1,count+1);
	
	else
		return max(count, max(LCS(a,b,n-1,m,0), LCS(a,b,n,m-1,0)));
	
}

int LCS_DP(string a, string b, int n, int m, int count)         // top down
{
	//int dp[n+1][m+1];
	//memset(dp,-1,sizeof(dp));

	if(n==0 || m==0)
		return count;
	
	if(dp[n][m]!=-1)
		return dp[n][m];
	
	if(a[n-1]==b[m-1])
	{
		return dp[n][m] = LCS(a,b,n-1,m-1,count+1);
	}	

	else
		return dp[n][m] = max(count,max(LCS(a,b,n-1,m,0), LCS(a,b,n,m-1,0)));
	
			
}
*/
void LCS_bottom_up_DP(string a, string b, int n, int m)         // bottom up
{
	int p,q;
	//int dp[n+1][m+1];
	int result=INT_MIN;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
				
			else if(a[i-1]==b[j-1])     // we store the maximum result in variable and also its indices in p & q
			{
				dp[i][j] = 1 + dp[i-1][j-1];
				//result = max(result, dp[i][j]);
				if(dp[i][j]>result)
				{
					result = dp[i][j];
					p=i;
					q=j;
				}
				
			}
				
			else if(a[i-1]!=b[j-1])   // if not match then len is 0
				dp[i][j] = 0;
		}
	}
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	vector<char> v;
	cout<<p<<q<<endl;
	while(dp[p][q]>0)
	{
		if(a[p-1]==b[q-1])
		{
			v.push_back(a[p-1]);         //store that character
			p--;
			q--;
		}
	}
	
	reverse(v.begin(),v.end());
	
	cout<<"Length of longest common substring = "<<result<<endl;
	cout<<"and common string is ";
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	
	//return result;
}



int main() 
{ 
	string a,b;
	cin>>a>>b;
	//getline(cin,a);
	//getline(cin,b);
	
	int n = a.length();
	int m = b.length();
	
	memset(dp,-1,sizeof(dp));
	
	//cout<<LCS(a,b,n,m,0)<<endl; 
	//cout<<LCS_DP(a,b,n,m,0)<<endl;
	LCS_bottom_up_DP(a,b,n,m);
	
	return 0;

}
