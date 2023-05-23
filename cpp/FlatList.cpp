////////////////////////////////////////////////////////////////
// Flattening a Linked List ====================================
////////////////////////////////////////////////////////////////
// Given a Linked List of size N, where every node represents a 
// sub-linked-list and contains two pointers: ==================
// (i) a next pointer to the next node, ========================
// (ii) a bottom pointer to a linked list where this node is ===
// head. =======================================================
// Each of the sub-linked-list is in sorted order. Flatten the =
// Link List such that all the nodes appear in a single level ==
// while maintaining the sorted order. =========================
////////////////////////////////////////////////////////////////
// Note: The flattened list will be printed using the bottom --- 
// pointer instead of the next pointer. ------------------------
////////////////////////////////////////////////////////////////
// Example 1: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Input: 5 -> 10 -> 19 -> 28 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        |     |     |     | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        7     20    22   35 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        |           |     | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
//        8          50    40 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
//        |                 |   ~   ~   ~   ~   ~   ~   ~   ~   ~
//        30               45  ~    ~    ~    ~    ~    ~    ~    ~
// Output: 5->7->8->10->19->20->22->28->30->35->40->45->50. ====
// Explanation: yok ============================================
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N*N*M) __________________________
// Expected Auxiliary Space: O(1) ______________________________
////////////////////////////////////////////////////////////////
# include <cstdio>
# include <iostream>
////////////////////////////////////////////////////////////////
struct Node {
    const int data;
    struct Node * next{};
    struct Node * bottom{};
    Node( int data ): data( data ){}
};
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
Node * flatten( Node* root );
////////////////////////////////////////////////////////////////
void printList( Node * node ){
    for(; node; node = node->bottom ){
        printf( "%d ", node->data );
    }
}
////////////////////////////////////////////////////////////////
int main(){int n,m,flag=1,flag1=1;struct Node*temp=NULL;
struct Node*head=NULL;struct Node*pre=NULL;
struct Node*tempB=NULL;struct Node*preB=NULL;cin>>n;
int*work=new int[n];for(int i=0;i<n;i++)cin>>work[i];
for(int i=0;i<n;i++){m=work[i];--m;int data;scanf_s("%d",&data);
temp=new Node(data);temp->next=NULL;temp->bottom=NULL;if(flag){
head=temp;pre=temp;flag=0;flag1=1;}else{pre->next=temp;pre=temp;
flag1=1;}for(int j=0;j<m;j++){int temp_data;
scanf_s("%d",&temp_data);tempB=new Node(temp_data);if(flag1){
temp->bottom=tempB;preB=tempB;flag1=0;}else{preB->bottom=tempB;
preB=tempB;}}}Node*fun=head;Node*fun2=head;
Node*root=flatten(head);printList(root);cout<<endl;}
////////////////////////////////////////////////////////////////
// This should be an insertion sort.
////////////////////////////////////////////////////////////////
Node ahead( 0 );
////////////////////////////////////////////////////////////////
# define bot bottom
////////////////////////////////////////////////////////////////
Node * InsertCoin( Node * node ){
    auto p{ &ahead };
    for(; p->bot and ( p->bot->data < node->data ); p = p->bot ){
    }
    auto copy{ node->bot };
    node->bot = p->bot;
    p->bot = node;
    return copy;
}
////////////////////////////////////////////////////////////////
Node * flatten( Node * root ){
    if( !root ){
        return root;
    }
    ahead.bot = root;
    for( auto q{ root->next }; q; q = q->next ){
        for( auto p{ q }; p; p = InsertCoin( p )){
        }
    }
    return ahead.bot;
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  126 / 126
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1114
// Total Time Taken:                                        0.01
////////////////////////////////////////////////////////////////
