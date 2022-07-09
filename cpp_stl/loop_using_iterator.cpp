#include <iostream>
using namespace std;

int main()
{
 string s = "Sagar Gujarati";
 
 string::iterator it;

 for (it = s.begin(); it != s.end(); it++){
 	cout << *it;
 }
 cout << endl;

 return 0;
}
