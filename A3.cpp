#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to add two numbers represented as linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0); // Dummy node to simplify the logic
    ListNode* current = dummyHead;
    int carry = 0;

    // Traverse both lists
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10; // Compute carry
        current->next = new ListNode(sum % 10); // Create a new node for the current digit
        current = current->next;
    }

    return dummyHead->next; // Return the next node of the dummy head
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create the first linked list: 2 -> 4 -> 3 (342)
    ListNode* l1 = new ListNode(23);
    l1->next = new ListNode(42);
    l1->next->next = new ListNode(33);

    // Create the second linked list: 5 -> 6 -> 4 (465)
    ListNode* l2 = new ListNode(65);
    l2->next = new ListNode(67);
    l2->next->next = new ListNode(64);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
