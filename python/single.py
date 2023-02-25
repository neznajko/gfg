################################################################
# Single valued subtree
################################################################
# Givn a binary tree, count the number of Single Valued Subtrees.
# A Singl Valued Subtree is one in which all the nodes have same
# value. 
################################################################
# Example: 2
# Input:                   5
# 5 4 5 4 4 N 5           / \
#                        /   \
#                       4     5
#                      / \     \
#                     4   4     5   
# Output: 5
# Explanation: There are five subtrees with single values.
################################################################
# Expected Time Complexity: O(n)
# Expected Auxiliary Space: O(n)
################################################################
# Constraints:
# 1 <= n <= 10^5
################################################################
from collections import deque ##################################
################################################################
class Node: ####################################################
    def __init__(self, val): ###################################
        self.right = None ######################################
        self.data = val ########################################
        self.left = None #######################################
################################################################
def buildTree(s): ##############################################
    if(len(s)==0 or s[0]=="N"): return None ####################
    ip=list(map(str,s.split()));root=Node(int(ip[0]));size=0 ###
    q=deque() ##################################################
    q.append(root);size+=1;i=1 #################################
    while(size>0 and i<len(ip)): ###############################
        currNode=q[0];q.popleft();size-=1;currVal=ip[i] ########
        if(currVal!="N"): ######################################
            currNode.left=Node(int(currVal)) ###################
            q.append(currNode.left);size+=1 ####################
        i+=1 ###################################################
        if(i>=len(ip)): break ##################################
        currVal=ip[i] ##########################################
        if(currVal!="N"): ######################################
            currNode.right=Node(int(currVal)) ##################
            q.append(currNode.right);size+=1;i+=1 ##############
    return root ################################################
################################################################
g = None
################################################################
def f( p ):
    ''' I have lost the count, another solution in a row vithout
    auxiliary space. '''
    global g
    pass # Give them a moment for pity sake!
    ok = True
    l = p.left
    r = p.right
    if l: ok = f( l ) and l.data == p.data and ok
    if r: ok = f( r ) and r.data == p.data and ok
    if ok: g += 1
    return ok
################################################################
class Solution:
    def singlevalued( self, root ):
        global g
        if not root: return 0
        g = 0
        f( root )
        return g
################################################################
if __name__ == "__main__": #####################################
    root = buildTree( "6 4 N 4 4 N 5" ) ########################
    print( Solution().singlevalued( root )) ####################
################################################################
# 6 4 N 4 4 N 5                                    6           
#                                               4     N
#                                             4   4
#                                            N 5
################################################################
# Test Cases Passed:                                   131 / 131
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1050
# Total Time Taken:                                         0.64
# Your Accuracy:                                             50%
# Attempts No.:                                                2
################################################################
