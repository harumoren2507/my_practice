/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* ReverseList(struct ListNode *list)
{
    struct ListNode prev = NULL;
    struct ListNode current = list;
    struct ListNode next = NULL;
    while (current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    return prev;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result;
    struct ListNode *current;
    struct ListNode *re1;
    struct ListNode *re2;
    int carry = 0;
  
    result = NULL;
    re1 = ReverseList(l1);
    re2 = ReverseList(l2);

    result = malloc(sizeof(struct ListNode));
    while (re1 != NULL || re2 != NULL || carry != 0)
    {
        int sum = carry;
        if (re1 != NULL)
        {
            sum += re1->val;
            re1 = re1->next;
        }
        if (re2 != NULL)
        {
            sum += re2->val;
            re2 = re2->next;
        }
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        if (result == NULL)
        {
            result = newNode;
            current = result;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
        carry = sum / 10;
    }
    return (result);
}

//テストコ―ド


struct ListNode* createList(int* arr, int size) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    for (int i = 0; i < size; i++) {
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }
    return dummy.next;
}

// リストを表示する関数
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// リストを解放する関数
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // テストケース1: 342 + 465 = 807
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);
    
    printf("Test Case 1:\n");
    printf("Number 1: ");
    printList(l1);
    printf("Number 2: ");
    printList(l2);
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result);
    
    freeList(result);
    
    // テストケース2: 0 + 0 = 0
    l1 = createList((int[]){0}, 1);
    l2 = createList((int[]){0}, 1);
    
    printf("\nTest Case 2:\n");
    printf("Number 1: ");
    printList(l1);
    printf("Number 2: ");
    printList(l2);
    
    result = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result);
    
    freeList(result);
    
    // テストケース3: 9999 + 1 = 10000
    l1 = createList((int[]){9,9,9,9}, 4);
    l2 = createList((int[]){1}, 1);
    
    printf("\nTest Case 3:\n");
    printf("Number 1: ");
    printList(l1);
    printf("Number 2: ");
    printList(l2);
    
    result = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result);
    
    freeList(result);
    
    return 0;
}
/*


2. Add Two Numbers
Medium
Topics
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


https://leetcode.com/problems/add-two-numbers/description/
    

*/



