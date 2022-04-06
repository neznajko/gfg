////////////////////////////////////////////////////////////////
// Binary Tree to CDLL 
// Medium Accuracy: 55.09% Submissions: 19282 Points: 4
// 
// Lamp Geeks Summer Carnival is LIVE NOW
//
// Given a Binary Tree of N edges. The task is to convert this
// to a Circular Doubly Linked List(CDLL) in-place. The left and
// right pointers in nodes are to be used as previous and next
// pointers respectively in converted CDLL. The order of nodes
// in CDLL must be same as Inorder of the given Binary Tree. The
// first node of Inorder traversal (left most node in BT) must
// be head node of the CDLL.
// 
// Example 1:// 
// Input:
//       1
//     /   \
//    3     2
// Output:
// 3 1 2 
// 2 1 3
// Explanation: After converting tree to CDLL when CDLL is is
// traversed from head to tail and then tail to head, elements
// are displayed as in the output.  Example 2:
// 
// Input:
//      10
//    /    \
//   20    30
//  /  \
// 40  60
// Output:
// 40 20 60 10 30 
// 30 10 60 20 40
//
// Explanation:After converting tree to CDLL, when CDLL is is
// traversed from head to tail and then tail to head, elements
// are displayed as in the output.
//
// Your Task: You don't have to take input. Complete the
// function bTreeToCList() that takes root as a parameter and
// returns the head of the list. The printing is done by the
// driver code.
// 
// Constraints:
// 1 <= N <= 103
// 1 <= Data of a node <= 104
// 
// Expected time complexity: O(N)
// 
// Expected auxiliary space: O(h) , where h = height of tree
////////////////////////////////////////////////////////////////
# include <iostream>
# include <queue>
# include <sstream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Node {                                     // Driver Code
    int   data;
    Node* left;
    Node* right;
};
////////////////////////////////////////////////////////////////
Node* newNode( int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
////////////////////////////////////////////////////////////////
void displayCList( Node *head)
{
    Node *itr = head;
    do {
        cout << itr->data << " ";
        itr = itr->right;
    } while ( head != itr);
    cout << endl;
    itr = itr->left;
    do {
        cout << itr->data << " ";
        itr = itr->left;
    } while( head != itr);
    cout << itr->data << endl;
}
////////////////////////////////////////////////////////////////
Node* buildTree( string str) {
    // Corner Case
    if( str.length() == 0 || str[ 0] == 'N') {
        return NULL;
    }
    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss( str);
    for( string str; iss >> str; )
        ip.push_back( str);

    // Create the root of the tree
    Node* root = newNode( stoi( ip[ 0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push( root);

    // Starting from the second element
    int i = 1;
    while( !queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[ i];

        // If the left child is not null
        if( currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode( stoi( currVal));

            // Push it to the queue
            queue.push( currNode->left);
        }
        // For the right child
        i++;
        if( i >= ip.size()) break;
        
        currVal = ip[ i];

        // If the right child is not null
        if( currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode( stoi( currVal));

            // Push it to the queue
            queue.push( currNode->right);
        }
        i++;
    }
    return root;
}
////////////////////////////////////////////////////////////////
Node* mosleft( Node* p ){ 
    while( p->left ) p = p->left;
    return p;    
}
////////////////////////////////////////////////////////////////
Node* mosryte( Node* p ){
    while( p->right ) p = p->right;
    return p;    
}
////////////////////////////////////////////////////////////////
void relink( Node* p ){
    if( !p ) return; //
    relink( p->left );
    relink( p->right );
    if( p->left ){
        Node* q{ mosryte( p->left )};
        q->right = p;
        p->left = q;
    }
    if( p->right ){
        Node* q{ mosleft( p->right )};
        q->left = p;
        p->right = q;
    }
}
////////////////////////////////////////////////////////////////
class Solution {
public:
    Node* bTreeToCList( Node* root );
};
// Test Cases Passed:  299 / 299
// Total Time Taken:  0.11 / 1.17
////////////////////////////////////////////////////////////////
Node* Solution::bTreeToCList( Node* root ){
    relink( root );
    Node* p{ mosleft( root )};
    Node* q{ mosryte( root )};
    p->left = q;
    q->right = p;
    return p;
}
////////////////////////////////////////////////////////////////
int main() {
    int t;
    string tc;
    getline( cin, tc);
    t = stoi( tc);
    while( t--) {
        string s;
        getline( cin, s);
        Node* root = buildTree( s);
        Solution obj;
        Node *head = obj.bTreeToCList( root);
        if( head ) displayCList( head);
    }
}
////////////////////////////////////////////////////////////////
