#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = NULL;

void addNode(int num){
    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}
void reverseList(){
    Node *temp = NULL, *nextNode = NULL;
    while(head){
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
  head = temp;
}
void Log(){
    Node *traverse = head;
    while(traverse != NULL){
        cout << traverse->data << "--";
        traverse = traverse->next;
    }
    cout << endl;
}

int main(){
addNode(23);
addNode(56);
addNode(77);
Log();
reverseList();
Log();
}