// count no. of subsets with given difference such that union of these 2 subsets s1 ans s2 form original set

/*
   sum(s1) - sum(s2) = diff
   sum(s1) + sum(s2) = sum
   -------------------------
   sum(s1) = (sum+diff)/2
   
o So we count no. of subsets with given sum (sum+diff)/2
*/
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

int count_subsets(int arr[],int n,int diff)
{
	int sumofarray=0;
	for(int i=0;i<n;i++)
		sumofarray+=arr[i];
		
	int sum=(sumofarray + diff) / 2;
	
	return no_of_subsets_with_given_sum(arr,n,sum);
}

int main()
{
	int n=4;
	int arr[] = {1, 4, 2, 3};
	int diff = 4; 
	cout<<count_subsets(arr,n,diff);
	return 0;  

}
