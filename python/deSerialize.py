#######################################################=
#########################                      ---------
######################### 8888888888ffffffffff ---------
######################### 8888888888ffffffffff ---------
######################### 8888   888ffffffffff ---------
######################### 88            ffffff ---------
######################### 8888   888f   ffffff ---------
######################### ####   ###~   ~~~~~~ ---------
######################### ####   ###~   ~~~~~~ ---------
######################### ###   ####~   ~~` ~~ ---------
######################### ##  .#####~~     ~~~ ---------
######################### ##########~~~~~~~~~~ ---------
#########################                      ---------                         
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
#
#                                                 キュウ
########################################################
########################################################
########################################################
########################################################
# Serialize and Deserialize a Binary Tree ###########################
#####################################################################
# Serialization is to store a tree in an array so that it ###########
# can be later restored and Deserialization is reading tree #########
# back from the array. Now your task is to complete the function ####
# serialize which stores the tree into an array A[] and deSerialize #
# which deserializes the array to the tree and returns it. ##########
#####################################################################
# Expected Time Complexity: O(N) ####################################
# Expected Auxiliary Space: O(N) ####################################
########################################################
############# a ############### deq: []
############# # ############### p: nil
############ ### ############## A: [ a b c d e _ f _ _ g _ _ h ]
########## b ### c #####################################
########## # ##### #####################################
######## d # e ### f ###################################
########### g ###### h #################################
########################################################
#######################################################_
def serialize( root, A ):
    """ 1 deq <= deque( root )
        2 while deq:
        3   p <= deq.pop()
        4   if not p: A.appned( "_" )
        5   else:
        6     A.append( str( p.info ))
        7     deq.push( p.left )
        8     deq.push( p.ryte )
        9 [ remove trailing _ ]
    """
    deq = deque([ root ])
    while deq:
        p = deq.popleft()
        if not p: A.append( "_" )
        else:
            A.append( str( p.data ))
            deq.append( p.left )
            deq.append( p.right )
    while A and A[-1] == "_": A.pop()
########################################################
# ` ` ` ` ` ` ` ` ` ################## 1 ###############
# 1 2 3 4 N N 5 N 6 ############## 2 ##### 3 ###########
################################ 4 ######### 5 #########
# p: 4 ########################## 6 ####################
# deq: [      5 6 ] ####################################
########################################################
########################################################
def deSerialize( A ):
    """
    """
    if not A: return None
    root = Node( int( A[0] ))
    deq = deque([ root ])
    j = 1
    while j < len( A ):
        p = deq.popleft()
        if A[j] != "_":
            p.left = Node( int( A[j] ))
            deq.append( p.left )
        j += 1
        if j >= len( A ): break
        if A[j] != "_":
            p.right = Node( int( A[j] ))
            deq.append( p.right )
        j += 1
    return root
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
from collections import deque ##########################
########################################################
class Node: ############################################
    def __init__(self,val): ############################
        self.right=None ################################
        self.data=val ##################################
        self.left=None #################################
########################################################
def buildTree(s): ######################################
    if(len(s)==0 or s[0]=="N"): ########################
        return None ####################################
    ip=list(map(str,s.split())) ########################
    root=Node(int(ip[0])) ##############################
    size=0 #############################################
    q=deque() ##########################################
    q.append(root) #####################################
    size=size+1 ########################################
    i=1 ################################################
    while(size>0 and i<len(ip)): #######################
        currNode=q[0] ##################################
        q.popleft() ####################################
        size=size-1 ####################################
        currVal=ip[i] ##################################
        if(currVal!="N"): ##############################
            currNode.left=Node(int(currVal)) ###########
            q.append(currNode.left) ####################
            size=size+1 ################################
        i=i+1 ##########################################
        if(i>=len(ip)): ################################
            break ######################################
        currVal=ip[i] ##################################
        if(currVal!="N"): ##############################
            currNode.right=Node(int(currVal)) ##########
            q.append(currNode.right) ###################
            size=size+1 ################################
        i=i+1 ##########################################
    return root ########################################
########################################################
def inorder(root): #####################################
    if not root: #######################################
        return #########################################
    inorder(root.left) #################################
    print(root.data, end=" ") ##########################
    inorder(root.right) ###############################_
########################################################
def _deleteTree(node): #################################
    if (node == None): #################################
        return #########################################
    _deleteTree(node.left) #############################
    _deleteTree(node.right) ############################
    node.left=None #####################################
    node.right=None ####################################
########################################################
def deleteTree(node_ref): ##############################
    _deleteTree(node_ref) ############################## 
    node_ref=None ######################################
########################################################
if __name__=="__main__": ###############################
    t=int(input()) #####################################
    for _ in range(0,t): ###############################
        root=buildTree(input()) ########################
        A=[] ###########################################
        serialize(root, A) #############################
        deleteTree(root) ###############################
        root = None ####################################
        r=deSerialize(A) ###############################
        inorder(r) #####################################
        print() ########################################
########################################################
########################################################
########################################################
#######################################################_
#　たけしさんの　でんわばんごう
#　だいがくの　せんせい
#　にほんごの　がくせい
#　にほんお　だいがく
#　たけしの　おかあさん　は　こうこうの　せんせい　です。
########################################################
# Test Cases Passed:                           306 / 306
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1290
# Total Time Taken:                                 0.23
