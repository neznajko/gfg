################################################################
# Lowest Common Ancestor in a Binary Tree Given a Binary Tree
# with all unique values and two nodes value, n1 and n2. The
# task is to find the lowest common ancestor of the given two
# nodes. We may assume that either both n1 and n2 are present in
# the tree or none of them are present.
################################################################
# LCA: It is the first common ancestor of both the nodes n1 and
# n2 from bottom of tree.
################################################################
# Example: 2
# Input: n1 = 3 , n2 = 4
#            5    
#           /    
#          2  
#         / \  
#        3   4
# Output: 2
# Explanation: LCA of 3 and 4 is 2. 
################################################################
# Expected Time Complexity:O(N).
# Expected Auxiliary Space:O(Height of Tree).
################################################################
# Constraints:
# 1 ≤ Number of nodes ≤ 10^5
# 1 ≤ Data of a node ≤ 10^5
################################################################
from collections import deque
################################################################
class Node:
    def __init__( self, val):
        self.data = val
        self.left = None
        self.right = None
################################################################
def buildTree( s):
    if( len( s) == 0 or s[0] == "N"): return None
    ip = list( map( str,s.split()))
    root = Node( int( ip[0]))                     
    size = 0
    q = deque()
    q.append( root)                            
    size = size + 1 
    i = 1                                       
    while( size > 0 and i < len( ip)):
        currNode = q[0]
        q.popleft()
        size = size - 1
        currVal = ip[i]
        if( currVal != "N"):
            currNode.left = Node( int( currVal))
            q.append( currNode.left)
            size = size + 1
        i = i + 1
        if( i >= len( ip)): break
        currVal = ip[i]
        if( currVal != "N"):
            currNode.right = Node( int( currVal))
            q.append( currNode.right)
            size = size + 1
        i = i + 1
    return root
################################################################
# Test Cases Passed: 1025 / 1025
# Total Points Scored: 4 / 4
# Your Total Score: 830
# Total Time Taken: 0.91
# Your Accuracy: 100%
# Attempts No.: 1
################################################################
class voilà( Exception): pass
################################################################
class Solution:
    def __init__( self):
        # ancestor stack during search
        self.aux = []
        
    def srch( self, root, val):
        if root == None: return
        self.aux.append( root )
        if root.data == val: raise voilà
        self.srch( root.left, val)
        self.srch( root.right, val)
        self.aux.pop()
    
    def lca( self, root, a, b ):
        try: self.srch( root, a) # savng space indentation style
        except voilà:
            anc = self.aux.copy()
            self.aux.clear()
            try: self.srch( root, b)
            except voilà: return lastcom( anc, self.aux)
        return Node(-1)
################################################################
def lastcom( a, b):
    '''Last"""common"""node'''
    n = min( len( a), len( b))
    j = 1
    while j < n and a[j] == b[j]: j += 1
    return a[j - 1]
################################################################
if __name__ == "__main__":
    t = int( input())
    for _ in range(t):
        a, b = list( map( int, input().split()))
        s = input()
        root = buildTree( s)
        k = Solution().lca( root, a, b)
        print( k.data)
###############################################################_
# log:
