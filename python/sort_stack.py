#---------                  
###----                     ==============//////////////
#####-----                  ==============//////////////
#######------               ==============//////////////
#########-------            ======= ======//////////////
#######------------         ======= ======//////////////
#####-----------            ======= ======//////////////
###----------               ====                    ////
#---------                  ======= ======//////////////
###----                     ####### ######..............
#####-----                  ####### ######..............
#######------               ########  ####..............
#########-------            ##########              ....
#######------------         ##############..............
#####-----------            ##############..............
###----------               ##############..............
#---------                  ##############--------------
########################################################
##                                                  シチ
# Sort a stack #########################################
###########################################################
# Given a stack, the task is to sort it such that the top #
# of the stack has the greatest element. ##################
###########################################################
# Expected Time Complexity: O(N*N) #####################
# Expected Auxilliary Space: O(N) recursive ############
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
class Solution:

    def Insert( self, key ):
        ls = []
        while self.a and self.a[-1] > key:
            ls.append( self.a.pop() )
        self.a.append( key )
        while ls:
            self.a.append( ls.pop() )

    def Sorted( self, a ):
        self.a = []
        while a: self.Insert( a.pop() )
        a[:] = self.a

########################################################
if __name__=='__main__':################################
    t=int(input())######################################
    for i in range(t):##################################
        n=int(input())##################################
        arr=list(map(int,input().strip().split()))######
        ob=Solution()###################################
        ob.Sorted(arr)##################################
        for e in range(len(arr)):#######################
            print(arr.pop(),end=" ")####################
        print()#########################################
########################################################
#＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃
########################################################
#　いま　なんじですか。
#　いま　なんじですか。
#　いま　なんじせうか。
#　いま　なんじですか。
########################################################
########################################################
# Test Cases Passed:                           100 / 100
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1282
# Total Time Taken:                                 0.15
