#include <iostream>
using namespace std;



int main() {
    int a[] = {12, 45, 7, 89, 34, 67};
    int max = a[0];
    int n=6;

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }



    cout << "Largest element = " << max;

    return 0;
}
