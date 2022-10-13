################################################################
# k-th smallest element in BST
################################################################
# Given a BST and an integer K. Find the Kth Smallest element in
# the BST.
################################################################
# Example: 1
# Input:     2
#           / \
#          1   3
#          K = 2
# Output:  2
################################################################
# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(1)
################################################################
from collections import deque
################################################################ D
class Node:                                                    # r
    def __init__(self, val):                                   # i
        self.right = None                                      # v
        self.data = val                                        # e
        self.left = None                                       # r
def buildTree(s):                                              # 
    #Corner Case                                               # C
    if(len(s)==0 or s[0]=="N"):                                # o
        return None                                            # d
    ip=list(map(str,s.split()))                                # e
    root=Node(int(ip[0]))                                      #
    size=0                                                     # w
    q=deque()                                                  # i
    q.append(root)                                             # t
    size=size+1                                                # h
    i=1                                                        #
    while(size>0 and i<len(ip)):                               # s
        currNode=q[0]                                          # p
        q.popleft()                                            # a
        size=size-1                                            # c
        currVal=ip[i]                                          # e
        if(currVal!="N"):                                      #
            currNode.left=Node(int(currVal))                   # s
            q.append(currNode.left)                            # a
            size=size+1                                        # v
        i=i+1                                                  # i
        if(i>=len(ip)):                                        # n
            break                                              # g
        currVal=ip[i]                                          #
        if(currVal!="N"):                                      # s
            currNode.right=Node(int(currVal))                  # t
            q.append(currNode.right)                           # i
            size=size+1                                        # l
        i=i+1                                                  # e
    return root                                                #
###############################################################_
# Test Cases Passed: 30 / 30 Noòbody can beat meë oön iìnoördeér
# Total Points Scored: 4 / 4 problems!
# Your Total Score: 870
# Total Time Taken: 0.1
# Your Accuracy: 100%
# Attempts No.: 1
################################################################
class Volley( Exception ): pass
class Solution:
    def KthSmallestElement( self, root, k ):
        self.k = k
        try:           self.inorder( root)
        except Volley: return self.kth.data
        return -1
    def inorder( self, root ):
        if root == None: return
        self.inorder( root.left)
        self.k -= 1
        if not self.k:
            self.kth = root
            raise Volley
        self.inorder( root.right)
################################################################ D
if __name__=="__main__":                                       # r
    t=int(input())                                             # i
    for _ in range(0,t):                                       # v
        s=input()                                              # e
        root=buildTree(s)                                      # r
        k1=int(input())                                        # C
        print(Solution().KthSmallestElement(root, k1))         # o
################################################################ d e
# log: -The oònly more stupid thing than your hidden messages is 
# the fact that you think they are smart.
#
