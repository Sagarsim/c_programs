#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x){

	if(r >= l){
	  int mid = l + (r - l) / 2;

	  if(arr[mid] == x){
	    return mid;
	  }

	  if(arr[mid] > x){
	    return binarySearch(arr, l, mid - 1, x);
	  }

	  return binarySearch(arr, mid + 1, r, x);
	}
	
	return -1;
}

int main() {
  int arr[] = {2,3,4,5,6,67,77,88,99,102,111};
  int x = 5;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, x);
  (result == -1) 
	  ? cout << "Element not found" << endl
	  : cout << "Element found at index: " << result << endl;
  return 0;
}
