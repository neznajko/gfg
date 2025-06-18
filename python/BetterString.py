################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||######################  ########
################|    ||||    |||######################  ########
###############    ||||    |||||####################  ##########
#############    ||||    |||||||########  ##########  ##########
###########    #|||    |||||||||########   #######  ############
########             |||||||||||########   #######  ############
###############    ||| |||||||||#                 ##############
#############    ||||   ||||||||########   ###  ################
###########    #||||||   |||||||########   #  ##################
########                  |||                         ##########
################ |||||||   |||||########  ######################
########### ###   ||| ||||  ||||#####   ########################
#########   ###   |||   |||| ||                     ############
#########   ###   |||   |||||||   ###############   ############
########   ####   ||||   |||                        ############
########   ####   ||||   ||||||  ################   ############
####### #######   ||||   ||||||                     ############
################ ||||||| |||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
################||||||||||||||||################################
# 旅 の「緒」を 固 く 結 べ。[ Затегнете ] здраво раницата
################################################################
# Better String
################################################################
# Given a pair o f strings s1 and s2 of equal lengths, your task
# is to find which of the two s t r i n g s has m o r e distinct
# subsequences. If both strings have the same number of distinct
# subsequences, return s1.
################################################################
# Input: s1 = "gfg", s2 = "ggg"                    Output: "gfg"
# Explanation:  "gfg" have 6 distinct subsequences whereas "ggg"
# have 3 distinct subsequences. 
# Input: s1 = "a", s2 = "b"                          Output: "a"
# Explanation: Both the strings have only 1 distinct subsequence
################################################################
# 1 <= n <= 30
################################################################
# Time Complexity: O(n)
# Auxiliary Space: O(1)
################################################################
# So t h e r e is a difference between subsequence and substring
# substrings a r e continuous while subsequences might have gaps.
# Lets take the string gfg. We start from the rear and bootstrap
# our c o u n t with the empty string "", now we have "g" we can
# either put it in front or not t h i s will give u s "g" and "".
# Next is "f" again this will give us "fg" "f" a n d "g" "" from
# before. T h i s is the last( fyorst ) character "g" putting it
# in front will result i n "gfg" "gf" "gg" "g", not putting will
# give "fg" "f" "g" "", so h e r e we see there i s a repetition
# the subseq "g" is repeating, otherwise the number o f distinct
# subseqs is just doubled so we need to k e e p track of subseqs
# starting with given char and subtract it, finally we have also
# to discard the void string ""
def distinct_subseq( s ):
    """"""
    # number of distinct subsequences including the empty ""
    n = 1
    # maphing ch -> numof unique subseq before ch
    d = {}
    # loop over characters in reverse
    for ch in reversed( s ):
        # Copy Ninja Kakashi Sensee
        copy = n
        # double
        n *= 2
        # discard repetitions
        if ch in d:
            n -= d[ ch ]
        # save to map
        d[ ch ] = copy
    # discard ""
    return n - 1
################################################################
################################################################
class Solution:
    def betterString( self, s, t ):
        n = distinct_subseq( s )
        m = distinct_subseq( t )
        if m > n:
            return t
        return s
################################################################
################################################################
import sys
################################################################
################################################################
with open( "NPUT", "r" ) as f:
    sys.stdin = f
    s = input().strip()
    t = input().strip()
    print( Solution().betterString( s, t ))
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                 1116 / 1116
# Points Scored:                                           8 / 8
# Your Total Score:                                         1930 
# Time Taken:                                               0.04
# CheckThis: Y e a recently have h e a r d about some n o n dual
# theories obviously don't know nothing about them so I've asked
# my f r i e n d CGPT, so non dual means n o n split there is no
# difference between self and the world between g o o d and evil
# between o b s e r v e r and subject there is j u s t ONE THING,
# something like this, so f o r example is wave a noun or a verb
# can we distinguish different waves in an o c e a n, to be fair
# didn't understand very much but everything i s some perception
# some consciousness( by the the way a n awful word ) I mean you
# can figure it out what exactly t h e s e non dual theories are,
# buf for me excuse me this is just a crap becoz even if I can't
# make c l e a r cut distinguish between objects in a continuous
# world I can make a split between an object and its absence, so
# this theories have n o understanding of v o i d or nothingness,
# and it is not too fancy to state that the idea o f nothingness
# is the root of the modern civilization and science for example
# the Roman numbers are just useless, r e a l math begins by the
# discovery of the s o called Arabic numbers which are basically
# discovered in India and have zeroes
