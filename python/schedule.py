################################################################
#   C o u r s e   S c h e d u l e   *   C o u r s e   S c h e d
################################################################
# There are a totl of n tsks you hav to pck   *   There are a to
################################################################
# ay   *   , labld from 0 to n - 1. Some tasks may   *   , labld
################################################################
# tes tasks   *   have prerequisites tasks,   *   have prerequis
################################################################
# for exmple to pck tsk 0 you hav to   *   for exmple to pck tsk
################################################################
# xressd   *   fst finish tasks 1, which is expressd   *   fst f
################################################################
# Given   *   as a pair: [ 0, 1 ]. Given   *   as a pair: [ 0, 1
################################################################
# nd a list   *   the totl nmbr of n tasks, and a list   *   the
################################################################
#   *   of prerequisite pairs of size m. Find   *   of prerequis
################################################################
# pick to   *   a ordering of tasks you should pick to   *   a o
################################################################
# ks.   *   finish all tasks.   *   finish all tasks.   *   fini
################################################################
# e corect ordrs   *   Note: Thre may b mltiple corect ordrs   *
################################################################
#    *   , you jst need to retrn one of them.   *   , you jst ne
################################################################
#   If it is impsble to fnsh all tsks   *   If it is impsble to 
################################################################
# g any   *   , return an empty array. Returnng any   *   , retu  
################################################################
# utpt as 1,   *   correct order will give the outpt as 1,   *
################################################################
# *    wheres any invalid ordr wll give the   *   wheres any inv
################################################################
# ".   *   output "No Ordering Possible".   *   output "No Order
################################################################
# Example: 2       Input: n = 4, m = 4 prerequisites = {{ 1, 0 },
# Output: 1                                             { 2, 0 },
# Explanation: ... one correct task order is [ 0, 1, 2, { 3, 1 },
#                                              3 ], ... { 3, 2 }}
###############################################################_
# Expected Time Complexity: O( n + m )
# Expected Auxiliary Space: O( n + m )
from collections import deque###################################
# v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v 
class Solution:# ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
    def findOrder( self, n, m, prerequisites ):
        """ Every task j is like a graph node, a prerequisite
        pair ( i, j ) means i depends on j, or j is < than i,
        that is j must be done previous to i or = to say i is
        next to j """
        nfPrev = [ 0 ]* n# number of previous nodes
        lsNext = [[] for j in range( n )]# list of next nodes
        for i, j in prerequisites:# j < i
            nfPrev[ i ] += 1
            lsNext[ j ].append( i )
        deq = deque()# task queue
        for j, nfprev in enumerate( nfPrev ):
            if not nfprev:
                deq.append( j )
        topsort = []
        while len( deq ):
            topsort.append( deq.popleft() )
            for i in lsNext[ topsort[ -1 ]]:
                nfPrev[ i ] -= 1
                if not nfPrev[ i ]:
                    deq.append( i )
        if len( topsort ) < n:
            return []
        return topsort
###############################################################=
def check( graph, N, res )        :#############################
    map = [ 0 ]*                  N#############################
    for i in range( N )           :#############################
        map[ res[ i ]] =          i#############################
    for i in range( N )           :#############################
        for v in graph[ i ]       :#############################
            if map[ i ] > map[ v ]:#############################
                return        False#############################
    return                     True#############################
################################################################
if __name__ == '__main__'                           :###########
    n, m = list( map( int, input().strip().split() ))###########
    adj = [ [] for i in range( n )                  ]###########
    prerequisites = [                               ]###########
    for i in range( m )                             :###########
        u, v = map( int, input().split()            )###########
        adj[ v ].append( u                          )###########
        prerequisites.append([ u, v ]               )###########
    ob = Solution(                                  )###########
    res = ob.findOrder( n, m, prerequisites         )###########
    if( not len( res ))                             :###########
        print( "No Ordering Possible"               )###########
    else                                            :###########
        if check( adj, n, res )                     :###########
            print( 1                                )###########
        else                                        :###########
            print( 0                                )###########
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                               10124 / 10124
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1058
# Total Time Taken:                                         2.09
# Your Accuracy:                                             50%
# Attempts No.:                                                2
################################################################
