#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int activitySelection(vector<int> &start, vector<int> &finish) {
    vector<vector<int>> arr;
 
    for (int i = 0; i < start.size(); i++) {
        arr.push_back({start[i], finish[i]});
    }

    // Sort activities by finish time
    sort(arr.begin(), arr.end(), compare);
    
    // At least one activity can be performed
    int count = 1;  
    
    // Index of last selected activity
    int j = 0;      

    for (int i = 1; i < arr.size(); i++) {
       
        // Check if current activity starts
        // after last selected activity finishes
        if (arr[i][0] > arr[j][1]) {
            count++;
            
            // Update last selected activity
            j = i;  
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start, finish);
    return 0;
}