########################################################
########################################################
########################################################
########################################################
############------------------------####################                    
############   #*################   ####################
############====                ====####################
############   #  ####\  #####  #   ####################
############   #  #####  #####  #   ####################
############   #  #####  #####  #   ####################
############   :                #   ####################
############   #  ############  #   ####################
############   #  ############  #   ####################
############   #  ############  #   ####################
############   #  ###########| .#   ####################
############\\\\\\\\\\\\\\\\\\\\\\\\####################
############                        ####################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
# Maximum sum Rectangle
########################################################
########################################################
########################################################
########################################################
# Given a 2D matrix M of dimensions RxC. Find the maximum
# sum submatrix in it.
########################################################
# Input: R=4 C=5 M=[ 1 ,2,-1,-4,-20]
#                  [-8,-3, 4, 2,  1]
#                  [ 3, 8,10, 1,  3]
#                  [-4,-1, 1, 7, -6]
# Output: 29
# Explaneation: [ x, x, x, x, x]
#               [ x,-3, 4, 2, x]
#               [ x, 8,10, 1, x]
#               [ x,-1, 1, 7, x]
########################################################
########################################################
########################################################
########################################################
# Expected Time Complexity:O(R*R*C)
# Expected Auxillary Space:O(R*C)
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
class Solution:
    def maximumSumRectangle( self, n, m, a ):
        for i in range( n ):
            for j in range( 1, m ):
                a[i][j] += a[i][j - 1]
            a[i].insert( 0, 0 )
        self.n = n
        self.prefix = a
        res = -1
        for j1 in range( m ):
            for j2 in range( j1 + 1, m + 1 ):
                res = max( res, self.maxsubsum( j1, j2 ))
        return res
    def maxsubsum( self, j1, j2 ):
        s = 0
        maxs = -1
        for i in range( self.n ):
            val = ( self.prefix[i][j2] -
                    self.prefix[i][j1] )
            s = max( val, s + val )
            if maxs < s: maxs = s
        return maxs            
#######################################################=
#######################################################_
########################################################
########################################################
#　かがく　かがく　かがく　かがく　かがく　かがく　かがう＿かがく　かがく
#　アジアけんきゅう　アジアけんきゅう　アジアけんきゅう＿アジアけんきゅう
#　けいざい　けいざい　けいざい　けいざい　けいざい　けいざい　けいざい
#　こくさいかんけい　こくさいかんけい　こくさいかんけい　こくさいかんけい
#　コンピューター　コンピューター　コンピューター　コンピューター　コンピューター
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
import sys #############################################
#################################################################
if __name__=='__main__':#########################################
    t=int(sys.stdin.readline().strip())##########################
    for _ in range(t):###########################################
        N,M=map(int,sys.stdin.readline().strip().split())########
        a=[]#####################################################
        for i in range(N):#######################################
            s=list(map(int,sys.stdin.readline().strip().split()))
            a.append(s)##########################################
        ob=Solution()############################################
        print(ob.maximumSumRectangle(N,M,a))#####################
########################################################=========
########################################################---------
########################################################.........
########################################################
# Test Cases Passed:                           105 / 105
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1306
# Total Time Taken:                                 4.08