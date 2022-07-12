////////////////////////////////////////////////////////////////
// T o p   V i e w   o f   B i n a r y   T r e e 
// M e d i u m   A c c u r a c y :   3 2 . 3 %   S u b m i s s i
// o n s :   1 0 0 k +   P o i n t s :   4
////////////////////////////////////////////////////////////////
// G | i | v | e | n |   | b | e | l | o | w |   | i | s |   | a
// b | i | n | a | r | y |   | t | r | e | e | . | T | h | e | 
// t | a | s | k |  is to print the top view of binary tree. Top
// view of a binary tree is the set of nods visble when the tree
// is vewed  | f | r | o | m |   | t | h | e |   | t | o | p | .
// F | o | r |   | t | h | e |   | g | i | v | e | n |   | b | e
// l | o | w |   | t | r | e | e | :
// 
//        1
//       / \
//      /   \
//     /     \
//    2       3
//   / \     / \
//  4   5   6   7
// 
// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node.
// 
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N).
// 
// Constraints: 1 ≤ N ≤ 10^5
////////////////////////////////////////////////////////////////
# include <vector>
# include <queue>
# include <string>
# include <sstream>
# include <iostream>
////////////////////////////////////////////////////////////////
using namespace std; //                              Driver Code
/////////////////////////////////////////////////////v//////////
struct Node { int data; Node* left; Node* right; };
////////////////////////////////////////////////////////////////
// Utility function to create a new Tree Node
Node* newNode( int val ){                 Node* temp = new Node;
    temp              ->                            data = val;;
               temp           ->                    left = NULL;
          temp                        ->           right = NULL;
                                                    return temp;
                        }
////////////////////////}///////////////////////////////////////
// Function to Build Tree
Node* buildTree( string str ){
    // Corner Case
    if(str.length()==0||str[0]=='N')return NULL;
    // Creating vector of strings from input
    // string after spliting by space
    vector<string>ip;istringstream iss(str);for(string str;iss>>
    str;)ip.push_back(str);
    // Create the root of the tree
    Node*root=newNode(stoi(ip[0]));
    // Push the root to the queue
    queue<Node*>queue;queue.push(root);
    // Starting from the second element
    int i=1;while(!queue.empty()&&i<ip.size()){
        // Get and remove the front of the queue
        Node*currNode=queue.front();queue.pop();
        // Get the current node's value from the string
        string currVal=ip[i];
        // If the left child is not null
        if(currVal!="N"){
            // Create the left child for the current node
            currNode->left=newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }
        // For the right child
        i++;if(i>=ip.size())break;currVal=ip[i];
        // If the right child is not null
        if (currVal!="N"){
            // Create the right child for the current node
            currNode->right=newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }i++;}return root;}
////////////////////////////////////////////////////////////////
class Solution { public: vector<int> topView( Node* root ); };
////////////////////////////////////////////////////////////////
int main() {
    ////____////____////____////    ////____////____====____````
    int tc; cin >> tc; cin.ignore( 256, '\n' );
    while( tc-- ){ string treeString; getline( cin, treeString );
        Solution ob; Node* root = buildTree( treeString );
        vector<int> vec = ob.topView( root ); for( int x : vec )
        cout << x << " "; cout << endl; }}
////////////////////////////////////////////////////////////////
// <--+--> x                   0        0 
//  - | +                     1 2       1
//    v y                    3 4 5      2
//                          6 7 8 9     3
//                         a b c d e    4
//                        f g h i j k   5
//                       l m n o p q r  6
//                      s t u v w x y z 7
//                      '|'|'|'|'|'|'|'
//                     -765432101234567+
//
// εὕρηκα: A node with a givn x will cover all others bellow it.
////////////////////////////////////////////////////////////////
# include <deque>
////////////////////////////////////////////////////////////////
// Ok, if the tree has N nodes, than it's easy to check that the
// number of levels is proportional to log(N), for N equals 10^5
// this is approximately 16. In our case the number of different
// x per level is 1 + level( for the above picture level 7 has 8
// nodes from s to z). TABSIZ is the maximum displasement from 0
// which is something like log(N) / 2. For positive and negative
// coors there are separate hash tables namely pos and neg.
constexpr int TABSIZ = 10;
////////////////////////////////////////////////////////////////
struct Link//in Park
{
    Node* node;
    int   x;
};
////////////////////////////////////////////////////////////////
vector<int> Solution::topView( Node* root ){
// Test Cases Passed: 105 / 105
// Total Time Taken: 0.01 / 1.12
    // hash tables, initialized to false
    vector<bool> pos( TABSIZ );
    vector<bool> neg( TABSIZ );
    // the deque, negative x are pushed ahead, positive as usual
    deque<int> deq;
    // traveling level-wise using BFS queue
    queue<Link> q;
    q.push({ root, 0 });
    while(! q.empty()){
        const int n = q.size();
        for( int j = 0; j < n; j++ ){
            auto[ node, x ] = q.front(); // -std=c++17
            q.pop();
            if( x < 0 ){
                if( neg[-x] == false ){
                    neg[-x] = true;
                    deq.push_front( node->data );
                }
            } else {
                if( pos[x] == false ){
                    pos[x] = true;
                    deq.push_back( node->data );
                }
            }
            // push next generation to the queue
            if( node->left ){
                q.push({ node->left, x - 1 });
            }
            if( node->right ){
                q.push({ node->right, x + 1 });
            }
        }
    }
    return vector<int>( deq.begin(), deq.end() );
}
////////////////////////////////////////////////////////////////
