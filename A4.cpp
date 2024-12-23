#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverseKNodes(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextNode = nullptr;
    int count = 0;

    
    while (current != nullptr && count < k) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
        count++;
    }

    
    return prev;
}

// Function to reverse nodes in k-sized groups
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    // Check if there are at least k nodes left
    ListNode* temp = head;
    int count = 0;
    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    // If there are at least k nodes, reverse them
    if (count == k) {
        ListNode* reversedHead = reverseKNodes(head, k);
        head->next = reverseKGroup(temp, k); 
        return reversedHead;
    }

  
    return head;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    
    ListNode* head = new ListNode(11);
    head->next = new ListNode(26);
    head->next->next = new ListNode(33);
    head->next->next->next = new ListNode(46);
    head->next->next->next->next = new ListNode(51);
    head->next->next->next->next->next = new ListNode(62);

    cout << "Original List: ";
    printList(head);

    int k = 3; // Group size
    ListNode* result = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(result);

    return 0;
}
