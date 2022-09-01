################################################################
#                                Implementing Dijkstra Algorithm
################################################################
# Given a weighted, undirected and connected graph of V vertices
#    and E edges, Find the shortest distance of all the vertex's
#                                      from the source vertex S.
################################################################
#     Note: The Graph doesn't contain any negative weight cycle.
################################################################
# Example 2:
# 
# Input:
# V = 3, E = 3
# u = 0, v = 1, w = 1
# u = 1, v = 2, w = 3
# u = 0, v = 2, w = 6
# adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
# S = 2
# Output:
# 4 3 0                
#                      1
#                 0---------1
#                  \       /
#                   \     /
#                 6  \   /  3
#                     \ /
#                      2, S
#                      
# Explanation: 4 = 2-1-0
#              3 = 2-1
#              0 = 2-2
################################################################
#                                                     Your Task:
#   You don't need to read input or print anything. Your task is 
#  to complete the function dijkstra() which takes the number of
#   vertices V and an adjacency list adj as input parameters and
#      returns a list of integers, where ith integer denotes the
#   shortest distance of the ith node from the Source node. Here
#  adj[i] contains a list of lists containing two integers where
#    the first integer j denotes that there is an edge between i
# and j and the second integer w denotes that the weight between
#                                             edge i and j is w.
################################################################
# Expected Time Complexity: O(V^2).
# Expected Auxiliary Space: O(V^2).
################################################################
# Constraints:
# 1 ≤ V, w ≤ 1000
################################################################
from collections import deque
from math import inf
################################################################
# Test Cases Passed: 131 / 131
# Total Points Scored: 4 / 4
# Your Total Score: 774
# Total Time Taken: 0.15
# Your Accuracy: 100%
# Attempts No.: 1
################################################################
# Whether it's more efficient I don't know but here it turns out
# that we can use normal rather than a priority queue because we
# are interested in all distances. If we are interested at given
# destination vertex, we can use a priority queue and stop after
# reaching destination.
################################################################
class Solution:
    def dijkstra( self, V, adj, S ):
        #
        dst = [ inf ]*V
        dst[ S ] = 0
        deq = deque([ S ])
        #
        while len( deq ):
            u = deq.popleft()
            for v, w in adj[ u ]:
                new_dst = dst[ u ] + w
                if new_dst < dst[ v ]:
                    dst[ v ] = new_dst
                    deq.append( v )
        return dst
################################################################
# t
# V E
# u1 v1 w1
# u2 v2 w2
# ..
# uE vE wE
# S
################################################################
if __name__ == '__main__':                               # DCode
    test_cases = int( input() )                          # DCode
    for cases in range( test_cases ):                    # DCode
        V, E = map( int, input().strip().split())        # DCode
        adj = [[] for i in range( V )]                   # DCode
        for i in range( E ):                             # DCode
            u, v, w = map( int, input().strip().split()) # DCode
            adj[ u ].append([ v, w ])                    # DCode
            adj[ v ].append([ u, w ])                    # DCode
        S = int( input())                                # DCode
        ob = Solution()                                  # DCode
        res = ob.dijkstra( V, adj, S)                    # DCode
        for i in res:                                    # DCode
            print( i, end=" " )                          # DCode
        print()                                          # DCode
################################################################
