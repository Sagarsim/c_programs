#include <iostream>
using namespace std;

int main(){

 char opr;
 int op1, op2;

 while(true) {

  cin >> opr;
  
  if(opr == 'Q')
    break;
  else {

   cin >> op1 >> op2;
    
   switch(opr) {
    case '+':
      cout << op1 + op2 << endl;
      break;
    case '-':
      cout << op1 - op2 << endl;
      break;
    case '*':
      cout << op1 * op2 << endl;
      break;
    case '/':
      cout << op1 / op2 << endl;
      break;
    default:
      cout << "Invalid Operator\n";
      break;
   }
  }
 }
  
 return 0;
}
