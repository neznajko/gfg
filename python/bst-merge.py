########################################################
# Merge two BST's 
# Hard Accuracy: 50.0% Submissions: 28284 Points: 8
# Givn two BSTs(-Wait a minute, why there's no ' here as
# abov?), retrn elments of both BSTs in sorted form.
# 
# Example 1:
# Input:
# BST1:
#        5
#      /   \
#     3     6
#    / \
#   2   4  
# BST2:
#         2
#       /   \
#      1     3
#             \
#              7
#             /
#            6
# Output: 1 2 2 3 3 4 5 6 6 7
# Explanation: 
# After merging and sorting the
# two BST we get 1 2 2 3 3 4 5 6 6 7.
# Example 2:
# 
# Input:
# BST1:
#        12
#      /   
#     9
#    / \    
#   6   11
# BST2:
#       8
#     /  \
#    5    10
#   /
#  2
# Output: 2 5 6 8 9 10 11 12
# Explanation: 
# After merging and sorting the
# two BST we get 2 5 6 8 9 10 11 12.
# 
########################################################
# Your Task: U don't need to read nput vs. prnt anythng.
# Your tsk is to complete the functon merge() vich takes
# roots of both the BSTs as its nput and returns an rray
# of integers denotng the node valus of both the BSTs in
# a sorted order.
# 
# Expected Time Complexity: O(M+N) where M and N are the
# sizes if the two BSTs.
# Expected Auxiliary Space: O(Height of BST1 + Height of
# BST2).
#
# Constraints:
# 1 ≤ Number of Nodes ≤ 10**5
########################################################
from collections import deque
########################################################
class Node:
    def __init__( self, val):
        self.data  = val
        self.left  = None
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
# Not the most elegant and beautiful solution plus it is
# quite slow. Don't know how to make co-routines, and is
# it possible at all. Here, for every Binary Search Tree
# I'm making a class vit explicit stack and nod pointer,
# to keep track of the current inorder status,.
class Disorder:
    def __init__( self, T):
        self.P = T # Points to current node
        self.stk = [] # stack
        self.vlu = None # most recent value
        self.don = T == None
    def revint( self):
        while self.P:
            self.stk.append( self.P)
            self.P = self.P.left
        if not self.stk:
            self.don = True
            return
        self.P = self.stk.pop()
        self.vlu = self.P.data
        self.P = self.P.right
    def sort( self):
        ls = []
        while( not self.don):
            ls.append( self.vlu)
            self.revint()
        return ls        
########################################################
class Solution:
    def merge( self, root1, root2):
        ''''''
        u = Disorder( root1)
        v = Disorder( root2)
        u.revint()
        v.revint()
        ls = [] # result
        while True:
            if u.don: ls.extend( v.sort()); break
            if v.don: ls.extend( u.sort()); break
            if u.vlu <= v.vlu:
                ls.append( u.vlu)
                u.revint()
            else:
                ls.append( v.vlu)
                v.revint()
        return ls
########################################################
if __name__ == "__main__":
    t = int( input())
    for _ in range( 0, t):
        s1 = input()
        s2 = input()
        root1 = buildTree( s1)
        root2 = buildTree( s2)
        res = Solution().merge( root1, root2)
        for i in range( len( res)):
            print( res[i], end=" ")
        print()
########################### https://youtu.be/7bW75OwVXZI
# log: Test Cases Passed: 40/40
#      Total Time Taken:  5.7/7.2( boo)
########################################################

