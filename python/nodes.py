#!                                  /usr/bin/env python3
########################################################
# Nodes at given distance in binary tree               
########################################################
# Given a binary tree, a target node in the binary tree, 
# and an integer value k, find all the nodes that are at
# distance k from the given target node. No parent pntrs
# are available.
########################################################
# Example 1, Input: 20 8 22 4 12 N N N N 10 14
#                   8
#           20      2
#         /    \                     []
#       8       22             1     [2,7]
#     /   \                   / \    [1,3,4]
#    4    12                 2   7   [2]
#        /   \              / \      [2,5,6]
#       10    14           3   4     [4]
#                             / \    [4]
# Target Node = 8            5   6   [1]
# K = 2
# Output: 10 14 22
# Explanation: The three nodes at distance 2
# from node 8 are 10, 14, 22.
#
# Example 2, Input: 20 7 24 4 3 N N N N 1
#                   7
#          20       2
#        /    \
#       7      24
#     /   \
#    4     3
#         /  
#        1
#
# Target Node = 7
# K = 2
# Output: 1 24
########################################################
# Your Task: You dn't need to read nput or prnt anythng.
# Complete the function KDistanceNodes() which takes the
# root of the tree, target, and K as nput parameters and
# returns a list of nodes at k distance from target in a
# sorted order.
########################################################
# Expected Time Complexity: O(N*logN)
# Expected Auxiliary Space: O(Height of tree)
########################################################
class Solution:
    def __init__( self):
        self.g = [ []] # graph in adjacency list format
        self.n = [ None] # nodes
    def KDistanceNodes( self, root, target, k):
        """ return d'sorted lst of all nodes at k dstnce
        from target """
        # make sure dfs gets non empty node
        if not root: return []
        self.g[ 1:] = []     # clear graph
        self.n[ 1:] = []     # clear nodes
        self.c = 0           # preorder node counter
        self.j = -1          # target node
        self.target = target # target value
        self.dfs( root, 0)   # build graph and stuff
        # make sure target exist
        if self.j == -1: return []
        # discard 0-1 edge
        self.g[ 0].remove( 1)
        self.g[ 1].remove( 0)
        return  self.bfs( k)
########################################################    
    def dfs( self, node, pare):
        self.c += 1 # node's name
        self.n.append( node) # preorder
        # ck if target
        if node.data == self.target: self.j = self.c
        # add graph edges
        self.g.append([ pare])
        self.g[ pare].append( self.c)
        pare = self.c
        if node.left:  self.dfs( node.left,  pare)
        if node.right: self.dfs( node.right, pare)
########################################################
    def bfs( self, k):
        deq = deque([ self.j]) # starting node
        vzd = [ False]*len( self.n) # visited
        for i in range( k):
            deqlen = len( deq)
            for j in range( deqlen):
                u = deq.popleft()
                vzd[ u] = True
                for v in self.g[ u]:
                    if not vzd[ v]: deq.append( v)
        return sorted([ self.n[ v].data for v in deq])
########################################################
from collections import deque
########################################################
class Node:
    def __init__( self, val):
        self.data = val
        self.left = None
        self.right = None
####################################### driver code ####
def buildTree( s): # 20 7 24 4 3 N N N N 1
    if not s or s[ 0] == "N": return None
    # Creating list of strings from input string after
    # spliting by space
    ip = s.split()
    # Create the root of the tree
    root = Node( int( ip[ 0]))
    size = 0
    q = deque()
    # Push the root to the queue
    q.append( root)
    # Starting from the second element
    i = 1
    while q:
        # Get and remove the front of the queue
        currNode = q.popleft()
        # Get the current node's value from the string
        currVal = ip[ i]
        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node( int( currVal))
            # Push it to the queue
            q.append( currNode.left)
        # For the right child
        i += 1
        if i >= len( ip): break
        currVal = ip[ i]
        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node( int( currVal))
            # Push it to the queue
            q.append( currNode.right)
        i += 1
        if i >= len( ip): break
    return root
########################################################
if __name__ == "__main__":
    x = Solution()
    t = int( input())
    for _ in range( t):
        line = input()
        target = int( input())
        k = int( input())
        root = buildTree( line)
        res = x.KDistanceNodes( root, target, k)
        for i in res:
            print( i, end=' ')
        print()
########################################################
# log: - C7eg npoMsHaTa 3e7eHoTo me cuMBo7u3upa 4opanuTe
# Ha pageB, a He pa6oTHoTo Hace7eHue! uFo-neTpoB urpa 7u
# xopoTo Ha no6egaTa?
########################################################
