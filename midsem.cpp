#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printEqualSumSets(int arr[], int n)
{
 int i, currSum;
 
 // Finding sum of array elements
 // using accumulate,An in built function to print sum of values in a given range
 int sum = accumulate(arr, arr+n, 0);

 // If sum is odd then array cannot be partitioned.
 if (sum%2 == 1) {
  cout << "No such distribution is possible";
  return;
 }
 // sum of two possible subsets.
 int k = sum/2;

 // Dynamic programming table with bolean values
 bool a[n + 1][k + 1];

 //setting beginner values 
 for (i = 1; i <= k; i++)
  a[0][i] = false;

 for (i = 0; i <= n; i++)
  a[i][0] = true;

 // Filling the DP table in bottom up manner.
 for (i = 1; i <= n; i++) {
  for (currSum = 1; currSum <= k; currSum++) {
    a[i][currSum] = a[i - 1][currSum];

   if (arr[i - 1] <= currSum)
    a[i][currSum] = a[i][currSum] | 
    a[i - 1][currSum - arr[i - 1]];
  }
 }

 // Dynamic array declaration
 vector<int> set1, set2;

 // If partition is not possible
 if (!a[n][k]) {
  cout << "No such distribution is possible\n";
  return;
 }

 i = n;
 currSum = k;

 while (i > 0 && currSum >= 0) {

  // If current element is not used in k,then,it goes to set 2.
  if (a[i - 1][currSum]) {
   i--;
   set2.push_back(arr[i]);
  }
  // If current element is used in k,then it goes to set 1.
  else if (a[i - 1][currSum - arr[i - 1]]) {
   i--;
   currSum -= arr[i];
   set1.push_back(arr[i]);
  }
 }

 cout<<"Such distribution is possible. One such possible distribution is as follows\n";
 cout << "List 1: ";
 for (i = 0; i < set1.size(); i++)
  cout << set1[i] << " ";
 cout << "\nList 2: ";
 for (i = 0; i < set2.size(); i++)
  cout << set2[i] << " ";
}

int main()
{
int n;
cout << "n=";
cin >> n;
if(n>100){
cout<<"The value of n should be less than or equal to 100";
}
int arr[n],sum =0;
for(int i = 0;i<n;i++){
cin>>arr[i];
if(arr[i]>20){
cout<<"The value of inputs should be less than or equal to 20";
}}
 printEqualSumSets(arr, n);
 return 0;
}
