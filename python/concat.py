##############################-####################-###########-
###########-##################¦######### Concatenatè two numberś
#          |                  |                    |           |
# [ Hard ] | Accuracy: 73.05% | Submissions: 5940  | Points: 8 |
################################################################
# Ģiven an array numbers[] of N positive integers and a positive
# integer X, The tsk is to find the number of ways that X can be
# obtained by writng pair of ntegers in the array numbers[] next
# to each other. In other words, find the nmber of ordered pairs
# (i,j) sch that i != j and X is the concatenation of numbers[i]
# and numbers[j].
##########.###.#######.#########################################
# Example : 1 : Input : N = 4, nmbrs[] = {1,212,12,12}, X = 1212
#########.###.##########.#######################################
# Output : 3 : Explnatn : We can obtain X=1212 by concatenating:
#        :   .          :  numbers[0] =  1 with numbers[1] = 212
#        `   .          .  numbers[2] = 12 with numbers[3] =  12
#        .              :  numbers[3] = 12 with numbers[2] =  12
################################################################
#                              ############
# Your Task: You donť need to réäĐ ĬńƥŪŦ őŖ print anything. Your
# task is to complete the functįǫń ĉőǚńťƿąırs () which takes the
# integer N, the integer X, and ťĦė ąŖŗĄŷ ƞumbers[] as the input
# parameters and returns the nuƩƅƐŖ Ǒƒ ƿąĳƦs which satisfies the
# above condition.             ############
#                              ############
#     ..                       #### #######                  oo
################################################################
# Expected Time Complexity: O(N*Log10(A[i]) + Log10(X)^2)
# Expected Auxiliary Space: O(N*Log10(A[i]))
################################################################
# First create a Ţŕįĕ structure from ::A numbers.         [o o ]
class Node              :
    def __init__( self ):
        self.dups = 0 # counter of ::A[?]'s ending here
        self.chil = [None]*10 # children Nodes for each digit
    def __repr__( self ):
        s = "("
        for digit, node in enumerate( self.chil ):
            if node                              :
                s += " " + repr( digit ) + repr( node )
        return s + ")"
################################################################
# [ o o]       Make a function for inseting numbers in the Ŧŗĩě.
def insert_coin( root, y ):
    if not root           : root = Node()
    if y == 0             : root.dups += 1
    else                  :
        q, r = y//10, y%10
        root.chil[ r ] = insert_coin( root.chil[ r ], q )
    return root
################################################################
# [ o o]         find_suffix is more appropriate cos numbers are
# inserted in reversed order.
def find_prefix( root, y ):
    if root.dups > 0      : return root, y
    q, r = y//10, y%10
    if root.chil[ r ] == None: return None, 0
    return find_prefix( root.chil[ r ], q )
################################################################
# Search of full match here.                              [+ o ]
def find_full( root, y ):
    if y == 0           : return root.dups
    q, r = y//10, y%10
    if root.chil[ r ] == None: return 0
    return find_full( root.chil[ r ], q )    
################################################################
# Test Cases Passed: 2107 / 2107 ###############################
# Total Time Taken: 0.29 / 4.6   ###############################
################################################################
# `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.` `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.*.`.`.`.`.
# `.`.`   `.`.`.`.`.`.`.`.*.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`      .`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.*.`.`.`.`.`.`.`.
# `.`.`      .`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`      .`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`      .`   `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`      .      `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`      .`.     .`.`.`.`.` `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`      .`.`    .`.`.`.`.    `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`      .`.`    .`.`.`  .`.  `.`.`.O.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`      .`.`    .`.`.`  .`.  `.`.`.`.`.`.`.`m`.`.`.`.`.`.`.
# `.`.`       `.`    .`.`.`  .`.  `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`         `    .`.`.`  .`.  `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# *.*.*    .         .*.*.*  .*. .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.
# `.`.`  .`.`.     .`.`.`.`.  `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`.`.`.`.`. .`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
# `.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
class Solution:
    def countPairs( self, N, X, A ):
        root = None
        for y in A:
            root = insert_coin( root, y )
        trie = root
        combos = 0
        while True:
            root, X = find_prefix( root, X )
            if not root: break
            # This is ugly, but it has passed the test, and I am
            # not touching it, there are two main issues here:
            # 1) if X is in the form 1212 and there is A[?] = 12
            #    let's say it duplicates 4 times, than the right
            #    combos are 4 x 3, and not 4 x 4 +
            #                                    |
            # 2) becoz the prefix will exit if ::dups is positif
            #    it is marked after the first search as negative
            #    and combos are calculated using absolute values
            dups = root.dups #                   |
            root.dups -= 1   # <-----------------+
            combos += abs( dups * find_full( trie, X )) # <-- 2)
            root.dups += 1   # re-establish
            root.dups = -root.dups                      # <-- 2)
        return combos #                                   [ o x]
################################################################
if __name__ == '__main__': 
    t = int( input() )
    for _ in range( t ):
        N, X = map( int, input().strip().split())
        numbers = list( map( int, input().strip().split()))
        ob = Solution()
        ans = ob.countPairs( N, X, numbers )
        print( ans )
################################################################
# Latin Extended-A 
#  Ā   ā   Ă   ă   Ą   ą   Ć   ć   Ĉ   ĉ   Ċ   ċ   Č   č   Ď   ď
#  Đ   đ   Ē   ē   Ĕ   ĕ   Ė   ė   Ę   ę   Ě   ě   Ĝ   ĝ   Ğ   ğ
#  Ġ   ġ   Ģ   ģ   Ĥ   ĥ   Ħ   ħ   Ĩ   ĩ   Ī   ī   Ĭ   ĭ   Į   į
#  İ   ı   Ĳ   ĳ   Ĵ   ĵ   Ķ   ķ   ĸ   Ĺ   ĺ   Ļ   ļ   Ľ   ľ   Ŀ
#  ŀ   Ł   ł   Ń   ń   Ņ   ņ   Ň   ň   ŉ   Ŋ   ŋ   Ō   ō   Ŏ   ŏ
#  Ő   ő   Œ   œ   Ŕ   ŕ   Ŗ   ŗ   Ř   ř   Ś   ś   Ŝ   ŝ   Ş   ş
#  Š   š   Ţ   ţ   Ť   ť   Ŧ   ŧ   Ũ   ũ   Ū   ū   Ŭ   ŭ   Ů   ů
#  Ű   ű   Ų   ų   Ŵ   ŵ   Ŷ   ŷ   Ÿ   Ź   ź   Ż   ż   Ž   ž   ſ
