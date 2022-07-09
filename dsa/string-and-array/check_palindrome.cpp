#include <iostream>
using namespace std;

void check_palindrome(string s){
 
 int len = s.length();

 for(int i = 0;i < len;i++){
   if(s[i] != s[len - i -1]){
     cout << "string " << s << " is not a palindrome\n";
     return; 
   }
 }
 cout << "string " << s << " is a palindrome\n"; 
}

int main(){
 
 string s1 = "hello", s2 = "kayak";

 check_palindrome(s1);
 check_palindrome(s2);

 return 0;
}
