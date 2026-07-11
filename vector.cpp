#include<iostream>
using namespace std;

int main()
{
   int arr[]={20,30,1,2,54};
   int idx=1;
   int len= sizeof(arr)/sizeof(int);
   int* newArr=new int[len-1];
   for(int i=0,j=0;j<len;i++)
   {
       if(i!=idx)
       {
           newArr[j]=arr[i];
           j++;
       }
   }
   for(int i=0;i<len-1;i++)
   {
       cout << newArr[i] << " ";
   }


}

