////////////////////////////////////////////////////////////////
/* Intersection Point in Y Shapped Linked Lists 
 * Medium Accuracy: 49.55% Submissions: 100k+ Points: 4
 *
 * Given two singly linked lists of size N and M, write a
 * program to get the point where two linked lists intersect
 * each other.
 /////////////////////////////////////////////////////////////// 
 Example: 1
 Input:
 LinkList1 = 3->6->9->common
 LinkList2 = 10->common
 common = 15->30->NULL
 Output: 15
 ///////////////////////////////////////////////////////////////
 Example: 2
 Input: 
 Linked List 1 = 4->1->common
 Linked List 2 = 5->6->1->common
 common = 8->4->5->NULL
 Output: 8
////////////////////////////////////////////////////////////////
Your Task: You don't need to read input or print anything. The
task is to complete the function intersetPoint() which takes the
pointer to the head of linklist1(head1) and linklist2(head2) as
input parameters and returns data value of a node where two
linked lists intersect. If linked list do not merge at any
point, then it should return -1.  Challenge : Try to solve the
problem without using any extra space.
////////////////////////////////////////////////////////////////
Expected Time Complexity: O(N + M)
Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
Constraints:
1 ≤ N + M ≤ 2*10^5
-1000 ≤ value ≤ 1000
*///////////////////////////////////////////////////////////////
# include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Node {
int data;
Node* next;
Node( int x ){
data = x;
next = NULL;
}
};
////////////////////////////////////////////////////////////////
int intersectPoint( Node* head1, Node* head2 );
Node* inputList( int size ){        if( size == 0 ) return NULL;
                                                        int val;
                                                     cin >> val;
                                   Node* head = new Node( val );
                                              Node* tail = head;
                            for( int i = 0; i < size - 1; i++) {
                                                     cin >> val;
                                   tail->next = new Node( val );
                                              tail = tail->next;
                                                               }    
                                                    return head;
}
////////////////////////////////////////////////////////////////
int main()                                                     {
                                              int T, n1, n2, n3;
                                                       cin >> T;
                                                   while( T-- ){
                                          cin >> n1 >> n2 >> n3;
                                 Node* head1  = inputList( n1 );
                                 Node* head2  = inputList( n2 );
                                 Node* common = inputList( n3 );
                                             Node* temp = head1;
                    while( temp != NULL && temp->next != NULL ){
                                              temp = temp->next;
                                                               }
                         if( temp != NULL ) temp->next = common;
                                                   temp = head2;
                    while( temp != NULL && temp->next != NULL ){
                                              temp = temp->next;
                                                               }
                          if( temp != NULL) temp->next = common;
                 cout << intersectPoint( head1, head2 ) << endl;
                                                               }
                                                               }
////////////////////////////////////////////////////////////////
//  head1 = 3->6->9->15->30->NULL
//  head2 =      10->15->30->NULL
// - What if reverse the two lists and loop until their values
// are same?
// This is not going to work becus both lists aren't independent
// 3             - Ok what if revrse only one of them and attach
//  6            its tail to the head of the other. Then use the
//   9           Floyd cycle detection algorithm.
//    15 30 NULL 3->6->9->15->30->NULL
//  10           10->15->30->NULL will become
//
// NULL < 3 < 6 < 9 < 15 < 30 ->  3 < 6 < 9 < 15 < 30
//                     ^          |            ^
//                    10          +---------> 10
Node* revs( Node* list ){
    Node* prev = NULL,
        * cure = list;
    while( cure ){
        Node* next = cure->next;
        cure->next = prev;
        prev = cure;
        cure = next;
    }
    return prev;
}
Node* makeLoop( Node* p, Node* q ){
    Node* r = revs( p );
    // Here p is at the tail.
    p->next = q;
    return r;
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 192 / 192
// Total Time Taken: 0.52 / 1.6
//                                                              
// * - fast pointer   
// ø - slow pointer
//
//         7    Some notes about the Floyd Cycle Detection
//        / \   Algorithm, both pointers start from 1 but the
// 1-2-3-4   6  fast pointer goes 1-3-5-7-5-7-..., whether the
//        \ /   slow goes 1-2-3-4-5-6-7-4-5-6-..., now let's                                                  
//         5    speak abstractly when the slow pointer enters                                               
//              the cycle, let's say the position of the fast                                                
//         7    is at 5:                                                
//        / \                                                   
// 1-2-3-ø   6  ,and let's say they meet at 7, marked with x:                                                         
//        \ /                                                   
//         *
//         x    ,than we let go both pointers cycle and ask
//        / \   when the slow pointer appears at 4 where the
// 1-2-3-4   6  fast will be?
//        \ /
//         5
//         7    a) 5
//        / \   
// 1-2-3-ø   6  b) 6
//        \ /
//         5    c) 7
// becoz there is repetitions and we've already got the same
// configuration at the second figure the right answer is a) 5
// which means that the time required for the slow pointer to go
// from the point where both pointers meet to the cycle origin
// is the same as the time required to go from the beginning of
// the list to the ORIG. And that explains the logic behind the
// detach function.
////////////////////////////////////////////////////////////////
Node* detach( Node* head, Node* s ){
    if( head == s ){
        while( head != s->next ){
            s = s->next;
        }
    } else {
        while( head->next != s->next ){
            head = head->next;
            s = s->next;
        }
    }
    return s->next;
}
Node* cycleDetection( Node* head ){
////----////----////----\\\\,,,,````----////____````____,,,,----
    Node* f{ head };
    Node* s{ head };
    while( f and f->next ){
        s = s->next;
        f = f->next->next;
        if( s == f ) break;
    }
    return detach( head, s );
}
int intersectPoint( Node* p, Node* q ){
    return cycleDetection( makeLoop( p, q ))->data;
}
////////////////////////////////////////////////////////////////
