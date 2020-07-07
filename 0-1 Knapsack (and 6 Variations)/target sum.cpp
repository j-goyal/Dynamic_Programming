/*Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer,
   you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
*/

// SAME AS count no. of subsets with given difference taking +ve's one side and -ve's we have same problem
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int no_of_subsets_with_given_sum(int arr[], int n, int sum) // recursion
{
	if(sum==0)
		return 1;
	if(n==0 && sum!=0)
		return 0;
	if(arr[n-1]<=sum)
		return no_of_subsets_with_given_sum(arr,n-1,sum-arr[n-1]) + no_of_subsets_with_given_sum(arr,n-1,sum); 
	else
		return no_of_subsets_with_given_sum(arr,n-1,sum);	
}

int no_of_ways(int arr[],int n,int sum)
{
	int sumofarray=0;
	for(int i=0;i<n;i++)
		sumofarray+=arr[i];
		
	int sum2=(sumofarray + sum) / 2;
	
	return no_of_subsets_with_given_sum(arr,n,sum2);
}


int main()
{
	int n=4;
	int arr[] = {1, 1, 2, 3}; 
	int sum=1;
	cout<<no_of_ways(arr,n,sum);
	return 0;  

}
