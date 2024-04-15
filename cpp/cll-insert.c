//////////////////////////////////////////////////////////////// 
//`  `` `  `  `  `  `  `  `          .`  .`  .`  .`  .`  .`  .`  校
// `  ```  `  `  `  `  `  `        .`  .`  .`  .`  .`  .`  .`  .
//  `  ``  `  `  `  `  `  `      .`  .`  .`  .`  .`  .`  .`  .` 
//`  `  `` `  `  `  `  `  `    .`  .`  .`          .`  .`  .`  .
// `  `  ```  `     `  `  `  .`  .`  .`  .       .`  .`  .`  .` 
//  `  ` ```  `     `  `  `                                    .
//`  `  `                 `  .   .   .   .   .   .   .   .   .` 
// `  ` `` ````     `  `  `            |           , , , , , , ,        
//  `  `  `  ``     `                |   |       ,   , , , , , ,
//`  `  `  `  `       `            |   | |         ,   , , , , ,
// `  `  `  `           `        |   | | .       .   ,   , , , ,
//  `  `  `         `     `      | | | .   .   .   .   , , , , ,
//   `  `     `     ` `     `    | | | | .   .   .       mischen
//    `     ` `     `   `        | | | | | .   .                
//     `  `   `     ` m          | | | | .   .   .              
//      `     `     ` e          | | | .   .   .   .            
//            `     ` z          | | .   .       .   .          
//            `     ` c        . '     . |         .    '  .    
//            `     ` l          .   . | |           .   .      
//            `  `  ` a          | | | | |                      
//    m  e  s  c  o  l  a  r  e  | | | | |                      
//                               | | | | | m é l a n g e r      
//////////////////////////////////////////////////////////////// コウ
// Sorted insert for circular linked list, 
////////////////////////////////////////////////////////////////
// Given a sorted circular linked list of length n, the task is
// to insert a new node in this circular list so that it remains
// a sorted circular linked list
////////////////////////////////////////////////////////////////
// Input: n = 3 LinkedList = 1->2->4 (the first and last node is
// connected, i.e. 4 --> 1) data = 2 Output: 1 2 2 4
// Explanation: We can add 2 after the second node.
////////////////////////////////////////////////////////////////
// Input: n = 4 LinkedList = 1->4->7->9 (the first and last node 
// is connected, i.e. 9 --> 1) data = 5 Output: 1 4 5 7 9
// Explanation: We can add 5 after the second node
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// 0 <= n <= 10^5
////////////////////////////////////////////////////////////////
# include <stdio.h>
# include <stdlib.h>
////////////////////////////////////////////////////////////////
struct Node{int data;struct Node*next;};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
struct Node *get_tail( struct Node *ahead ){
    struct Node *p = ahead;
    while( p->next != ahead ){
        p = p->next;
    }
    return p;
}
void insert_coin( struct Node *p, struct Node *q ){ // p -> q
    q->next = p->next;
    p->next = q;
}
struct Node *cons( int data ){
    struct Node *p = malloc( sizeof *p );
    p->data = data;
    p->next = p;
    return p;
}
////////////////////////////////////////////////////////////////
struct Node *sortedInsert( struct Node *ahead, int data ){
    // there is a problem in the c driver it can't handle null
    // lists, so i had to insert thus and use the c++ code
    if( ahead == NULL ){
        return cons( data );
    }
    struct Node *tail = get_tail( ahead );
    struct Node *coin = cons( data );
    if( data <= ahead->data ){
        insert_coin( tail, coin );
        return coin;
    }
    if( data >= tail->data ){
        insert_coin( tail, coin );
        return ahead;
    }
    struct Node *p = ahead;
    while( p->next->data < data ){
        p = p->next;
    }
    insert_coin( p, coin );
    return ahead;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void printList(struct Node*node){struct Node*temp=node;if(node!=
NULL){do{printf("%d ",temp->data);temp=temp->next;}while(temp!=
node);}	printf("\n");}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){int t;scanf("%d",&t);while(t--){int n;scanf("%d",&n);
int first;scanf("%d",&first);struct Node*head;head=(struct Node*
)malloc(sizeof(struct Node));head->data=first;head->next=NULL;
struct Node*tail=head;for(int i=1;i<n;++i){int data;scanf("%d", 
&data);struct Node*temp;temp=(struct Node*)malloc(sizeof(struct
Node));temp->data=data;temp->next=NULL;tail->next=temp;tail=tail
->next;}tail->next=head;int data;scanf("%d",&data);head=
sortedInsert(head, data);printList(head);}return 0;}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1120 / 1120
// Points Scored:                                          4 / 4
// Your Total Score:                                        1738 
// Time Taken:                                              0.06
