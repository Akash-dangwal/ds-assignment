#include<iostream>
using namespace std;
class Node{
  public:
  int val;
  Node* nxt;
  Node(int v){
    val=v;
    this->nxt=NULL;
  }
};
class LinkedList{
  public:
Node* head;
Node* tail;
int size;
LinkedList(){
  head=tail=NULL;
  size=0;
}
void insertAtLast(int value){
  Node* temp=new Node(value);
  if(size==0) head=tail=temp;
  else{
    tail->nxt=temp;
    tail=temp;
  }
  size++;
}
void insetAtStart(int val){
  Node* temp=new Node(val);
  if(size==0) head=tail=temp;
  else{
    temp->nxt=head;
    head=temp;
  }
  size++;
}
void insertAtIdx(int idx,int val){
  if(idx<0||idx>size) cout<<"Invalid";
  else if(idx==0) insetAtStart(val);
  else if(idx==size-1) insertAtLast(val);
  else{
    Node* t=new Node(val);
    Node* temp=head;
    for(int i=1;i<idx;i++){
      temp=temp->nxt;
    }
    t->nxt=temp->nxt;
    temp->nxt=t;
    size++;
  }
}
void Display(){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->nxt;
  }
}
int getAtIdx(int idx){
  if(idx<0||idx>=size){
    cout<<"Invalid";
    return -1;
  }
  else if(idx==0) return head->val;
  else if(idx==size-1) return tail->val;
  else{
    Node* temp=head;
    for(int i=1;i<=idx;i++){
      temp=temp->nxt;
    }
    return temp->val;
  }
}

void deleteAtHead(){
  if(size==0) cout<<"List is empty";
  head=head->nxt;
  size--;
}
void deleteAtTail(){
  if(size==0) {
    cout<<"list is empty";
    return;
  }
  Node* temp=head;
 for(int i=1;i<size-1;i++){
    temp=temp->nxt;
  }
  temp->nxt=NULL;
  tail=temp;
  size--;
}
void deleteAtIdx(int idx){
  if(size==0) {
    cout<<"Link is Empty";
    return;
  }
  else if(idx<0||idx>=size) cout<<"Invalid";
  else if(idx==0) deleteAtHead();
  else if(idx==size-1) deleteAtTail();
  else{
    Node* temp=head;
    for(int i=1;i<=idx-1;i++){
      temp=temp->nxt;
    }
    temp->nxt=temp->nxt->nxt;
    size--;
  }
}
void rotateRight(int k) {
       Node* temp=head;
       Node* tail=NULL;
       int n=0;
       while(temp!=NULL){
        if(temp->nxt==NULL) tail=temp;
        n++;
        temp=temp->nxt;
       }
       
       
       if(k==0||n==0) return;
       k=k%n;
       temp=head;
       for(int i=1;i<n-k;i++){
        temp=temp->nxt;
       }
       tail->nxt=head;
       head=temp->nxt;
       temp->nxt=NULL;
       
    }
void reverseList() {
      Node* curr=head;
         Node* prev=NULL;
         Node* Next=NULL;
         while(curr){
             Next=curr->nxt;
             curr->nxt=prev;
             prev=curr;
            curr=Next;
         }
         head=prev;
    }
    void interleaf(LinkedList& ll2){
      Node* tA=head;
      Node* tB=ll2.head;
      Node* nextA=NULL;
      Node* nextB=NULL;
      while(tA!=NULL||tB!=NULL){
        nextA=tA->nxt;
        nextB=tB->nxt;
        tA->nxt=tB;
        tB->nxt=nextA;
        tA=nextA;
        tB=nextB;
      }
    }
    void middleNode() {
      Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->nxt!=NULL){
        slow=slow->nxt;
        fast=fast->nxt->nxt;
    }
     cout<<slow->val;

    }
    void firstOccurence(int k){
      Node* temp=head;
      int ans=-1;
      for(int i=0;i<size;i++){
        if(temp->val==k){
          ans=i;
          break;
        }
        temp=temp->nxt;
      }
      cout<<ans;
    }
void checkList(){
  if(size==0) cout<<"True";
  else cout<<"False";
}
void printSize(){
  cout<<size<<endl;
}
};

int main(){
LinkedList ll;
LinkedList ll1;
ll.insertAtLast(10);
ll.insertAtLast(20);
ll.insetAtStart(5);
ll.insetAtStart(1);
ll.Display();
cout<<endl;
ll1.insetAtStart(2);
ll1.insetAtStart(3);
ll1.insetAtStart(4);
ll1.insetAtStart(6);
ll1.Display();
cout<<endl;
ll.firstOccurence(18);



}