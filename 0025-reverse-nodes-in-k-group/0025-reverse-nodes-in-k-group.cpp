

class Solution {
public:
    // Function to reverse a linked list
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;  // New head after reversing the list
    }

    // Function to get the Kth node from a given position
    ListNode* getKthNode(ListNode* head, int k) {
        while (head != nullptr && k > 1) {
            head = head->next;
            k--;
        }
        return head;
    }

    // Function to reverse nodes in groups of K
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;  // No need to reverse if k is 1 or list is empty
        }

        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        ListNode* newHead = nullptr;

        while (temp != nullptr) {
            // Get the Kth node of the current group
            ListNode* kThNode = getKthNode(temp, k);

            // If the group has fewer than k nodes, don't reverse
            if (kThNode == nullptr) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            // Store the next node after the Kth node
            ListNode* nextNode = kThNode->next;

            // Disconnect the Kth node to prepare for reversal
            kThNode->next = nullptr;

            // Reverse the nodes from temp to Kth node
            ListNode* reversedHead = reverseLinkedList(temp);

            // Adjust the new head if this is the first group
            if (newHead == nullptr) {
                newHead = reversedHead;
            } else {
                prevLast->next = reversedHead;
            }

            // Update the pointer to the last node of the previous group
            prevLast = temp;

            // Move to the next group
            temp = nextNode;
        }

        return newHead == nullptr ? head : newHead;
    }
};

