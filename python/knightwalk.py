################################################################
# Knight Walk
################################################################
# Given a square chessboard, the initial position oöf Knight and
# position of a target. Find out the minimum steps a Knight will
# take to reach the target positn. If it cannot reach the target
# position return -1.
################################################################
# Note: The initial and the target position cordinates of Knight
# have been given accoring to 1-base indexing.
###############################################################=
# Example:     1
# Input:       N = 6
#              knightPos[ ] = {4, 5}
#              targetPos[ ] = {1, 1}
# Output:      3
# Explanation:   1   2   3   4   5   6
#              +---+---+---+---+---+---+
#              |   |   |   |   |   |   | 6
#              +---+---+---+---+---+---+
#              |   |   |   | N |   |   | 5
#              +---+---+---+---+---+---+
#              |   |   |   |   |   |   | 4
#              +---+---+---+---+---+---+
#              |   |   |   |   | * |   | 3
#              +---+---+---+---+---+---+
#              |   |   | * |   |   |   | 2
#              +---+---+---+---+---+---+
#              | T |   |   |   |   |   | 1 
#              +---+---+---+---+---+---+
#              Knight takes 3 step to reach from
#              (4, 5) to (1, 1):
#              (4, 5) -> (5, 3) -> (3, 2) -> (1, 1). 
################################################################
########________########________########________########________
# your  #       # y o u #       #       # t  o  #       # input
#       # task: #       # don't # need  #       # READ  #
################################################################
#       # print # anyt  # Your  #       #       #       #
# o   r #       # hing. #       # task  # is    # T O   # blah
################################################################
#       -       -       ^       -       - can   - reach -
# blah  # blah  #  ...  ^  I f  #    it #   not #       # The
################################################################
# t a r # posi  # ret   #       #       #       #       #
# g e t # tion  # urn   #  -1.  #       #       #       #
################################################################
#       #       #       #       #       #       #       #
#       #       #       #       #       #       #       #
######## ####### ####### ####### ####### ####### ####### #######
################################################################
# Expected Time Complexity: O(N^2)
# Expected Auxiliary Space: O(N^2)
################################################################
# Constraints:
# 1 <= N <= 1000
# 1 <= Knight_pos(X,Y),Targer_pos(X,Y) <= N
################################################################
FRAMESIZ = 2
################################################################
# translate x,y 1-based input coordinates to i,j 0-based indices
def getij( x, y, n ):
    j = x - 1 + FRAMESIZ
    i = n - y + FRAMESIZ
    return i, j
################################################################
import numpy as np
################################################################
# +----+----+----+----+----+
# |    |-2-1|    |-2+1|    |
# +----+----+----+----+----+
# |-1-2|    |    |    |-1+2|
# +----+----+----+----+----+
# |    |    | 0 0|    |    |
# +----+----+----+----+----+
# |+1-2|    |    |    |+1+2|
# +----+----+----+----+----+
# |    |+2-1|    |+2+1|    |
# +----+----+----+----+----+
###############################################################=
dr = [(-2, -1), (-2, 1), (-1, 2), (1, 2),
      (2, 1), (2, -1), (1, -2), (-1, -2)]
###############################################################_
GRD = -1
NIL = 0
VZT = 1
################################################################
from itertools import product
###############################################################_
def makeboard( n ):
    siz = FRAMESIZ + n + FRAMESIZ
    brd = np.full(( siz, siz ), GRD, dtype=int )
    R = range( FRAMESIZ, FRAMESIZ + n )
    for ij in product( R, R ): brd[ ij ] = NIL
    return brd
################################################################
# [[-1 -1 -1 -1 -1 -1 -1 -1 -1 -1]                makeboard( 6 )
#  [-1 -1 -1 -1 -1 -1 -1 -1 -1 -1]                with GRD eq -1
#  [-1 -1  0  0  0  0  0  0 -1 -1]
#  [-1 -1  0  0  0  0  0  0 -1 -1]
#  [-1 -1  0  0  0  0  0  0 -1 -1]
#  [-1 -1  0  0  0  0  0  0 -1 -1]
#  [-1 -1  0  0  0  0  0  0 -1 -1]
#  [-1 -1  0  0  0  0  0  0 -1 -1]
#  [-1 -1 -1 -1 -1 -1 -1 -1 -1 -1]
#  [-1 -1 -1 -1 -1 -1 -1 -1 -1 -1]]                       Fig. 1
###############################################################=
from collections import deque
################################################################
# Test Cases Passed: 160 / 160 I thought starting from both ends
# Total Points Scored: 4 / 4   will be faster I don't know maybe
# Your Total Score: 934        it was 4 using np.array 4 indices.
# Total Time Taken: 6.71
# Your Accuracy: 20%
# Attempts No.: 5
################################################################
class Solution:
    """"""
    def minStepToReachTarget( self, KnightPos, TargetPos, N ):
        ''''''
        KnightPos = getij( *KnightPos, N )
        TargetPos = getij( *TargetPos, N )
        brd = makeboard( N )
        brd[ KnightPos ] = VZT
        deq = deque([( KnightPos, 0 )])
        while len( deq ):
            n = len( deq )
            for _ in range( n ):
                (i0, j0), d = deq.popleft()
                if (i0, j0) == TargetPos: return d
                for di, dj in dr:
                    i = i0 + di
                    j = j0 + dj
                    if brd[ i, j ] == NIL:
                        brd[ i, j ] = VZT
                        deq.append((( i, j ), d + 1 ))
        return -1
    
###############################################################_
# log: youtu.be/u2kOR5YcIQU
################################################################
print( Solution().minStepToReachTarget([ 8, 8 ], [ 1, 1 ], 8 ))
################################################################
#######_                                                #######=
