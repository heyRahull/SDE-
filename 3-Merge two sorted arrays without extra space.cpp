/*
We are given two sorted arrays. We need to merge these two arrays such that the initial numbers (after complete sorting) are in the first array 
and the remaining numbers are in the second array. Extra space allowed in O(1).

Example: 

Input: ar1[] = {1,4,1,7,8,10};
       ar2[] = {2, 3,9};
Output: ar1[] = {1,1,2,3,4,7}
        ar2[] = {8,9,10} 

Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}  

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}
*/

Method 1 (Using extra space) T.C=O(nlogn), S.C=O(N)
  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[]={1,4,1,7,8,10};
    int arr2[]={2,3,9};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    int arr3[m+n];

    for(int i=0;i<n;i++)
    arr3[i]=arr1[i];

    for(int i=n;i<m+n;i++)
    arr3[i]=arr2[i-n];

    sort(arr3,arr3+(m+n));

    for(int i=0;i<n;i++)
    arr1[i]=arr3[i];

    for(int i=n;i<m+n;i++)
    arr2[i-n]=arr3[i];

    for(int x:arr1)
    cout<<"arr1 -> "<<x<<" "<<"\n";

    for(int y:arr2)
    cout<<"arr2 -> "<<y<<" "<<"\n";
}
------------------------------------------------------------------------------------------------------------------------

Method 2 (Using insertion sort type method) T.C = O(NM), S.C= O(1)
  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[]={1,4,7,8,10};
    int arr2[]={2,3,9};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    
    for(int i=0;i<n;i++)
    {
        if(arr1[i]>arr2[0])
        {
            swap(arr1[i],arr2[0]);
            int firstElement = arr2[0];
            int k;
            for(k=1;k<m && arr2[k]<firstElement;k++)
            {
                arr2[k-1]=arr2[k];
            }
            arr2[k-1]=firstElement;
        }
    }

    for(int i=0;i<n;i++)
    cout<<"arr1 -> "<<arr1[i]<<" "<<"\n";
    for(int j=0;j<m;j++)
    cout<<"arr2 -> "<<arr2[j]<<" "<<"\n";
}
-----------------------------------------------------------------------------------------------------------------------
  
Method 3 (Gap Method) T.C = O(N),S.C = O(1)
  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int nextGap(int gap)
{
    if(gap<=1)
    return 0;
    return (gap/2)+(gap%2);
}

void merge(int *arr1,int *arr2,int n,int m)
{
    int i,j,gap=n+m;

    for(gap=nextGap(gap); gap>0; gap=nextGap(gap))
    {
        //comparing elements in the first array
        for(i=0;i+gap<n;i++)
            if(arr1[i]>arr1[i+gap])
            swap(arr1[i],arr1[i+gap]);
        

        //comparing elements in both the arrays
        for(j=gap>n?gap-n:0; i<n&&j<m; i++,j++)
            if(arr1[i]>arr2[j])
            swap(arr1[i],arr2[j]);

        if(j<m)
        {
            //comparing elements in the second array
            for(j=0;j+gap<m;j++)
            if(arr2[j]>arr2[j+gap])
            swap(arr2[j],arr2[j+gap]);            
        }
    }
}

int main()
{
    int a1[]={10,27,38,43,82};
    int a2[]={3,9};
    int n= sizeof(a1)/sizeof(int);
    int m=sizeof(a2)/sizeof(int);

    merge(a1,a2,n,m);
    cout<<"First Array : ";
    for(int i=0;i<n;i++)
    cout<<a1[i]<<" "<<"\n";

    cout<<"Second array : ";
    for(int j=0;j<m;j++)
    cout<<a2[j]<<" "<<"\n";
}
