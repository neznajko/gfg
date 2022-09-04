################################################################
# Check if subtree
# Given two binary trees with head reference as T and S having
# at most N nodes. The task is to check if S is present as
# subtree in T. A subtree of a tree T1 is a tree T2 consisting
# of a node in T1 and all of its descendants in T1.
################################################################
# Input:
# T:      1          S:   3
#        / \             /
#       /   \           4
#      2     3          
#     / \   /
#    N   N 4
# Output: 1 
# Explanation: S is present in T
################################################################
# Expected Time Complexity: O(N).
# Expected Auxiliary Space: O(N).
################################################################
# Constraints:
# 1 <= Number of nodes <= 10^5
# 1 <= Value of nodes <= 10^4
################################################################    
from collections import deque
import sys; sys.setrecursionlimit( 1000000 )
################################################################
class Node:
    def __init__( self, val ):
        self.data = val
        self.left = None
        self.right = None
################################################################
def buildTree( s ):
    if( len( s ) == 0 or s[ 0 ] == "N" ):           
        return None
    ip = list( map( str, s.split()))
    root = Node( int( ip[ 0 ]))                     
    size = 0
    q = deque()
    q.append( root )                            
    size = size + 1 
    i = 1                                       
    while( size > 0 and i < len( ip )):
        currNode = q[ 0 ]
        q.popleft()
        size = size - 1
        currVal = ip[ i ]
        if( currVal != "N" ):
            currNode.left = Node( int( currVal ))
            q.append( currNode.left )
            size = size + 1
        i = i + 1
        if( i >= len( ip )): break
        currVal = ip[ i ]
        if( currVal != "N" ):
            currNode.right = Node( int( currVal ))
            q.append( currNode.right )
            size = size + 1
        i = i + 1
    return root    
################################################################
#           1           4 2 1 5 3 7 6
#          / \          One idea is to get Inorder represntation
#         /   \         of the trees for O(N), and than ju:z pyt-hon
#        /     \        find for avaerage O(N)
#       2       3
#      / \     / \      
#     4   N   5   6   
#    N N     N N 7 N    1 2 3 4 N 5 6 N N N N 7 N
#
# I've passed around 114 / 304 or smth test cases, and checked 
# the hint, it turns out both Preorder and Inorder have to
# match, the qvestion is ytf?
# Ok for whatever reason with or without Preorder this is not
# working??! Have to try something else I guess..
################################################################
class NotSame( Exception ): pass
class TheSame( Exception ): pass
################################################################
def travel( T, S ):
    if T is None:
        if S is None: return
        else:         raise NotSame
    if S is None: raise NotSame
    if T.data != S.data: raise NotSame
    travel( T.left,  S.left )
    travel( T.right, S.right ) 
################################################################
def areSame( T, S ):
    try:
        travel( T, S )
    except NotSame:
        return False
    return True        
################################################################
def check( T, S ):
    if T == None: return
    if areSame( T, S ): raise TheSame
    check( T.left, S )
    check( T.right, S )
################################################################
# Test Cases Passed: 304 / 304
# Total Points Scored: 4 / 4
# Your Total Score: 786
# Total Time Taken: 1.39
# Your Accuracy: 25%
# Attempts No.: 4
################################################################
class Solution:
    def isSubTree( self, T, S ):
        try:
            check( T, S )
        except TheSame:
            return True
        return False
################################################################
if __name__=="__main__":
    t = int( input() )
    for _ in range( t ):
        rootT = buildTree( input() )
        rootS = buildTree( input() )
        if Solution().isSubTree( rootT, rootS ):
            print( "1" )
        else:
            print( "0" )
################################################################
# log:
