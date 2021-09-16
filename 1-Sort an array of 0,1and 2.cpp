/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:
Input: nums = [0]
Output: [0]

Example 4:
Input: nums = [1]
Output: [1]
*/

Method 1 (Sort the array using the sort function) - T.C = O(nlogn), S.C = O(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={0,1,1,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    for(int x : arr)
    cout<<x<<" ";
}

-------------------------------------------------------------------------------------------------
Method 2 (Using Counting Sort) - T.C = O(2N), S.C = O(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={0,1,1,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a=0,b=0,c=0; //a,b and c will contain the count of 0,1 and 2 respectively
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        a++;
        else if(arr[i]==1)
        b++;
        else if(arr[i]==2)
        c++;
    }
     for(int i=0;i<a;i++)
     {
         arr[i] = 0;
     }
     for(int j=a;j<a+b;j++)
     {
         arr[j]=1;
     }
     for(int k=a+b;k<a+b+c;k++)
     {
         arr[k]=2;
     }
     for(int x:arr)
     cout<<x<<" ";
}

Note : The counting sort approach requires two passes,first for counting the no. of 0,1 and 2 and second for filling the elements into array. Lets now see a more optimal solution.

-----------------------------------------------------------------------------------------------------
Method 3 (Dutch National Flag Algo) - T.C = O(N), S.C = O(1)

This method is the most optimal approach, it sorts the array in just one pass only.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={0,1,1,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
   
   int low = 0;
   int mid = 0;
   int high = n-1;

   while(mid<=high)
   {
       switch(arr[mid])
       {
           case 0: 
           swap(arr[low],arr[mid]);
           low++,mid++;
           break;

           case 1:
           mid++;
           break;

           case 2 :
           swap(arr[mid],arr[high]);
           high--;
           break;
       }
   }
   for(int x : arr)
   cout<<x<<" ";
}

