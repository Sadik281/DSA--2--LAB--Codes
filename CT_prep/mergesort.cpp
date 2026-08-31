#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr, int l, int r, int m)
{
    vector<int> left;
    vector<int> right;

    for(int i = l; i <= m; i++)
        left.push_back(arr[i]);

    for(int i = m + 1; i <= r; i++)
        right.push_back(arr[i]);

    int i = 0;
    int j = 0;
    int k = l;

    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < left.size())
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < right.size())
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> & arr,int low,int high)
{
    
    if(low>=high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(arr,low,mid); // Recursively sorting the left subarray
    mergeSort(arr,mid+1,high); // Recursively sorting the right subarray
    merge(arr,low,high,mid);
}
void display (vector<int> & arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" "; // Displaying the elements of the array
    }
    cout<<endl;
}
int main ()
{
    vector<int> arr={12, 11, 13, 5, 6, 7};
    mergeSort(arr,0,arr.size()-1);
    cout<<"Sorted array is: ";
    display(arr); // Displaying the sorted array
    return 0;


}
