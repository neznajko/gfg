################################################################
# Duplicate subtree in Binary Tree
################################################################
# Given a binary tree find out whether it contains a dupsub tree
# of size two or more, or not.
################################################################
# Example:     1
# Input:           1
#                 / \ 
#                2   3
#               / \   \    
#              4   5   2     
#                     / \    
#                    4   5
# Output:      1
# Explanation:   2     
#               / \    
#              4   5, is the duplicate sub-tree.
################################################################
# Note: Two same leaf nods are not considered as subtree as size
# of a leaf node is one.
################################################################
# Constraints:
# 1 ≤ Number of nodes ≤ 100
################################################################
################################################################
################################################################
################################################################
################################################################    
from collections import deque
###############################################################_
class Node:
    def __init__( self, val ):
        self.data  = val
        self.left  = None
        self.right = None
################################################################
def buildTree( s ):
    if( len( s ) == 0 or s[ 0 ] == "N" ): return None
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
#           1        pre: []
#          / \       ino: []
#         /   \      
#        /     \        
#       2       3
#      / \     / \      
#     4   N   5   2   
#    N N     N N 4 N _   
##### # ##### # ### ###########################################=
##### # ##### # ### ############################################
class Et_Voilà( Exception ): pass
################################################################
class Travel:
    """"""
    def journey( self, root ):
        if root == None:
            self.pre.append( 0)
            self.ino.append( 0)
        else:
            i = len( self.pre)
            j = len( self.ino)
            self.pre.append( root.data)
            self.journey( root.left)
            self.ino.append( root.data)
            self.journey( root.right)
            n = self.getHash( i, j)
            if n != 0 and n in self.bucket: raise Et_Voilà
            self.bucket.add( n)

    def getHash( self, i, j ):
        ls = self.pre[ i:]
        if len( ls) == 3: return 0 # leaf node
        ls.extend( self.ino[ j: ])
        return hash( tuple( ls ))

    def __init__( self ):
        self.pre = []
        self.ino = []
        self.bucket = set()

###############################################################=
# Test Cases Passed: 1072 / 1072 I had some issues solvng similr
# Total Points Scored: 4 / 4     prblm usng pre and inorder tree
# Your Total Score: 886          representations had to read the
# Total Time Taken: 0.1          link in the descriptn to figure
# Your Accuracy: 100%            why. Basicly the null nods have
# Attempts No.: 1                to be included as well.
################################################################
# geeksforgeeks.org/
# check-binary-tree-subtree-another-binary-tree-set-2/ 
################################################################
class Solution:
    def dupSub( self, T ):
        try: Travel().journey( T)
        except Et_Voilà: return 1
        return 0
################################################################
if __name__ == "__main__":
    T = buildTree( "1 2 3 4 5 2 N N N N N 4 5")
    print( Solution().dupSub( T ))
################################################################
# log: youtu.be/R3ihv5ateWw
#
