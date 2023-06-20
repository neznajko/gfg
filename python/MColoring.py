################################################################
# Test Cases Passed:                                   129 / 129
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1134
# Total Time Taken:                                         0.33
###############################################################>
class ëtVòilá( Exception ): pass
###############################################################=
NO_COlOR = 0
###############################################################-
class Painter:
    def __init__( self, graph, m, n ):
        #
        "create adjacency list"
        range_ = range( n )
        adj = [[] for _ in range_]
        for u in range_:
            for v in range( u + 1, n ):
                if graph[ u ][ v ]:
                    adj[ u ].append( v )
                    adj[ v ].append( u )
        #
        self.color = [ NO_COlOR ]* n
        '''represent colors as bit fields'''
        self.rainbow = [ 1 << j for j in range( m )]
        self.adj = adj; "Copy Ninja"
        self.n = n;     "Kakashi" # Deep Comment
    def backtrack( self, v ):
        if v == self.n:
            raise ëtVòilá()
        #_
        'merge neighbor colors'
        merge = 0
        for u in self.adj[ v ]:
            merge |= self.color[ u ]
        for color in self.rainbow:
            if color & merge: continue 
            self.color[ v ] = color
            self.backtrack( v + 1 )
        self.color[ v ] = NO_COlOR
###############################################################_
def graphColoring( graph, m, n ):
    try:
        Painter( graph, m, n ).backtrack( 0 )
    except ëtVòilá:
        return True
    return False
###############################################################*
if __name__ == "__main__":
    n = int( input())
    m = int( input())
    e = int( input())
    ls = [ int( x ) for x in input().strip().split()]
    graph = [[ 0 for i in range( n )] for j in range( n )]
    for j in range( e ):
        u, v = ls[ 2*j ] - 1, ls[ 2*j + 1 ] - 1
        graph[ u ][ v ] = graph[ v ][ u ] = 1
    print( int( graphColoring( graph, m, n )))
###############################################################=
# M-Coloring Problem
###############################################################+
#     Given an undirected graph and an integer M. The task is to
#    Given an undirected graph and an integer M. The task is to
#   Given an undirected graph and an integer M. The task is to
#  Given an undirected graph and an integer M. The task is to
#  determine if the graph can be colored with at most M colors
#   determine if the graph can be colored with at most M colors
#    determine if the graph can be colored with at most M colors
#   such that no two adjacent vertices of the graph are colored
#  such that no two adjacent vertices of the graph are colored
# such that no two adjacent vertices of the graph are colored
#      with the same color. Here coloring of a graph means the
#       with the same color. Here coloring of a graph means the
#        with the same color. Here coloring of a graph means the
#        assignment of colors to all vertices. Print 1 if it is
#       assignment of colors to all vertices. Print 1 if it is
#      assignment of colors to all vertices. Print 1 if it is
#     assignment of colors to all vertices. Print 1 if it is
#    assignment of colors to all vertices. Print 1 if it is
#   assignment of colors to all vertices. Print 1 if it is
#  assignment of colors to all vertices. Print 1 if it is
# assignment of colors to all vertices. Print 1 if it is
#             possible to colour vertices and 0 otherwise.
#              possible to colour vertices and 0 otherwise.
#               possible to colour vertices and 0 otherwise.
#                possible to colour vertices and 0 otherwise.
#                 possible to colour vertices and 0 otherwise.
#                  possible to colour vertices and 0 otherwise.
#                   possible to colour vertices and 0 otherwise.
###############################################################~
# Expected Time Complexity: O( M^N )
# Expected Auxiliary Space: O( N )
###############################################################_
