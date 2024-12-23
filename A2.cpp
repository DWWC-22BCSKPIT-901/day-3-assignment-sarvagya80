#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr; // Previous pointer
    ListNode* current = head; // Current pointer
    while (current != nullptr) {
        ListNode* nextNode = current->next; 
        current->next = prev; // Reverse the link
        prev = current; 
        current = nextNode; 
    }
    return prev; // New head of the reversed list
}
// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original List: ";
    printList(head);
    // Reverse the list
    ListNode* reversedHead = reverseList(head);
    cout << "Reversed List: ";
    printList(reversedHead);
    return 0;
}
