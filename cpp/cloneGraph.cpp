                            ////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <map>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// Clone Graph
////////////////////////////////////////////////////////////////
// Given a reference of a node in a connected undirected graph.
// Return a clone of the graph. Each node in the graph contains
// a value (Integer) and a list (List[Node]) of its neighbors.
////////////////////////////////////////////////////////////////
struct Node {
    int           val;
    vector<Node*> neighbors;
    Node( int _val ){
        val       = _val;
        neighbors = vector<Node*>();
    }
};
////////////////////////////////////////////////////////////////
// Test Cases Passed: 203 / 203 I've lost all my day trying to
// Total Points Scored: 4 / 4   solve this one in Python, there
// Your Total Score: 946        is bug in the checking function
// Total Time Taken: 0.18       and in the Node constructor,
// Your Accuracy: 100%          never pass empty list as default
// Attempts No.: 1              argument.
////////////////////////////////////////////////////////////////
class Solution {
private:
    map<Node*, Node*> f;
public:
    Node* jeepcopy( Node* orig ){
        Node* copy = f[ orig ] = new Node( orig->val );
        for( auto nbor: orig->neighbors ){
            Node* nbor_copy =( f.count( nbor ) > 0 ? 
                               f[ nbor ] :
                               jeepcopy( nbor ));
            copy->neighbors.push_back( nbor_copy );
        }
        return copy;
    }
    Node* cloneGraph( Node* node ){
        return jeepcopy( node );
    }
};
////////////////////////////////////////////////////////////////
// log: -It seems the only thing I know is how to rise when down.
////////////////////////////////////////////////////////////////
int main() {
    cout << "muaha[ha]" << endl;
}
////////////////////////////////////////////////////////////////
////////                                                ////////
