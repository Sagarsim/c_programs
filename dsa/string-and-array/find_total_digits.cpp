#include <iostream>
using namespace std;

int main(){
 
 unsigned long long int x = 757477757777;

 int total_digits = 0;

 do {
  total_digits++;
  x /= 10;
 }
 while(x);

 cout << "Total digits: "<< total_digits << endl;
 
 return 0;
}
