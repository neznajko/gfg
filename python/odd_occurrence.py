########################################################
########################################################
########################################################
##############                                      ____
##############    ~~~~~~~~~~~~~~~:::::::::::::::    ____
##############    ~~~~~~~~~~~~~~   :::::::::::::    ____
##############    ~~~~~~                  ::::::    ____
##############    ~~~~~~~~~~~~      ::::::::::::    ____
##############    ~~~~~~~~~   ~~~:::   :::::::::    ____
##############    ~~~~~~   ~~~~~~::::::   ::::::    ____
##############    ~~~~~~~~~~~~~~~:::::::::::::::    ____
##############    <<                          &&    ____
##############    <<<<<<<<<<<<<<<&&&&&&&&   &&&&    ____
##############    <<<<           &&&&&&&&   &&&&    ____
##############    <<<<   <<<<<   &&&&&&&&   &&&&    ____
##############    <<<<           &&&&&&&&   &&&&    ____
##############    <<<<   <<<<<<<<&&&&&&&&   &&&&    ____
##############    <<<<<<<<<<<<<<<&&&&&&&&   &&&&    ____
##############                                   
########################################################
########################################################
########################################################
###################   ##################################
###########                   ##########################
################`  .#.  `###############################
##############`  .#####,  '#############################
########################################################
########                         #######################
###########################   ##########################
############         ######   ##########################
############  #####  ######   ##########################
############  #####  ######   ##########################
############         ######   ##########################
############  #############   ##########################
###########################  .##########################
##########################` .###########################
########################################################
########################################################
########################################################
    ####                                        ####  キ
    ####                                        ####
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
# Two numbers with odd occurrences #####################     o_o
################################################################
# Given an unsorted array, Arr[] of size N and that contains ###
# even number of occurrences for all numbers except two numbers.
# Find the two numbers in decreasing order which has odd #######
# occurrences. #################################################
########################################################
# Input: 4, 2, 4, 5, 2, 3, 3, 1 ########################
# Output: 5, 1 #########################################
########################################################
# Expected Time Complexity: O(N) #######################
# Expected Auxiliary Space: O(1) #######################
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
#######################################################_
class Solution:
    def twoOddNum( self, a, n ):
        s = set()
        for key in a:
            if key in s: s.remove( key )
            else:        s.add(    key )
        return [ max( s ), min( s )]
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
if __name__=='__main__':################################
    t=int(input())######################################
    for _ in range(t):##################################
        N=int(input())##################################
        Arr=input().split()#############################
        for itr in range(N):############################
            Arr[itr]=int(Arr[itr])######################
        ob=Solution()###################################
        ans=ob.twoOddNum(Arr,N)#########################
        for i in range(len(ans)):#######################
            print(ans[i],end=" ")#######################
        print()#########################################
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
# Test Cases Passed:                             25 / 25
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1250
# Total Time Taken:                                 1.84
