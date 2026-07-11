#include<iostream>
using namespace std;
int f(int n){
if(n==1)
{
    return 1;
}
return n*f(n-1);
}

int main()
{
   int n;
   cout <<" Enter a number" <<endl;
   cin  >> n;
   int b= f(n);
   cout << "the Factorial: " << b;
return 0;
}
