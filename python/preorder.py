####### ####### ####### ####### ####### ####### ####### ####### 
#       Preorder        Traversal       and     BST
##### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### 
#   Given   an  array   arr[]   of  size    N   consisting  of
## # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# distinct  integers, write a program that  returns 1 if  given 
############### ############### ############### ############### 
#             array           can             represent
#### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### 
#    preorder    traversal   of  a   possible    BST,    else
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
#  returns 0.
################################################################
# Example: 2          Explaination: 2    This is not BST because
# Input: {2, 4, 1}                   \      1 < 2, and is in the
# Output: 0                           \           right sub-tree.
#                                      4
#                                     /
#                                    1
################################################################
# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(N)
################################################################
# Constraints:
# 1 ≤ N      ≤ 10^5
# 0 ≤ arr[i] ≤ 10^5
################################################################
# 1                 a               # abdh i ej k cfl m gn o
# 2                / \              # 
# 3               /   \             # In this lecture we are going
# 4              /     \            # to talk about preorder baby,
# 5             /       \           # Y/n and BST, joking of course.
# 6            /         \          # Don't know, OK binary tree is
# 7           /           \         # defined recursively like having
# 8          /             \        # a root and a left and ryte
# 9         b               c       # binary sub-trees, something
# a        / \             / \      # like thus. Binary Search Tree
# b       /   \           /   \     # is a Binary Tree with the 
# c      /     \         /     \    # property that all nodes in
# d     d       e       f       g   # the left sub-tree are smaller
# e    / \     / \     / \     / \  # then the root and all nodes
# f   h   i   j   k   l   m   n   o # in the ryte sub-tree are bigger
##################################### zo thats why
# 2    is not a BST; in the ryte sub-tree 4, 1 is smaller than 2
#  \                                     /
#   \                                   1
#    4 Preorder is again defined recursively with something like
#   /  def preorder( root ):   Zo ve basically traverse, but not
#  1     if not root: return   with bus, all the left branches
#        dump( root )          untill we hit the void, than we
#        preorder( root.left ) jump to the most recent non None
#        preorder( root.ryte ) ryte branch etc.
# In the above tree the preorder is written in groups which
# indicate vhere we jump to a ryte branch:
# abdh i ej k cfl m gn o, because of the BST property for all
# nodes whitin a group we'll have the relations a>b>d>h etc.
# and vheneva we have something like h<i in the array that means
# a ryte branch jump. The idea of the algorithm is to use stack
# for tracking parent nodes and vheneva a node from new group is
# detected to figure it's parent, than all nodes in this group
# should be bigger than parent's bound.
################################################################
from math import inf
################################################################
class Solution:
    def canRepresentBST( self, a, n ):
        bound = -inf
        pare = [ a[ 0 ]] # parent stack
        for j in range( 1, n ):
            if a[ j ] < a[ j - 1 ]:
                if a[ j ] < bound: return 0
            else:
                while True:
                    bound = pare.pop()
                    if not pare or pare[ -1 ] > a[ j ]: break
            pare.append( a[ j ])
        return 1
################################################################
# Test Cases Passed: 1045 / 1045
# Total Points Scored: 4 / 4
# Your Total Score: 978
# Total Time Taken: 0.18
# Your Accuracy: 100%
# Attempts No.: 1
################################################################
a = [ 2, 4, 1 ]
print( Solution().canRepresentBST( a, len( a )))
################################################################
