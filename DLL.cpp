#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void traverseLL(Node* head){
    Node* temp = head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node* deleteHeadOfLL(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTailOfLL(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    temp->back = nullptr;
    prev->next = nullptr;
    delete temp;
    return head;
}

Node* deleteKthElementOfLL(Node* head, int k){
    if(head == NULL || head->next == NULL) return NULL;

    if(k==1){
        head = deleteHeadOfLL(head);
    }
    else{
        Node* temp = head;
        while(temp){
            --k;
            if(k==0) break;
            temp = temp->next;
        }

        Node* piche = temp->back;
        Node* age = temp->next;
        piche->next = age;
        if(age!=NULL){
            age->back = piche;
        } 
        temp->next = nullptr;
        temp->back = nullptr;
    }

    return head;
}

Node* insertBeforeHead(Node* head, int val){
    Node* temp = new Node(val, head, nullptr);
    head->back = temp;
    head = temp;
    return head;
}

Node* insertBeforeTail(Node* head, int val){
    Node* res = head;
    while(res->next){
        res = res->next;
    }
    Node* prev = res->back;
    Node* temp = new Node(val, res, prev);
    res->back = temp;
    if(prev!=NULL) prev->next = temp;
    else head = temp;
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val){
    Node* temp = head;
    if(k==1){
        return insertBeforeHead(head, val);
    }
    while(temp){
        k--;
        if(k==0) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* reverseDLL(Node* head)
{   
    if(head == NULL || head->next == NULL) {
        return head;
    } 
    Node* temp = head;
    while(temp){
        Node* front = temp->next;
        temp->next = temp->back;
        if(front!=NULL) temp->back = front;
        else{
            head = temp;
            temp->back = nullptr;
            break;
        }
        temp = front;
    }
    return head;
}

Node * deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;
    while(temp){
        if(temp->data == k){
            if(temp == head){
                head = temp->next;
                temp->next = nullptr;
                head->back = nullptr;
                delete temp;
                temp = head;
            }
            else{
                Node* front = temp->next;
                Node* back = temp->back;
                back->next = front;
                if(front != NULL) front->back = back;
                temp->next = nullptr;
                temp->back = nullptr;
                delete temp;
                temp = front;
            }
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    vector<int> arr = {1, 1};
    Node* head = convertToLL(arr);
    head = deleteAllOccurrences(head, 1);
    traverseLL(head);
    return 0;
}