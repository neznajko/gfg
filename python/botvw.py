########################################################
########################################################
#####                          #########################
####  999999999999@@@@@@@@@@@@  ########################
####  9                      @  ########################
####  9 99  99999  @@@@@@@@@ @  ########################
####  9 999  9999  @@@@@@@@@ @  ########################
####  9 9999999999@@@@@@ @@@ @  ########################
####  9 9999   999@@@@@ @@@@ @  ########################
####  % %%%%%%%   ===  ===== =  ########################
####  % %%%%%%%%%%   ======= =  ########################
####  % %%%       ===   ==== =  ########################
####  % %%%%%%%%%%========== =  ########################
####  %                      =  ########################
####  % %%%%%%%%%%============  ########################
#####                          #########################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
      ###########                      _______/                        
      ###########                      ______/        ズ
########################################################
########################################################
########################################################
class Solution:
    def bottomView( self, root ):
        d = {}
        deq = deque([( root, 0 )])
        while deq:
            n = len( deq )
            for _ in range( n ):
                p, w = deq.popleft()
                d[ w ] = p.data
                if p.left:
                    deq.append(( p.left, w - 1 ))
                if p.right:
                    deq.append(( p.right, w + 1 ))
        return [ v for k, v in sorted( d.items())]
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
# Bottom View of Binary Tree
########################################################
########################################################
########################################################
########################################################
# Given a binary tree, print the bottom view from left to
# right. A node is included in bottom view if it can be
# seen when we look at the tree from bottom. If there are
# multiple bottom-most nodes for a horizontal distance from
# root, then print the later one in level traversal. For
# example, in the below diagram, 3 and 4 are both the bottom-
# most nodes at horizontal distance 0, we need to print 4.
#
#                      20
#                     /  \
#                    8   22
#                   / \  / \
#                   5  3 4 25
#                     /  \      
#                    10  14
# 
# For the above tree the output should be 5 10 4 14 25.
########################################################
########################################################
########################################################
########################################################
# Expected Time Complexity: O( N log N )
# Expected Auxiliary Space: O( N       )
########################################################
########################################################
########################################################
########################################################
from collections import deque ##########################
########################################################
########################################################
########################################################
########################################################
class Node:#############################################
    def __init__(self,val):#############################
        self.right=None#################################
        self.data=val###################################
        self.left=None##################################
########################################################
########################################################
########################################################
########################################################
def buildTree(s):#######################################
    if(len(s)==0 or s[0]=="N"):#########################
        return None#####################################
    ip=list(map(str,s.split()))#########################
    root=Node(int(ip[0]))###############################
    size=0##############################################
    q=deque()###########################################
    q.append(root)######################################
    size=size+1#########################################
    i=1#################################################
    while(size>0 and i<len(ip)):########################
        currNode=q[0]###################################
        q.popleft()#####################################
        size=size-1#####################################
        currVal=ip[i]###################################
        if(currVal!="N"):###############################
            currNode.left=Node(int(currVal))############
            q.append(currNode.left)#####################
            size=size+1#################################
        i=i+1###########################################
        if(i>=len(ip)):#################################
            break#######################################
        currVal=ip[i]###################################
        if(currVal!="N"):###############################
            currNode.right=Node(int(currVal))###########
            q.append(currNode.right)####################
            size=size+1#################################
        i=i+1###########################################
    return root#########################################
########################################################
########################################################
########################################################
########################################################
if __name__=="__main__":################################
    t=int(input())######################################
    for _ in range(0,t):################################
        s=input()#######################################
        root=buildTree(s)###############################
        ob=Solution()###################################
        res=ob.bottomView(root)#########################
        for i in res:###################################
            print(i,end=" ")############################
        print()#########################################
########################################################
########################################################
########################################################
########################################################
# Test Cases Passed:                             60 / 60
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1234
# Total Time Taken:                                 0.64