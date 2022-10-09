////////////////////////////////////////////////////////////////
// Count BST nodes that lie in a given range
////////////////////////////////////////////////////////////////
// Given a Binary Search Tree (BST) and a range l-h (inclusive), 
// count the nmbr of nods in the BST that lie in the givn range.
//////////////////////////////////////////////////////////////// 
// Example:     1
// Input:           10
//                 /  \
//                5    50
//               /    /  \
//              1    40  100
//              l = 5, h = 45
// Output:      3
// Explanation: 5 10 40 are the node in the range
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of the BST).
////////////////////////////////////////////////////////////////
class Node
{
    public int data;
    public Node left;
    public Node right;
    public Node(int key)
    {
        this.data = key;
        this.left = null;
        this.right = null;
    }
}
////////////////////////////////////////////////////////////////
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
        void inorder(Node root){
            if(root==null) return;
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
                var str1 = Console.ReadLine().Trim().Split(' ');
                int l = int.Parse(str1[0]);
                int h = int.Parse(str1[1]);
                Solution obj = new Solution();
                var res = obj.getCount(root,l,h);
                Console.WriteLine(res);
            }
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 155 / 155 Ok ths problm's only 4 the count
// Total Points Scored: 4 / 4   be cos it's realy an easy one no
// Your Total Score: 862        complicated stuff traversing the
// Total Time Taken: 0.06       binary tree in inorder will give 
// Your Accuracy: 100%          sortd seq. Then just count nodes
// Attempts No.: 1              within [low, high] range.
////////////////////////////////////////////////////////////////
class Solution {
    int low;
    int high;
    int cnt = 0;
    void inorder( Node root ){
        if( root == null )return;
        inorder( root.left );
        if( root.data >= low && root.data <= high ){
            cnt++;
        }
        inorder( root.right );
    }
    public int getCount( Node root, int low, int high ){
        this.low = low;
        this.high = high;
        inorder( root );
        return cnt;
    }
}
////////////////////////////////////////////////////////////////
// log: