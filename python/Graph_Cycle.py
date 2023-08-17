############################################################****
# Detect cycle in an undirected graph
############################################################>>>>
# Given an undirected graph with V vertices and E edges, check whether
# it contains any cycle or not. Graph is in the form of adjacency
# list where adj[i] contains all the nodes ith node is having edge
# with.
############################################################::::
# Example: 1
# Input: V = 5, E = 5
# adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
# Output: 1
# Explanation: 1->2->3->4->1 is a cycle.
############################################################====
# Expected Time Complexity: O( V + E )
# Expected Space Complexity: O( V )
############################################################____
class Cycle_Detected( Exception ): pass
############################################################----
class Solution:
    
    def isCycle( self, V, adj ):
        ''' depth fyorst search '''
        self.viz = [ False ]* V
        self.adj = adj
        try:
            for v in range( V ):
                if not self.viz[ v ]: # if not vizited
                    self.explore( v, -1 ) 
        except Cycle_Detected:
            return True
        #
        return False

    def explore( self, v, p ):
        ''' p is v parent '''
        self.viz[ v ] = True # mark as vizited
        for u in self.adj[ v ]: # nbor loop
            if self.viz[ u ]:
                # if u is vizited and not parent we have cycle
                if u != p: raise Cycle_Detected()
            else:
                self.explore( u, v )
    
############################################################====
if __name__=='__main__':####################################____
    T=int(input())##########################################>>>>
    for i in range(T):######################################----
        V,E=map(int,input().split())########################||||
        adj=[[] for i in range(V)]##########################,,,,
        for _ in range(E):##################################====
            u,v = map(int,input().split())##################````
            adj[u].append(v)################################....
            adj[v].append(u)################################====
        obj=Solution()######################################____
        ans=obj.isCycle(V,adj)##############################....
        if(ans): print("1")#################################----
        else: print("0")####################################>>>>
############################################################____
############################################################====
############################################################::::
# Test Cases Passed:                               211 / 211
# Total Points Scored:                                 4 / 4
# Your Total Score:                                     1178
# Total Time Taken:                                     2.42
############################################################====
