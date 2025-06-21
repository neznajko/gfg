################................================////////////////
################................================////////////////
################................=  =============////////////////
################................ ==  ===========////////////////
################............... =  ==  =========////////////////
################............... =    == ========////////////////
################............... =      = =======////////////////
################............... =      = =======////////////////
#######                         =      =              //////////
###### #########................=      =========//////  ////////
##### #                                               // ///////
###### ##                                               / //////
#######  #######................=      =========//////// ///////
#########                       =      =                ////////
################..  ........... =      = =======////////////////
################  .. ......... .       = =======////////////////
##############  ..  .  ....... .       = =======////////////////
############# ##     ..  ..... .      = ========////////////////
############ #         ..  .. .       = ========////////////////
############# #          ..   .       = ========////////////////
############## #.          ...       = =========////////////////
###############  ..                  = =========////////////////
################.  ..               =  =========////////////////
################...  ...            ===    =====////////////////
################.   ...                ====    =////////////////
##############   ...                       ====     ////////////
##########    ##.            ...=              =////      //////
#####     ####            ...    ====               ////// /////
#### #####             ...   ...=    ====                 / ////
### #               ...   ......=====    =====          // /////
#### ##         ....   .........=========     ==////  //  //////
#####  ##  #####    ............==============      //  ////////
#######  ##     ................================////  //////////
#########  #####................================////////////////
################................================////////////////
################................================////////////////
################................================////////////////
# ス カ ー ト の「丈」が み じ か い 。[Дължината] на полата е къса
################################################################
################################################################
################################################################
################################################################
# Median in a row-wise sorted Matrix
################################################################
# Given a row-wise sorted matrix where the number of r o w s and
# c o l u m n s is always odd, f i n d the median o f the matrix
################################################################
# Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
# Output: 5
# Explanation: Sorting matrix elements gives us
# {1,2,3,3,5,6,6,9,9}. Hence, 5 is median
################################################################
# 1 <= mat.size(), mat[0].size() <= 400
# 1 <= mat[i][j] <= 2000
################################################################
# Time Complexity: O(n * log(m) * log(maxVal - minVal))
# Auxiliary Space: O(1)
################################################################
################################################################
################################################################
################################################################
# 天気 てんき weather
# 暑い あつい hot
# きれいな beautiful
# 海 うみ sea
# 泳ぐ およぐ swim
#
# どんな what kind of ..
# 好く すく like
# 一緒に いつしょに together
# 難しい むずかしい difficult
# 大丈夫 だいじょうぶ it's ok
################################################################
################################################################
################################################################
################################################################
def binsrch( a, key ):
    l, u = 0, len( a ) - 1
    while l <= u:
        m = ( l + u ) // 2
        if a[ m ] <= key:
            l = m + 1
        else:
            u = m - 1
    return l

################################################################
from math import inf
################################################################
def count( mat, key ):
    c = 0
    value = inf
    for r in mat:
        j = binsrch( r, key )
        c += j
        if j < len( r ):
            value = min( value, r[ j ])
    return c, value

###############################################################
###############################################################
###############################################################
###############################################################
# 18. If c > 0, prove that (ca,cb) = c(a,b).
#
# From a previous exercise w e had to prove that if d and e are
# some integers and they b o t h divide each other, d|e and e|d,
# then d = ±e, h e r e becoz d := (ca,cb) and e := c(a,b) a r e
# positive, b e i n g greatest common divisors of ca,cb and a,b
# respectively, we n  e  e  d only t o show t h a t d|e and e|d:
#
# By theorem 1.2, if n o t mistaken, the GCD of two numbers can
# be r e p r e s e n t e d as a l i n e a r combination of them:
# d = (ca,cb) = cau + cbv, for s o m e integers u and v, on the
# other hand a = (a,b)f and b = (a,b)g for some f and g, be coz
# (a,b) is the GCD of a and b, zo d = c(a,b)(uf + vg), that i s
# e|d.                                                        «
#
# Now the o t h e r way around e = c(a,b) = c(as + bt) for some
# integers s and t, z o e = cas + cbt, and again be coz (ca,cb)
# i s the GCD of ca and cb, e = (ca,cb)hs + (ca,cb)it, for some
# h and i zo e = (ca,cb)(hs + it), that is d|e                «
###############################################################
###############################################################
###############################################################
###############################################################
def makeflat( mat ):
    flat = []
    for r in mat:
        flat.extend( r )
    return sorted( flat )

################################################################
################################################################
################################################################
################################################################
# This problem c a n be solved in O(n²) by merging the rows, but
# the efficient solution is a bit obscure, gfg gives the t i m e
# complexity so it is possible to figure the solution by reverse
# engineering this formula: O(n * log(m) * log(maxVal - minVal)),
# the term n log(m) means we are doing binary search on each row,
# the term log(maxVal - minVal) means we are doing binary search
# on the value range
################################################################
class Solution:
    def median( self, mat ):
        n = len( mat )
        m = len( mat[ 0 ])
        halflife = n * m // 2
        l = min([ r[ 0 ] for r in mat ])
        u = max([ r[-1 ] for r in mat ])
        copy = mat[0][0]
        while l <= u:
            m = ( l + u ) // 2
            c, value = count( mat, m )
            if c == halflife:
                return value
            if c < halflife:
                l = m + 1
                copy = value
            else:
                u = m - 1
        return copy

################################################################
################################################################
# 2.1.41: Which washer, rotating around its a x i s or not, will
# t  r  a  v  e  l a greater distance before stopping on a rough
# horizontal surface? The initial speed of t h e centers o f the
# washer is the same
################################################################
#################### Lets assume t h e washer is moving on right 
#################### and rotating cw then the velocity at points
########    ######## A and B will be directed as follows:
######        ######       . B       Becoz the friction force is
#####          #####     .`. B`.     opposite t o velocity a n d
##### A      B #####   .`.`   `.`.   becoz force is a vector the
#####          ##### A`.`       `.`. sum force size will be less
######        ###### A`           `. then 2f w h e r e f i s the
########    ########                 friction force at A a n d B
#################### S o in rotation the resulting friction will 
#################### be less then t h e case without rotation so 
#################### spinning washer will travel larger distance
################################################################
### ##### ##### ##### ##########################################
##   ###   ###   ###   #########################################
#     #     #     #     ########################################
import sys
################################################################
################################################################
################################################################
################################################################
def parse_ints():
    numbers = list( map( int, input().strip().split()))
    return numbers

################################################################
################################################################
################################################################
################################################################
# 42. A norepeatword is a sequence of at least one (and possibly
# all) of the usual 26 letters a,b,c,...,z, with repetitions not
# allowed. For e x a m p l e, "course" i s a norepeatword, b u t
# "statistics" is not. Order matters, e.g., "course" i s not the
# same a s "source". A norepeatword is chosen randomly, with all
# norepeatwords equally likely. Show that t h e probability that
# it uses all 26 letters is very close to 1/e
#
# O k if we have k letters we can make k! words, and we can pick
# k l e t t e r s from alphabet i n C(26,k) = 26!/k!(26-k)! ways
# so the total sample space size is:
# sum{k=1,26} 26!/(26-k)! = 26!sum{k=0,25} 1/k!
# T h e number of 26 nonrepeatwords is 26! so the probability is:
# P = 1/sum{k=1,26} 1/k!, we c a n use Taylor expansion on eˣ to 
# show t h a t e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + 1/5! + ... so
# sum{k=0,25} 1/k! is very close to e, hence P = 1/e           «
################## ####   ##############    ############## #####
################# ####   ##############    ############## ######
################ ####   ##############    ############## #######
############### ####   ##############    ############## ########
############## ####   ##############    ############## #########
############# ####   ##############    ############## ##########
with open( "NPUT", "r" ) as f:
    sys.stdin = f
    n = parse_ints()[ 0 ]
    m = parse_ints()[ 0 ]
    mat = [ parse_ints() for _ in range( n )]
    print( Solution().median( mat ))

################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                 1117 / 1117
# Points Scored:                                           8 / 8
# Your Total Score:                                         1938
# Time Taken:                                               1.14
