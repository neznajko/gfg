################################################################
# Detect cycle in a directed graph
################################################################
# Given a Directed Graph with V vertices (Numbered from 0 to V-1)
# and E edges, check whether it contains any cycle or not.
################################################################
# Expected Time Complexity: O(V + E)
# Expected Auxiliary Space: O(V)
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
class Cycle_Detected( Exception ): pass
###############################################################_
class Solution:
    """"""
    def explore( self, v ):
        self.enter[ v ] = True
        for u in self.adj[ v ]:
            if self.leave[ u ]: continue
            if self.enter[ u ]: raise Cycle_Detected()
            self.explore( u )
        self.leave[ v ] = True

    def isCyclic( self, n, adj ):
        self.enter = [ False ] * n
        self.leave = [ False ] * n
        self.adj = adj
        try:
            for v in range( n ):
                if self.leave[ v ]: continue
                self.explore( v )
        except Cycle_Detected:
            return True
        return False        

################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
###############################################################=
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
if __name__=='__main__':########################################
    t=int(input())##############################################
    for i in range(t):##########################################
        V,E=list(map(int,input().strip().split()))##############
        adj=[[] for i in range(V)]##############################
        for i in range(E):######################################
            a,b=map(int,input().strip().split())################
            adj[a].append(b)####################################
        ob=Solution()###########################################
        if ob.isCyclic(V, adj):#################################
            print(1)############################################
        else:###################################################
            print(0)############################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                   410 / 410
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1218
# Total Time Taken:                                          4.1