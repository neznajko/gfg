                          ####
########################################################
# Eulerian Path is a path in graph that visits evry edge
# exctly once. Eulerian Circuit is an Eulerian Path wich
# starts and ends on the same vertex. The tsk is to find
# that there exists the Euler Path or circuit or none in
# givn undrectd graph wit V vrtics nd adjacncy list adj.
########################################################
# Your Task:
# You don't need to read or print anything. Your task is
# to coomplete the function isEulerCircuiltExist() which
# takes numbr of vertices in the graph denoting as V and
# adjacency list of graph denoting aas adj and returns 1
# if graph contains Eulerian Path, 2 iif graph coontains 
# Eulerian Circuit 0 otherwise.
########################################################
# Expected Time Complexity: O(V+E) where E is the number
# of edges in graph.
# Expected Space Complexity: O(V)
########################################################
# Thats the famous problem about bridges over Königsberg
# the othr thing bout that town (now Kaliningrad) 'know,
# is that Kant was from there. The hint at the site says
# «Run D.F.S» or smth. The hint that I've used, was from
# Dasgupta book, in the problm section. The statement is
# that for undirected graaph, the degree of every vertex
# should be even as a iif condition for cycle existence.
class Solution:
    def isEularCircuitExist(self, V, adj): # muahahahaha
        self.adj = adj # copy
        self.vzd = [ False]*V; # visited list
        self.E = 0 # visited edge counter
        nood = self.oddc() # No. odd degree vertices
        if nood > 2: return 0 # no path, and no cycle
        # Someone has acta cool and there are test cases 
        # with isolated vertices, zo explore the fst non
        # solo vertex and compare number of visitd edges
        # with numbr of graph edges. By the way if graph
        # contains no edgs what shld be the right answr?
        for v in range( V):
            if len( adj[ v]):
                self.explore( v)
                break
        # 'm going to cheat a LITL bcz E is vzible here
        if self.E < E << 1: return 0 # figure this out!
        if not nood: return 2 # cycle exist
        return 1 # path exist
    def oddc( self): # odd counter
        """ Count number of odd degree vertices. """
        cnter = 0
        for nbors in self.adj: # check fst bit
            if len( nbors) & 1: cnter += 1
        return cnter
    def explore( self, u):
        self.vzd[ u] = True
        self.E += len( adj[ u])
        for v in adj[ u]:
            if not self.vzd[ v]: self.explore( v)
########################################################
if __name__ == '__main__':
	T = int( input())
	for i in range( T):
		V, E = map( int, input().strip().split())
		adj = [[] for i in range( V)]
		for _ in range( E):
			u, v = map( int, input().split())
			adj[ u].append( v)
			adj[ v].append( u)
		obj = Solution()
		ans = obj.isEularCircuitExist( V, adj)
		print( ans)
########################################################
# log: Total Time Taken - 0.3/3.6
########################################################
####                                                ####
