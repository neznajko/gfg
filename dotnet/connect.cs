////////////////////////////////////////////////////////////////
// Connect Nodes at Same Level
////////////////////////////////////////////////////////////////
// Given a binary tree, connect the nodes that are at same levl. 
// You'll be given an addition nextRight pointer for the same.
//
// Initially, all the nextRight pointers point to garbage valus. 
// Your function shld set these pointers to point next right for
// each node.
//
//        10                 10----------> NULL
//       / \                /  \
//      3   5      =>      3--->5--------> NULL
//     / \   \            / \    \
//    4   1   2          4-->1--->2------> NULL
// 
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
////////////////////////////////////////////////////////////////
// Constraints:
// 1 <= Number of nodes <= 10^5
// 0 <= Data of a node  <= 10
////////////////////////////////////////////////////////////////
using System.Collections.Generic;
////////////////////////////////////////////////////////////////
class Node
{
    public int  data;
    public Node left;
    public Node right;
    public Node nextRight;

    public Node(int key)
    {
        this.data = key;
        this.left = null;
        this.right = null;
        this.nextRight = null;
    }
}
namespace DriverCode
{
    class GFG
    {
        public Node buildTree(string str)
        {
            if (str.Length == 0 || str[0] == 'N')
                return null;
            var ip = str.Split(' ');
            Node root = new Node(int.Parse(ip[0]));
            Queue<Node> queue = new Queue<Node>();
            queue.Enqueue(root);
            int i = 1;
            while (queue.Count != 0 && i < ip.Length)
            {
                Node currNode = queue.Peek();
                queue.Dequeue();
                string currVal = ip[i];
                if (currVal != "N")
                {
                    currNode.left = new Node(int.Parse(currVal));
                    queue.Enqueue(currNode.left);
                }
                i++;
                if (i >= ip.Length)
                    break;
                currVal = ip[i];
                if (currVal != "N")
                {
                    currNode.right = new Node(int.Parse(currVal));
                    queue.Enqueue(currNode.right);
                }
                i++;
            }
            return root;
        }
        void printSpecial(Node root)
        {
            if (root == null)
                return;
            Node next_root=null;
            while (root != null)
            {
                Console.Write(root.data + " ");
                if( root.left !=null && next_root == null )
                    next_root = root.left;
                else if( root.right!=null && next_root==null  )
                    next_root = root.right;
                root = root.nextRight;
            }
            printSpecial(next_root);
        }
        void inorder(Node root)
        {
            if (root == null)
                return;
            inorder(root.left);
            Console.Write(root.data + " ");
            inorder(root.right);
        }
        static void Main(string[] args)
        {
            int testcases;
            testcases = Convert.ToInt32(Console.ReadLine());
            while (testcases-- > 0)
            {
                var gfg = new GFG();
                var str = Console.ReadLine().Trim();
                var root = gfg.buildTree(str);
                Solution obj = new Solution();
                obj.connect(root);
                
                gfg.printSpecial(root);
                Console.WriteLine();
                gfg.inorder(root);
                Console.WriteLine();
            }
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 149 / 149 Here we hv to walk BFS style and 
// Total Points Scored: 4 / 4   at the same time link nodes with 
// Your Total Score: 842        equal levels. It's not difficult 
// Total Time Taken: 1.41       problem, more of a technical one 
// Your Accuracy: 100%          but it's a good pick if you want
// Attempts No.: 1              to relax and having good time.
////////////////////////////////////////////////////////////////
class Solution
{
    public void connect( Node root)
    {
// prologue *
//* setup the BFS queue
        var queue = new Queue<Node>();
        queue.Enqueue( root);
//* make a head node for convenience
        var head = new Node(-1);
// action =
//= loop until dawn
        while( queue.Count > 0) {
//== initialize previous node
            var prev = head;
//== capture current queue size
            int n = queue.Count;
//== loop over first n nodes
            for( int j = 0; j < n; j++) {
//=== pop up first node and set to cure
                Node cure = queue.Peek();
                queue.Dequeue();
//=== link prev to cure
                prev.nextRight = cure;
//=== Enqueue children nodes
//==== check the left
                if( cure.left != null) {
                    queue.Enqueue( cure.left);
                }
//==== check the ryte
                if( cure.right != null) {
                    queue.Enqueue( cure.right);
                }
//=== Update prev with cure
                prev = cure;
            }
//== link last node to null
            prev.nextRight = null;
        }
// epilogue ,
//, Finish 
    }
}
////////////////////////////////////////////////////////////////
// log:
