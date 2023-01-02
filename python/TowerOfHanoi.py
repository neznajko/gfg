################################################################
# Tower Of Hanoi                                               #
################################################################
# The tower of Hanoi is a famous puzzle where we have three rods
# and N disks. The objective of the puzzle is to move the entire
# stk to another rod. You are given the nmbr of discs N. Initlly,
# thse discs are in the rod 1. You need to prnt all the steps of
# discs mvmnt so that all the discs reach the 3rd rod. Also, you
# need to find the total moves.                                #
################################################################
# Note: The discs are arrnged such that the top disc is numbered
# 1 and the bottm-most disc is nmbrd N. Also, all the discs have
# different sizes and a biggr disc cannot be put on the top of a
# smallr disc. Refer the provdd link to get a bettr clrity about
# the puzzle( clck ).                                          #
################################################################
# Example:                                                     1
# Input:                                                   N = 2
# Output:                        move disk 1 from rod 1 to rod 2
#                                move disk 2 from rod 1 to rod 3
#                                move disk 1 from rod 2 to rod 3
#                                                              3
################################################################
# Example:                                                     2
# Input:                                                   N = 3
# Output:                        move disk 1 from rod 1 to rod 3
#                                move disk 2 from rod 1 to rod 2
#                                move disk 1 from rod 3 to rod 2
#                                move disk 3 from rod 1 to rod 3
#                                move disk 1 from rod 2 to rod 1
#                                move disk 2 from rod 2 to rod 3
#                                move disk 1 from rod 1 to rod 3
#                                                              7
################################################################
# Please take care of the case of the letters.                 #
################################################################
# Expected Time Complexity: O(2^N)                             #
# Expected Auxiliary Space: O(N)                               #
################################################################
# Constraints:                                                 #
# 1 <= N <= 16                                                 #
################################################################
# The most straightforward approach seems to be using three stacks
# for the disks on the rods, and recursive function with base case
# r( N=1, FROM, TO, AUX ):
#   disk <- stack[ FROM ].pop()
#   print( move disk {disk} from rod {FROM} to rod {TO} )
#   stack[ TO ].push( disk )
#   return 1,
# for r > 1, we use recursive solution:
# r( N, FROM, TO, AUX ):
#   $1 <- r( N-1, FROM, AUX, TO ); move N-1 disks from FROM to
#                                ; AUX
#   $2 <- r( 1, FROM, TO, ? ); move the ramaining Nth disk to TO
#   $3 <- r( N-1, AUX, TO, FROM ); move the N-1 disks from AUX to
#                                ; TO completing the task
#   return $1 + $2 + $3.
# Now let's check vhether the printing is the same.
################################################################
# stack[ 1 ] = { 2, 1 }
# r( N=2, FROM=1, TO=3, AUX=2 )
#   $1 <- r( N=1, FROM=1, TO=2, AUX=3 )
#           disk <- 1; stack[ 1 ] = { 2 }
#           > "move disk 1 from rod 1 to rod 2"
#           ; stack[ 2 ] = { 1 }, $1 = 1
#   $2 <- r( N=1, FROM=1, TO=3, AUX=? )
#           disk <- 2; stack[ 1 ] = {}
#           > "move disk 2 from rod 1 to rod 3"
#           ; stack[ 3 ] = 2, $2 = 1
#   $3 <- r( N=1, FROM=2, TO=3, AUX=1 )
#           disk <- 1; stack[ 2 ] = {}
#           > "move disk 1 from rod 2 to rod 3"
#           ; stack[ 3 ] = { 2, 1 }, $3 = 1
# return 3, ok this seems to work, will write the code and check
# vhether it's working for N=3, etc.
################################################################
class Solution:
    def __init__( self ):
        """"""
        self.stk = [ None, None, [], [] ]
        
    def mv( self, FROM, TO ):
        disk = self.stk[ FROM ].pop() 
        print( "move disk %d from rod %d to rod %d" % ( disk, FROM, TO ))
        self.stk[ TO ].append( disk )
        return 1
        
    def r( self, N, FROM, TO, AUX ):
        if N == 1: return self.mv( FROM, TO )
        _1 = self.r( N - 1, FROM, AUX, TO )
        _2 = self.mv( FROM, TO )
        _3 = self.r( N - 1, AUX, TO, FROM )
        return _1 + _2 + _3

    def toh( self, N, FROM, TO, AUX ):
        self.stk[ 1 ] = list( reversed( range( 1, N + 1 )))
        if N == 1: return self.mv( FROM, TO )
        return self.r( N, FROM, TO, AUX )
################################################################
# Test Cases Passed: 21 / 21
# Total Points Scored: 4 / 4
# Your Total Score: 970
# Total Time Taken: 0.18
# Your Accuracy: 100%
# Attempts No.: 1
################################################################
print( Solution().toh( 3, 1, 3, 2 ))
################################################################
