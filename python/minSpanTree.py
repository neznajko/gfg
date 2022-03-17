################################################################
# Minimum Spanning Tree 
# Medium Accuracy: 49.39% Submissions: 42180 Points: 4
# Given a weighted, undirected and connected graph of V vertices
# and E edges. The task is to find the sum of weights of the
# edges of the Minimum Spanning Tree.
# 
# Your task: Since this is a functional problem you don't have__
# to worry about input, you just have to complete the function==
# spanningTree() which takes number of vertices V and an````````
# adjacency matrix adj as input parameters and returns an-------
# integer denoting the sum of weights of the edges of the,,,,,,,
# Minimum Spanning Tree. Here adj[i] contains a list of lists%%%
# containing two integers where the first integer a[i][0]:::::::
# denotes that there is an edge between i and a[i][0] and second
# integer a[i][1] denotes that the distance between edge i and..
# a[i][0] is a[i][1].~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 
# Expected Time Complexity: O(ElogV).
# Expected Auxiliary Space: O(V^2).
#
# Constraints:
# 2 ≤ V ≤ 1000
# V-1 ≤ E ≤ (V*(V-1))/2
# 1 ≤ w ≤ 1000
# Graph is connected and doesn't contain self loops & multiple
# edges.
################################################################
from heapq import heappush as push, heappop as pop
class Solution:
    # Improvisation of Prim's algorithm:
    def spanningTree( self, o_o, x_o): #
        heap = []
        viz = [ False]*V # visited vertices
        staat = 0
        # here w is first becos of the priority queue
        push( heap, ( 0, staat)) # ( w, u)
        s = 0 # sum
        n = 0 # tree counter
        while True:
            w, u = pop( heap)
            if viz[ u]: continue
            viz[ u] = True # spanning tree vertex
            s += w
            n += 1
            if n == V: break
            for v, w in adj[ u]:
                if not viz[ v]:
                    push( heap, ( w, v))
        return s
# Test Cases Passed: 121 / 121
# Total Time Taken:  1.3 / 7.6
################################### Contributed by: Nagendra Jha
if __name__ == '__main__':
    test_cases = int( input())
    for cases in range( test_cases):
        V, E = map( int, input().strip().split())
        adj = [[] for i in range( V)]
        for i in range( E):
            u, v, w = map( int, input().strip().split())
            adj[ u].append([ v, w])
            adj[ v].append([ u, w])
        ob = Solution()        
        print( ob.spanningTree( V, adj))
################################################################
# 
#
