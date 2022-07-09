#include <iostream>
using namespace std;
int main() {

 int arr[] = {10, 20, 30};

 for(int &x: arr)
     x = x*2;
 for(int y: arr)
    cout << y << " ";

 return 0;
}
