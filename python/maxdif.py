#                                                        
#   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 
#    | | | | | | | |    | | | | | | | | 
#   ::::.:::.:::.:::    ::::::::::::::::
#   2222222222222222    2222222222222222
#   0000                            0000
#   <<<<<<<<<<<<<<<      <<<<<<<<<<<<<<<
#   7777777777777          7777777777777
#   -----------    -    -    -----------
#   %%%%%%%%    %%%%    %%%%    %%%%%%%%
#   ****    ****            ****    ****
#   ----------------    ----------------
#   ````````````````    ````````````````
#   ____________________________________  本（ホン）
#                   
########################################################
# Maximum Difference
########################################################
# Given array A[] of integers, the task is to complete the
# function findMaxDiff which finds the maximum absolute difference
# between nearest left and right smaller element of every element
# in array.If the element is the leftmost element, nearest smaller
# element on left side is considered as 0. Similarly if the element
# is the rightmost elements, smaller element on right side
# is considered as 0.
########################################################
# Input : arr[] = {2, 4, 8, 7, 7, 9, 3}
# Output: 4
# Left smaller  LS[] = {0, 2, 4, 4, 4, 7, 2}
# Right smaller RS[] = {0, 3, 7, 3, 3, 3, 0}
# Maximum Diff of abs(LS[i] - RS[i]) = 7 - 3 = 4 
########################################################
# 1 <= A[] <= 100
########################################################
########################################################
########################################################
########################################################
def left_smaller( a ):
    stk = []
    ls = []
    for _ in a:
        while stk and stk[-1] >= _:
            stk.pop()
        if not stk:
            ls.append( 0 )
        else:
            ls.append( stk[-1] )
        stk.append( _ )
    return ls
########################################################
########################################################
########################################################
########################################################
class Solution:
    def findMaxDiff( self, a, n ):
        ls = left_smaller( a )
        rs = left_smaller( reversed( a ))
        t = max( zip( ls, reversed( rs )),
                 key=lambda t: abs( t[1] - t[0] ))
        return abs( t[1] - t[0] )
########################################################
if __name__ == '__main__':
    a = [ 2, 4, 8, 7, 7, 9, 3 ]
    print( Solution().findMaxDiff( a, len( a )))
########################################################
# jin 人 じん　ruy 類 るい　gaku 学　がく
# じんるいがく、じんるいがく、じんるいがく、じんるｒがく
# se(e) 政 せい　ji 治　じ
#　せいじ、せいじ、せいじ、せいじ、せいじ、せいじ、せいじ
# 文 bun 学 gaku( literature )
#　ぶんがく、ぶんがく、ぶんがく、ぶんがく、ぶんがく、ぶんがく
# 歴 reki 史 shi ( history )
#　れきし；れきし、れきしーれきし｀れきし＿れきし：れきし
########################################################
# Test Cases Passed:                           100 / 100
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1318
# Total Time Taken:                                 0.03
