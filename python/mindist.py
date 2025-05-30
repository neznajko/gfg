################################################################
# Min distance between two given nodes of a Binary Tree    #####
################################################################
# Givn a binary tree and two node values your task is to find ##
# the minimum distance between them. The given two nodes are  ##
# guaranteed to be in the binary tree and nodes are numbered  ##
# from 1 to N. Please Note that a and b are not always leaf   ## 
# nodes.                                                      ##
################################################################
# Input:  1                                                 ####
#        / \                                                #### 
#       2   3 a = 2, b = 3                                  ####
# Output: 2                                                 #### 
################################################################
# Expected Time Complexity: O(N)                               #
# Expected Auxiliary Space: O(Height of the Tree)              # 
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
class Ok( Exception ): pass
################################################################
class T:
    def __init__( self, root ):
        self.root = root
        self.path = []
    def find( self, x ):
        self.path[:] = []
        try: self.inorder( self.root, x )
        except Ok: pass
        return self.path[:]
    def inorder( self, node, x ):
        if not node: return
        key = node.data
        self.path.append( key )
        if key == x: raise Ok()
        self.inorder( node.left, x )
        self.inorder( node.right, x )
        self.path.pop()
################################################################
class Solution:
    def findDist( self, root, a, b ):
        t = T( root )
        p = t.find( a )
        q = t.find( b )
        p.append( -1 ) # Guards
        q.append( -2 ) # 
        j = 0
        while p[ j ] == q[ j ]: j += 1
        return len( p[ j: ]) + len( q[ j: ]) - 2
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
####====####====####====####====####====####====####====####====
####    ####    ####    ####    ####    ####    ####    ####
####    ####    ####    ####    ####    ####    ####    ####
####    ####    ####    ####    ####    ####    ####    ####
from collections import deque   ####    ####    ####    #### oo
################################################################
################################################################
################################################################
################################################################
class Node:#####################################################
    def __init__(self,val):#####################################
        self.right=None#########################################
        self.data=val###########################################
        self.left=None##########################################
################################################################
################################################################
################################################################
################################################################
################################################################
def buildTree(s):###############################################
    if(len(s)==0 or s[0]=="N"):#################################
        return None#############################################
    ip=list(map(str,s.split()))#################################
    root=Node(int(ip[0]))#######################################
    size=0######################################################
    q=deque()###################################################
    q.append(root)##############################################
    size=size+1#################################################
    i=1#########################################################
    while(size>0 and i<len(ip)):################################
        currNode=q[0]###########################################
        q.popleft()#############################################
        size=size-1#############################################
        currVal=ip[i]###########################################
        if(currVal!="N"):#######################################
            currNode.left=Node(int(currVal))####################
            q.append(currNode.left)#############################
            size=size+1#########################################
        i=i+1###################################################
        if(i>=len(ip)):#########################################
            break###############################################
        currVal=ip[i]###########################################
        if(currVal!="N"):#######################################
            currNode.right=Node(int(currVal))###################
            q.append(currNode.right)############################
            size=size+1#########################################
        i=i+1###################################################
    return root#################################################
################################################################
################################################################
################################################################
################################################################
if __name__=="__main__":########################################
    t=int(input())##############################################
    for _ in range(0,t):########################################
        s=input()###############################################
        root=buildTree(s)#######################################
        a,b=map(int,input().split())############################
        ob=Solution()###########################################
        print(ob.findDist(root,a,b))############################
################################################################
################################################################
################################################################
################################################################
################################################################
###############################################################=
# log:   5  In class T, we can get the path from a given root up
#       /   to a given node. Like, if we have a tree W, at fig.1,
#      /    then T.find( W, 3 ) will return [ 5, 4, 1, 3 ]. This
#     4     way we can call the find method for the two nodes; a
#    / \    and b and pass over common nodes in respective paths.
#   2   1   Zo if a and b are equal to 2 and 1; then T.find will
#      3    give: [ 5, 4, 2 ] and [ 5, 4, 1 ], skipping [ 5, 4 ]
#   fig.1   will give [ 2 ] and [ 1 ] then the answer is the sum
#           of remaining path lengths: 1 + 1 = 2.
# Test Cases Passed:                                   400 / 400
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1194
# Total Time Taken:                                         0.03

