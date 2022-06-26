#include <iostream>
using namespace std;

int main()
{
 char myStr[20];
 cout<< "Enter a string: ";
 cin >> myStr;
 cout << "Converted in uppercase: ";
 for (int i=0;i<strlen(myStr);i++){
   cout << (char)(myStr[i] - 'a' + 'A');
 }
 return 0;
}
