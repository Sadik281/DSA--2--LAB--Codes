/*Given an integer array arr[] of size n, find the inversion count in the array. Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Note: Inversion Count for an array indicates that how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is maximum. 

Examples: 

Input: arr[] = [4, 3, 2, 1]
Output: 6
Explanation: 

7_aug_25_2
 
Input: arr[] = [1, 2, 3, 4, 5]
Output: 0
Explanation: There is no pair of indexes (i, j) exists in the given array such that arr[i] > arr[j] and i < j

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: There is no pair of indexes (i, j) exists in the given array such that arr[i] > arr[j] and i < j */
#include <iostream>
#include<vector>
using namespace std;
int countMerge(vector<int> & arr,int l,int r,int m)
{
int n1= m-l+1;
int n2= r-m;
vector<int> left(n1);
vector<int> right(n2);
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[l+i]; // Copying elements to the left subarray
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=arr[m+1+i]; // Copying elements to the right subarray
    }
    int res=0;
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) // Merging the two subarrays and counting inversions

    {
        if(left[i]<=right[j]) // If the current element in the left subarray is less than or equal to the current element in the right subarray
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
            res+=n1-i;// Counting the number of inversions
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    return res;
}
int countInversions(vector<int> & arr,int l,int r)
{
    int res=0;
    if(l<r)
    {
        int m=l+(r-l)/2;
        res+=countInversions(arr,l,m);
        res+=countInversions(arr,m+1,r);
        res+=countMerge(arr,l,r,m);
    }
    return res;
}
int inversionCount(vector<int> & arr)
{
    return countInversions(arr,0,arr.size()-1);
}
int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int result=inversionCount(arr);
    cout<<"Inversion Count: "<<result<<endl;
    return 0;
}
