#include <iostream>
using namespace std;

int get_distinct_count(int arr[], int size) {
 
 int count = 0;
 bool is_distinct = true;

 for(int i=0;i<size;i++){
    is_distinct = true;
    
    for(int j=i-1;j>=0;j--){
        if(arr[i] == arr[j]){
            is_distinct = false;
        }
    }

    if(is_distinct == true){
        count++;
    }
 }
 
 return count;
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Total distinct elements: "<< get_distinct_count(arr, n) << endl;

    return 0;
}