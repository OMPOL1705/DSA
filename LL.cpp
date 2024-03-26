#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertToArray(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthLL(Node* head){
    int cnt=0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void traverseLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data  << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Deletion operations in Linked list

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node* removeKthElement(Node* head, int k){
    if(head == NULL) return head;

    if(k==1){
        head = removeHead(head);
    }
    else{
        Node* temp = head;
        Node* prev = NULL;
        int cnt=0;
        while(temp){
            cnt++;
            if(cnt == k){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

Node* removeElementByValue(Node* head, int el){
    if(head == NULL) return head;

    if(head->data == el){
        head = removeHead(head);
    }
    else{
        Node* temp = head;
        Node* prev = NULL;
        while(temp){
            if(temp->data == el){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

// Insertion operations in Linked list

Node* insertAtHead(Node* head, int el){
    Node* temp = new Node(el, head);
    head = temp;
    return head;
}

Node* insertAtTail(Node* head, int el){
    if(head == NULL) return new Node(el);
    Node* newNode = new Node(el, nullptr);
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtKthPosition(Node* head, int el, int k){
    if(head == NULL){
        if(k==1) return new Node(el);
        else return head;
    } 
    
    if(k==1){
        head = insertAtHead(head, el);
    }
    else{
        int cnt=0;
        Node* temp = head;
        while(temp){
            cnt++;
            if(cnt==k-1){
                Node* newNode = new Node(el, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}

Node* insertBeforeValue(Node* head, int val, int el){
    if(head == NULL) return head;
    if(head->data == val){
        head = insertAtHead(head, el);
    }
    else{
        Node* temp = head;
        while(temp->next){
            if(temp->next->data == val){
                Node* newNode = new Node(el, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}

Node* insertAfterValue(Node* head, int val, int el){
    if(head == NULL) return head;
        Node* temp = head;
        while(temp){
            if(temp->data == val){
                Node* newNode = new Node(el, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    return head;
}

Node* miidleInd(Node* head){
    Node* fast = head;
    Node* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow ->next;
        }
        return slow;
}

Node* reverseLL(Node* head){
    // if(head == NULL || head->next == nullptr){
    //         return head;
    //     }
    //     Node* newHead = reverseLL(head->next);
    //     Node* front = head->next;
    //     front->next = head;
    //     head->next = nullptr;
    //     return newHead;

    if(head == nullptr) return head;
        Node* temp = head;
        Node* prev = nullptr;
        while(temp){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    return prev;
}

void checkLoop(Node* head){
        Node* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cout << "true\n";
                return;
            }
        }
    cout << "false\n";
}

Node *entryOfLoop(Node *head) {
        if(head == nullptr) return head;

        Node* slow = head, *fast = head, *entry = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
    return NULL;
}

int lengthOfLoop(Node *head) {
    if(head == nullptr) return 0;
    Node* slow = head, *fast = head, *entry = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                int cnt=1;
                slow = slow->next;
                while(slow != fast){
                    cnt++;
                    slow = slow->next;
                }
                return cnt;
            }
        }
    return 0;
}

void isPalindrome(Node* head) {
        Node* slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newHead = reverseLL(slow->next);
        Node* first = head, *second = newHead;
        while(second){
            if(first->data != second->data){
                reverseLL(newHead);
                cout << "false\n";
                return; 
            }
            first = first->next;
            second = second->next;
        }

        reverseLL(newHead);
        cout << "true\n";
}

Node* findMiddle(Node* head)    {
        Node* slow = head;
        Node* fast = head->next;

        while(fast && fast->next)   {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

Node* mergeTwoList(Node* list1, Node* list2)    {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(list1 && list2)   {
            if(list1->data > list2->data) {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
            else    {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
        }
        if(list1)  temp->next = list1;
        else    temp->next = list2;

        return dummyNode->next;
}

Node* sortList(Node* head) {
        if(!head || !head->next)    return head;

        Node* mid = findMiddle(head);
        Node* right = mid->next;
        Node* left = head;

        mid->next = nullptr;
        
        left = sortList(left);
        right = sortList(right);

        return mergeTwoList(left, right);
}

Node* sortList2(Node *head){
    Node* zeroHead = new Node(-1), *zero = zeroHead;
    Node* oneHead = new Node(-1), *one = oneHead;
    Node* twoHead = new Node(-1), *two = twoHead;

    Node* temp = head;
    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }

        temp = temp->next;
    }

    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    return zeroHead->next;
}

int main() {
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    vector<int> arr = {1, 1, 1, 2, 1};
    Node* head = convertToArray(arr);
    head = sortList2(head);
    traverseLL(head);
    return 0;
}