########################################################
# B i p a r t i t e G r a p h
# Medium Accuracy: 40.1% Submissions: 53592 Points: 4
########################################################
# Givn an adjacncy lst of a graph adj of V no. of vrtics
# havng 0 based ndex. Chck whether the graph is biprtite
# or not.
########################################################
# Your Task:
# You don't need to read or print anything. Your task is
# to complete the fnctn isBipartite() whch taks V dnotng
# no. of vertices and adj denoting adjacency list of the
# graph and returns a boolean value true if the graph is
# bipartite otherwise returns false.
########################################################
# Expected Time Complexity: O( V+E)
# Expected Space Complexity: O( V)
########################################################
class Solution:
    """ A bipartite grph is a grph G=(V,E) hose vertices
    can be prtitiond into two sets (V=V1+V2, and V1V2=Ø)
    such that thre are no edgs betwen vrtics in the same
    set (for instnce, if u, v are in V1, then thre is no
    edge between u and v)         -- Dasgupta et al. """
    def isBipartite( self, nV, adj):
        self.nV   = nV
        self.adj  = adj
        self.sets = [ 0]*nV # 1 vs 2
        return self.dfs() ##############################
    def dfs( self): ####################################
        try:
            for u in range( self.nV):
                if not self.sets[ u]: # if 0( not vistd)
                    self.explor( u, 1) # or 2 as snd arg
            return True
        except Exception as e: return False ############
    def explor( self, u, g): ###########################
        self.sets[ u] = g
        for v in self.adj[ u]:
            if self.sets[ v] == g:
                raise Exception( "Not Bipartite")
            if not self.sets[ v]: # not visited
                self.explor( v, 3 - g) # 1 <-> 2
########################################################
if __name__ == '__main__':
    T = int( input())
    for i in range( T):
        V, E = map( int, input().strip().split())
        adj = [[] for i in range( V)]
        for i in range( E):
            u, v = map( int, input().strip().split())
            adj[ u].append( v)
            adj[ v].append( u)
        obj = Solution()
        pdb.set_trace()
        ans = obj.isBipartite( V, adj)
        if( ans):
            print( "1")
        else:
            print( "0")
########################################################
# log: - If you want to be elite than it's not enough to
# be arrogant to keep distance.
# Test Cases Passed: 825 / 825
# Total Time Taken:  1.6 / 6.6
########################################################
