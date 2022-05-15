////////--------........>>>>>>>>````````::::::::________********
////----,,,,````>>>>____;;;;----....''''""""----````    ,,,,>>>>
//  Delete  nodes   having  greater value   on  right
//
//  Medium  Accuracy:   37.92%  Submissions:57997   Points: 4
//  Given   a   singly  linked  list,   remove  all the     nodes
//  which   have    a   greater value   on  their   right   side.
// 
//  Example:    1
// 
//  Input:  LinkedList  =   12->15->10->11->5->6->2->3
//  Output: 15 11 6 3
//
//  Explanation:    Since,  12, 10, 5   and 2   are the elements
//  which   have    greater elements    on  the following   nodes.
//  So, after   deleting    them,   the linked  list    would
//  like    be  15, 11, 6,  3.
//
//  The task is to  complete    the function    compute()   which
//  should  modify  the list    as  required    and return  the
//  head    of  the modified    linked  list.   The printing
//  is  done    by  the driver  code,
//
//  Expected    Time    Complexity: O(N)
//  Expected    Auxiliary   Space:  O(1)
//
////----,,,,````>>>>____;;;;----....''''""""----````    ,,,,>>>> 
//  Constraints:
//  1   ≤   size    of  linked  list    ≤   1000
//  1   ≤   element of  linked  list    ≤   1000
////////////////////////////////////////////////////////////////
////----,,,,````>>>>____;;;;----....''''""""----````    ,,,,>>>> 
#   include <iostream>
using   namespace   std;
struct  Node    {
    int data;
    Node*   next;
    Node(   int x   ){
        data    =   x;
        next    =   NULL;
    }
};
////////////////////////////////////////////////////////////////
////----,,,,````>>>>____;;;;----....''''""""----````    ,,,,>>>> 
void    print(  Node*   root    ){
    Node*   temp    =   root;
    while(  temp    !=  NULL)   {
        cout    <<  temp->data  <<  " ";
        temp    =   temp->next;
    }
}
////////////////////////////////////////////////////////////////
////----,,,,````>>>>____;;;;----....''''""""----````    ,,,,>>>> 
class   Solution    {
public:
    Node*   compute(    Node*   head    );
};
////////////////////////////////////////////////////////////////
////----,,,,````>>>>____;;;;----....''''""""----````    ,,,,>>>>  
int main()  {
    int T;
    cin >>  T;
    while(  T-- ){
        int K;
        cin >>  K;
        struct  Node*   head    =   NULL;
        struct  Node*   temp    =   head;
        //
        for(    int     i   =   0;  i   <   K;  i++     ){
            int data;
            cin >>  data;
            if( head    ==  NULL    ){ 
                head =  temp    =   new Node(   data    );
            }   else {
                temp->next  =   new Node(   data    );
                temp    =   temp->next;
            }
        }
        Solution    ob;
        Node*   result  =   ob.compute(     head    );
        print(  result  );
        cout    <<  endl;
    }
}
////////////////////////////////////////////////////////////////
// Ok here we go, no alignment!
Node* f( Node* a ){
    if( a->next ){
        Node* p = f( a->next );
        if( p and p->data > a->next->data ){
            a->next = p;
        }
    }
    return a->next;
}
Node* Solution::compute( Node* head ){
    Node a( 0 );
    a.next = head;
    return f( &a );
}
////////////////////////////////////////////////////////////////
////----,,,,````>>>>____;;;;----....''''""""----````    ,,,,>>>> 
//  Test    Cases   Passed: 1076    /   1076
//  Total   Time    Taken:  0.22    /   1.6
////////////////////////////////////////////////////////////////
