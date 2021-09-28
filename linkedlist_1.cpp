#include <iostream>
using namespace std;

class Node {
public:
    int Value;
    Node* Next;
};
void printList(Node* n) {
    while (n!=NULL) {
        cout << n->Value << endl;
        n = n->Next;
    }
}


void insertAtTheEnd(Node** head,int newValue){
  //1.Prepare a new node
  Node* newNode = new Node();
  newNode->Value = newValue;
  newNode->Next=NULL;
  //2. If linked list is empty, newNode will be a head node
  if(*head==NULL){
    *head = newNode;
    return;
  }
  //3.Find the last node
  Node* last=*head;
  while(last->Next!=NULL){
    last=last->Next;
  }
  last->Next = newNode;
  //4.Insert newNode after last node(at the end)
}

void insertAtTheFront(Node** head,int newValue){
  //1.Preare a new node
  Node* newNode = new Node();
  newNode->Value = newValue;
  //2.Put it in front of current head
  newNode->Next=*head;
  //3. Move head of the list to point to the newNode
  *head=newNode;
}

void insertAfter(Node*previous,int newValue) {
  //1. check if previous node is NULL
  if(previous==NULL){
    cout<<"Previous can not be null";
    return;
  }
  //2. Prepare a newNode
  Node* newNode=new Node();
  newNode->Value=newValue;
  //3. Insert newNode after previous
  newNode->Next=previous->Next;
  previous->Next=newNode;
}

void printLastThirdNode(Node* n) {
  while((n->Next->Next->Next)!=NULL) {
    n=n->Next;
  }
  cout<<n->Value<<"\n";
}

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->Value = 1;
    head->Next = second;
    second->Value = 2;
    second->Next = third;
    third->Value = 3;
    third->Next = fourth;
    fourth->Next=NULL;
    // insertAtTheFront(&head,-1);
    // insertAtTheFront(&head,-2);
    // insertAtTheEnd(&head,4);
    // insertAtTheEnd(&head,5);

    printLastThirdNode(head);

    system("pause>0");
}