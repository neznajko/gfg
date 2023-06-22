################################################################
# Test Cases Passed:                                     17 / 17
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1138
# Total Time Taken:                                         0.03
###############################################################%
from collections import deque
###############################################################-
class Solution:
    def isHeap( self, root ):
        deq = deque([ root ])
        expected_siz = len( deq )
        only_leafs = False # autumn leafs
        while len( deq ) == expected_siz:
            for _ in range( expected_siz ):
                node = deq.popleft()
                if node.left:
                    if only_leafs or node.left.data > node.data:
                        return False
                    deq.append( node.left )
                else:
                    only_leafs = True
                if node.right:
                    if only_leafs or node.right.data > node.data:
                        return False
                    deq.append( node.right )
                else:
                    only_leafs = True
            expected_siz <<= 1
        while len( deq ):
            node = deq.popleft()
            if node.left or node.right:
                return False
        return True
###############################################################_
#===============================================================
class Node:
    def __init__(self, val):
        self.right=None;self.data=val;self.left=None
###############################################################>        
def buildTree(s):
    if(len(s)==0 or s[0]=="N"):return None
    ip=list(map(str,s.split()));root=Node(int(ip[0]));size=0
    q=deque();q.append(root);size=size+1;i=1                                       
    while(size>0 and i<len(ip)):
        currNode=q[0];q.popleft();size=size-1;currVal=ip[i]
        if(currVal!="N"):
            currNode.left=Node(int(currVal))
            q.append(currNode.left);size=size+1;i=i+1
        if(i>=len(ip)):break
        currVal=ip[i]
        if(currVal!="N"):
            currNode.right=Node(int(currVal))
            q.append(currNode.right);size=size+1;i=i+1
    return root
###############################################################=
if __name__ == "__main__":
    root = buildTree( input())
    ob = Solution()
    print( int( ob.isHeap( root )))
###############################################################_
# Is Binary Tree Heap
######## ############################## ########################
#  Given# a binary tree. The task is to# check whether the given
####  ########  ###     ##### # ######    ####    #########  ###
# tr##ee follo##ws #####the m#a#x heap#### pro####perty or ##not.
################################################################
# Expected Time Complexity: O(N)
# Expected Space Complexity: O(N)
################################################################
