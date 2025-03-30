################################################################
################################################################
################################################################
################################################################
# Two Stacks in an Array
################################################################
# Your task is to implement 2 stacks in one array efficiently
# You need to implement 4 methods
################################################################
# twoStacks: Initialize the data structures and variables to be
# used to implement 2 stacks in one array
# push1: pushes element into the first stack
# push2: pushes element into the second stack
# pop1: pops an element from the first stack and returns the
# popped element. If the first stack is empty, return -1
# pop2: pops an element from the second stack and returns the
# popped element. If the second stack is empty, return -1
################################################################
# Examples:
# Input:
# push1(2)
# push1(3)
# push2(4)
# pop1()
# pop2()
# pop2()
# Output: [3, 4, -1]
################################################################
# 1 <= number of queries <= 10^4
# 1 <= number of elements in the stack <= 100
################################################################
################################################################
################################################################
################################################################
class TwoStacks:
    
    def __init__( self ):
        self.bufr = [ 0 ] * 1024
        self.sp1 = -1
        self.sp2 = len( self.bufr )

    def push1( self, x ):
        self.sp1 += 1
        self.bufr[ self.sp1 ] = x

    def pop1( self ):
        if self.sp1 > -1:
            self.sp1 -= 1
            return self.bufr[ self.sp1 + 1 ]
        return -1

    def push2( self, x ):
        self.sp2 -= 1
        self.bufr[ self.sp2 ] = x

    def pop2(self):
        if self.sp2 < len( self.bufr ):
            self.sp2 += 1
            return self.bufr[ self.sp2 - 1 ]
        return -1

################################################################
################################################################
# 1.2.1 Prove that √3 is irrational number.
# If it's a rational we'll have (p/q)² = 3, and p² = 3q², we can
# assume p and q have no common factors, cos we can cancel them,
# if q² is even, then p² is also even, but be cos if we multiply
# odd number by itself we'll get an odd number, p and q are also
# even, that means they have a common factor, zo q and p must be
# odd.
# p = 2s + 1
# q = 2t + 1, we can rewrite the above equation as:
# p² - q² = 2q², and substitue:
# (2s + 1)² - (2t + 1)² = 4s² + 4s + 1 - 4t² - 4t - 1 =
# = 4(s² - t² + s - t ) = 2q², zo q² = 2(s² - t² + s - t ),
# which means that q is even, so the assumption that √3 is
# rational is false
################################################################
################################################################
if __name__=='__main__': #######################################
    T=int(input()) #############################################
    while T>0: #################################################
        sq=TwoStacks() #########################################
        Q=int(input()) #########################################
        while Q>0: #############################################
            query=list(map(int,input().split())) ###############
            if query[1]==1: ####################################
                if query[0]==1: ################################
                    sq.push1(query[2]) ######################### 
                elif query[0]==2: ##############################
                    sq.push2(query[2]) #########################
            elif query[1]==2: ##################################
                if query[0]==1: ################################
                    print(sq.pop1(),end=' ') ###################
                elif query[0]==2: ##############################
                    print(sq.pop2(),end=' ') ###################
            Q-=1 ###############################################
        print() ################################################
        T-=1 ###################################################
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                 1111 / 1111
# Points Scored:                                           4 / 4
# Your Total Score:                                         1898 
# Time Taken:                                               0.25
# After Echoes: https://youtu.be/e_LvcTN8Las?si=w39iNsD1xUIsSYQq
