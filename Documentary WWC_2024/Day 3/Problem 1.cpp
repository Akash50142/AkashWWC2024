INPUT:

#include <iostream>
#include <vector> // Include the vector header

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize a dummy node to simplify the result list creation
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Traverse both linked lists
        while (l1 != nullptr || l2 != nullptr) {
            // Get the values from the current nodes, or 0 if we've reached the end of a list
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum and the carry
            int total = val1 + val2 + carry;
            carry = total / 10;  // Update carry for the next iteration
            current->next = new ListNode(total % 10);  // Create a new node with the digit value
            current = current->next;  // Move to the next node

            // Move to the next nodes in the input lists
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // If there's a carry left, add a new node
        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        // Return the next node of the dummy head, which is the actual result
        return dummyHead->next;
    }
};

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummyHead->next;
}

// Helper function to print the linked list
void printLinkedList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << " -> nullptr" << endl;
}

int main() {
    // Create two linked lists representing the numbers 342 and 465
    ListNode* l1 = createLinkedList({2, 4, 3});  // Represents the number 342
    ListNode* l2 = createLinkedList({5, 6, 4});  // Represents the number 465

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result linked list
    printLinkedList(result);  // Output: 7 -> 0 -> 8 -> nullptr (represents the number 807)

    return 0;
}


OUTPUT:

7 -> 0 -> 8 -> nullptr
