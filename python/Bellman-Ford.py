################################################################
# Distance from the Source( Bellman-Ford Algorithm)
################################################################
# Medium Accuracy: 56.58% Submissions: 5056 Points: 4
################################################################
# Given a weighted, directed and connected graph of V vertices
# and E edges, Find the shortest distance of all the vertex's 
# from the source vertex S.
################################################################
# Note: The Graph doesn't contain any negative weight cycle.
################################################################
# Your Task: You don't need to read input or print anything.
# Your task is to complete the function bellman_ford() which
# takes number of vertices V and an E sized list of lists of
# three integers where the three integers are u, v, and w;
# denoting there's an edge from u to v, which has a weight of w
# as input parameters and returns a list of integers where the
# ith integer denotes the distance of ith node from source
# node. If some node isn't possible to visit, then it's distance
# should be 100000000( 1e8).
################################################################
# Expected Time Complexity: O( V*E).
# Expected Auxiliary Space: O( V).
################################################################
from collections import deque
class Solution:
    def bellman_ford( self, nV, edgs, src):
        # Before Start
        graph = [[] for _ in range( nV)]
        for u, v, w in edgs:
            graph[ u].append(( v, w))
        deq = deque([ src])
        vztd = [ False]*nV
        dist = [ 100000000]*nV # 1e8
        dist[ src] = 0
        # Start
        while deq: # Finish
            u = deq.popleft()
            vztd[ u] = True
            for v, w in graph[ u]:
                d = dist[ u] + w
                if d < dist[ v]:
                    dist[ v] = d
                    if vztd[ v]: deq.append( v)
                if not vztd[ v]: deq.append( v)
        return dist # After Finish
#################################################### Driver Code
if __name__ == '__main__':
    test_cases = int( input())
    for cases in range( test_cases):
        V, E = map( int, input().strip().split())
        adj = []
        for i in range( E):
            u, v, w = map( int, input().strip().split())
            adj.append([ u, v, w])
        S = int( input())
        ob = Solution()
        res = ob.bellman_ford( V, adj, S)
        for i in res:
            print( i, end=" ")
        print()
################################################################
# log: Total Time Taken: 0.2/1.8
# Am not very sure, but I think this algorithm is an improvement
# over Bellman-Ford, it is basically a Dijkstra with two changes
# we use normal instead of priority queue, and vhen the distance
# is updated, the corresponding vertex is pushed back to the deq
# regardles whether it has been visited or not.
################################################################
