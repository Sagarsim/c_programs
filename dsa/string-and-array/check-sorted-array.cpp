#include <iostream>
using namespace std;

bool is_sorted(int arr[], int size){
 
 if(size <= 1){
  return true;
 }
  
 for( int x=0;x < size - 1;x++ ){
   if(arr[x] > arr[x+1]){
      return false;
   }
 }
  
 return true;
}

int main() {

 int arr1[] = {20, 30, 40};
 int arr2[] = {3, 2, 4};
 int empty_arr[0];
 int single_element_arr[] = {20};

 cout << is_sorted(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;

 cout << is_sorted(arr2, sizeof(arr2) / sizeof(arr2[0])) << endl;

 cout << is_sorted(empty_arr, sizeof(empty_arr) / sizeof(empty_arr[0])) << endl;

 cout << is_sorted(single_element_arr, sizeof(single_element_arr) / sizeof(single_element_arr[0])) << endl;
 return 0;
}
