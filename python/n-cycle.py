########################################################################
# Negative weight cycle
########################################################################
# Medium Accuracy: 50.77% Submissions: 16712 Points: 4
# Givn a weghted directed graph with n nodes and m edgs. Nodes r labeled
# from 0 to n-1, the tsk is to chck if it contains a negatve weght cycle
# or not.
# Note: edges[i] is defined as u, v and weight.
########################################################################
# Example 1:
# Input: n = 3, edges = {{0,1,-1},{1,2,-2},{2,0,-3}}
# Output: 1
# Explanation: The graph contains negative weight
# cycle as 0->1->2->0 with weight -1,-2,-3,-1.
########################################################################
# Your Task:
# U don't need to read or prnt anythng. Ur task is to complte d'function
# isNegativeWeightCycle() which takes n and edges as input paramater and
# returns 1 if graph contains negative weight cycle otherwise returns 0.
########################################################################
# Expected Time Complexity: O(n*m)
# Expected Space Compelxity: O(n)
########################################################################
class Solution:
    def isNegativeWeightCycle( self, nV, edgs):
        ''' isNegativeWeightCycleExist '''
        # [Ok] this is Bellman-Fort as described in the Dasgupta chapter
        # about negative cycles, but there is no need to wait all |V||E|
        # loops; if there is an update from negative there is a n-cycle.
        dist = [ 0]*nV
        while True:
            up = False # updates flag
            for u, v, w in edgs:
                ''' u --w-> v '''
                d = dist[ u] + w
                if d < dist[ v]:
                    if dist[ v] < 0: return 1 # negative cycle exist
                    dist[ v] = d
                    up = True
            if not up: break # nop
        return 0
############################################################ DRIVER CODE
if __name__ == '__main__': 
	T = int( input())
	for i in range( T):
		n, m = input().split()
		n = int( n)
		m = int( m)
		edges = []
		for _ in range( m):
			edges.append( list( map( int, input().split())))
		obj = Solution()
		ans = obj.isNegativeWeightCycle( n, edges)
		print( ans)
########################################################################
# log: Total Time Taken - 0.2 / 7.0
########################################################################
