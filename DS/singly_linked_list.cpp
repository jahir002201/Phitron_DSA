#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
      int val;
      Node* next;
      Node(int val){
        this->val=val;
        this->next=NULL;
      }
};
void insert_head(Node* &head,int val){
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;
}
void insert(Node* head,int pos,int val){
    Node* newNode=new Node(val);
    Node* tmp=head;
    for(int i=1;i<=pos-1;i++){
        tmp=tmp->next;
    }
    newNode->next=tmp->next;
    tmp->next=newNode;
}
void insert_tail(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
int size(Node* head){
    Node* tmp=head;
    int count=0;
    while(tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}
void delete_head(Node* &head){
    if(head==NULL) return;
    Node* deleteNode=head;
    head=head->next;
    delete deleteNode;
}
void delete_node(Node* &head,int pos){
    if(pos==0){
        Node* deleteNode=head;
        head=head->next;
        delete deleteNode;
        return;
    }
    Node* tmp=head;
    for(int i=1;i<=pos-1;i++){
        tmp=tmp->next;
    }
    Node* deleteNode=tmp->next;
    tmp->next=tmp->next->next;
    delete deleteNode;
}
void bubble_sort_desc(Node* head){
    for(Node* i=head;i!=NULL && i->next !=NULL;i=i->next){
        for(Node* j=i->next;j!=NULL;j=j->next){
            if(i->val < j->val){
                swap(i->val,j->val);
            }
        }
    }
}
void print_recursion(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    print_recursion(head->next);
}
void print_reverse(Node* head){
    if(head==NULL) return;
    print_reverse(head->next);
    cout<<head->val<<" ";
}
void print_linked_list(Node* head){
    Node* tmp=head;
    while(tmp){
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    cout<<"Enter values (-1 to end): ";
    while(cin>>val && val!=-1){
        insert_tail(head,tail,val);
    }
    cout<<"Print Recursion: ";
    print_recursion(head);
    cout<<endl;
    cout<<"Print Reverse: ";
    print_reverse(head);
    cout<<endl;
    insert_head(head,5);
    cout<<"Insert Head val=5: "<<endl;
    insert(head,4,7);
    cout<<"Insert pos=4, val=7 :"<<endl;
    cout<<"Normal Print: ";
    print_linked_list(head);
    cout<<endl;
    cout<<"Delete Head: "<<endl;
    delete_head(head);
    cout<<"Size: "<<size(head)<<endl;
    cout<<"Delete Node pos=2: "<<endl;
    delete_node(head,2);
    bubble_sort_desc(head);
    cout<<"Sorted Linked List (Descending Order): ";
    print_linked_list(head);
    return 0;
}