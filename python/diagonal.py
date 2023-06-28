###############################################################_
# Test Cases Passed:                                     60 / 60
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1150
# Total Time Taken:                                         0.69
################################################################
from collections import deque
###############################################################=
class Solution:
    def diagonal( self, root ):
        if not root: return ()
        ls = []
        deq = deque([ root ])
        while deq:
            node = deq.popleft()
            while node:
                ls.append( node.data )
                if node.left:
                    deq.append( node.left )
                node = node.right
        return ls
################################################################
class Node:
    def __init__( self, val ):
        self.right = None
        self.data = val
        self.left = None
###############################################################=
def buildTree( s ):
    if(len(s)==0 or s[0]=="N"): return None
    ip=list(map(str,s.split()));root=Node(int(ip[0]));size=0
    q=deque();q.append(root);size=size+1;i=1                                       
    while(size>0 and i<len(ip)):
        currNode=q[0];q.popleft();size=size-1
        currVal=ip[i]
        if(currVal!="N"):
            currNode.left=Node(int(currVal))
            q.append(currNode.left);size=size+1
        i=i+1
        if(i>=len(ip)): break
        currVal=ip[i]
        if(currVal!="N"):
            currNode.right=Node(int(currVal))
            q.append(currNode.right); size=size+1
        i=i+1
    return root
################################################################    
if __name__=="__main__":
    root=buildTree( "8 3 10 1 6 N 14 N N 4 7 13 N" )
    obj=Solution()
    diagonalNode = obj.diagonal(root)
    for node in diagonalNode:
        print(node,end=' ')
################################################################
# Diagonal Traversal of Binary Tree
################################################################
# Given a Binary Tree, print the diagonal traversal of the
# binary tree.
###############################################################=
# Example: 1
# Input: 8 3 10 1 6 N 14 N N 4 7 13 N
#             8                         8---10-------14
#            / \                        |             |
#           /   \                       3---6---7    13
#          /     \                      |   |
#         3      10                     1   4
#        / \       \                    If we rotate the tree
#       1   6      14                   we'll get thus.
#          / \     /
#         4   7  13
# Output: 8 10 14 3 6 7 13 1 4
################################################################
# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(N)
###############################################################_
