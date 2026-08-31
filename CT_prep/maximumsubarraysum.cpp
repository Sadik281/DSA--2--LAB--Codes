#include <bits/stdc++.h>
#include<algorithm>

using namespace std;
 int mss(vector<int>& arr,int low,int mid,int high)
 {
    int leftsum=INT_MIN;
    int sum=0;
    for(int i=mid;i>=low;i--)
    {
        sum+=arr[i];
        if(sum>leftsum)
        {
            leftsum=sum;
        }
    }
    int rightsum=INT_MIN;
   sum=0;
    for(int i=mid+1 ;i<=high;i++)
    {
        sum+=arr[i];
        if(sum>rightsum)
        {
            rightsum=sum;
        }
    }
    return leftsum+rightsum;
}
int mass(vector<int>& arr,int low,int high)
{
    if(low==high)
    {
        return arr[low];
    }
    int mid=low+(high-low)/2;
    int leftsolve=mass(arr,low,mid);
    int rightsolve=mass(arr,mid+1,high);
    int crosssum=mss(arr,low,mid,high);
    return max({leftsolve,rightsolve,crosssum});
}
int main ()
{
vector<int> arr={-16,-23,18,20,-7,12,-5};
int sum=mass(arr,0,arr.size()-1);
cout << sum <<endl;
return 0 ;
}

