////////////////////////////////////////////////////////////////
/* Reverse a sublist of a linked list 
 * Hard Accuracy: 77.86% Submissions: 2361 Points: 8
 *
 * Given a linked list and positions m and n. Reverse the linked
 * list from position m to n.
 * 
 * Example 1:
 * Input :
 * N = 10
 * Linked List = 1->7->5->3->9->8->10
 *                ->2->2->5->NULL
 * m = 1, n = 8
 * Output : 2 10 8 9 3 5 7 1 2 5 
 * Explanation :
 * The nodes from position 1 to 8 
 * are reversed, resulting in 
 * 2 10 8 9 3 5 7 1 2 5.
 * 
 * Example 2:
 * Input:
 * N = 6
 * Linked List = 1->2->3->4->5->6->NULL
 * m = 2, n = 4
 * Output: 1 4 3 2 5 6
 * Explanation:
 * Nodes from position 2 to 4 
 * are reversed resulting in
 * 1 4 3 2 5 6.
 * Your task :
 * You don't need to read input or print anything. Your task is
 * to complete the function reverseBetween() which takes the
 * head of the linked list and two integers m and n as input and
 * returns the head of the new linked list after reversing the
 * nodes from position m to n.
 *  
 * Expected Time Complexity: O(N)
 * Expected Auxiliary Space: O(1)
 *  
 * Constraints:
 * 1<=N<=10^5
 * 
 *//////////////////////////////////////////////////////////////
# include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Node {
    int data;
    Node* next;
    Node( int x) {
        data = x;
        next = NULL;
    }
};
////////////////////////////////////////////////////////////////
void printList( Node *head) {
    Node *temp = head;
    while( temp != NULL) {
        printf( "%d ", temp->data);
        temp = temp->next;
    }
}
////////////////////////////////////////////////////////////////
class Solution {
    public:
    Node* reverseBetween( Node* head, int m, int n);
};
// Reverse the links of (count) nodes starting at (a), which
// is set to point to NULL, place at (*end) the (count+1)th
// node for post linking.
Node* revs( Node* a, int count, Node** end) {
    Node* prev = NULL;
    Node* next;
    for( int j = 0; j < count; j++) {
        next = a->next;
        a->next = prev;
        prev = a;
        a = next;
    }
    *end = next;
    return prev;
}
Node* Solution::reverseBetween( Node* p, int m, int n) {
    Node head = Node( 0);
    head.next = p;
    p = &head;
    for( int j = 1; j < m; j++) { // m - 1 times
        p = p->next;
    } // now p->next points to the mth node
    Node* end;
    Node* a = revs( p->next, n - m + 1, &end);
    // post linking
    p->next->next = end;
    p->next = a;
    return head.next;
}
// Test Cases Passed:  30 / 30
// Total Time Taken:  0.2 / 1.3
//////////////////////////////////////////////////// Driver Code
int main() {
    int T;
    cin >> T;

    while( T--) {
        int N, m, n;
        cin >> N >> m >> n;

        Node *head = NULL;
        Node *temp = head;

        for( int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if( head == NULL) {
                head = temp = new Node( data);
            } else {
                temp->next = new Node( data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node* newhead = ob.reverseBetween( head, m, n);
        printList( newhead);
        cout << "\n";
    }
}
////////////////////////////////////////////////////////////////
//
//
