############ ####### ###########################################
############ ####### ###########################################
############ ####### ###########################################
#######                  #######################################
####### @@@@@@@@@@@@@@@@ #######################################
####### @@@@@@@@@@@@@@@@ ######                                  
####### @@@@@@@@@@@@@@@@ ###### |||||||||||||||| ###############
####### @              @ ###### |              | ###############
####### @              @ ###### |              | ###############
####### @@@@@      @@@@@ ###### |  |||    |||  | ###############
####### @@@@@      @@@@@ ###### |              | ###############
####### @              @ ###### |              |                
#######                  ###### |  |||    |||  | ###############
############ ################## |              | ###############
############ ##################                                 
############ ###################################################
#########                  #####################################
######### _              _ ###                  ################
######### _____      _____ ### >              > ################
######### _____      _____ ### >>>>>>    >>>>>> ################
######### _____      _____ ### >>>>>>    >>>>>> ################
######### _____      _____ ### >>            >>                   
######### _              _ ### >>            >> ################
######### _              _ ### >>>>>>    >>>>>> ################
######### ________________ ### >              > ################
######### ________________ ### >              > ################
#########                  ### >>>>>>>>>>>>>>>> ################
########### ## ## ## #########                                   
########### ## ## ## ###########################################
########### ## ## ## ###########################################
########### ## ## ## ###########################################
# 没 有 道「理」！ Няма [ логика ]!
################################################################
################################################################
################################################################
################################################################
# Sort Elements by Decreasing Frequency
################################################################
# Given an array of integers arr[], sort the array according t o
# t h e frequency of elements, i.e. elements t h a t have higher
# frequency comes first. I f the frequencies of two elements are
# the same, then the smaller number comes first.
################################################################
# Input: arr[] = [5, 5, 4, 6, 4]
# Output: [4, 4, 5, 5, 6]
################################################################
# 1 ≤ arr.size() ≤ 10⁵
# 1 ≤ arr[i] ≤ 10⁵
################################################################
################################################################
################################################################
################################################################
from collections import Counter
################################################################
################################################################
################################################################
################################################################
####  ####  ####  ####  ########################################
####  ####  ####  ####  ########################################
####  ####  ####  ####  ########################################
class Solution:
    def sortByFreq( self, a ):
        d = Counter( a )
        ls = []
        for v, n in sorted( d.items(),
                            key=lambda x: (x[1], -x[0]),
                            reverse=True ):
            ls.extend( [v] * n )
        return ls
################################################################
# <> 2.1.40: Horizontal conveyor b e l t moves with a velocity u.
# A washer flies onto the belt tangentially to it, t h e initial
# velocity v of which is perpendicular to t h e edge of the belt.
# Find the maximum width of the b e l t at which the washer will
# reach its other e d g e if the coefficient of friction between
# the washer and the belt is μ.
################################################################
#                         # from a system moving with u:
#             _______     # ( t o p v i e w ) | The friction f
#            /      /  |  #      C   CB = v   | will be directed
#    v      / 7    /_  |  #     /|   AB = u   | along CA
#  ----->  / / u  / /  |  #    / | ∠ACB = α y | tgα = u/v
#         / /    / /   v  #   /  |          | | On y projection
#        /      / /   g   #  <---v          | | we'll have 
#       /______/ /        # A     B    x----+ | fcosα so
#        /      /         # ||||||||||||||||||| y = ½at² = 
#       /______/          # = v²/2a, where a is the y component:
#                         # ma = fcosα = μmgcosα, zo 
#                         # y = v²/2μgcosα = v²√(1 + tg²α)/2μg =
########################### = v²√(1 + u²/v²)/μg = 
########################### = v√(v² + u²)/2μg                  «
################################################################
################################################################
import sys
################################################################
def parse_ints():
    return tuple( map( int, input().split() ))
################################################################
# 7. [M23] Given that x and y are integers, prove the laws of
# exponents, starting from the definition given by Eq. (4).
#
# "Throughout this section, let the letter b stand for a
#  positive real number. If n is an integer, then bⁿ is defined
#  by the familiar rules:
#    b⁰ = 1, bⁿ = bⁿ⁻¹b if n > 0, bⁿ = bⁿ⁺¹/b if n < 0.
#  It is easy to prove by induction that the laws of exponents
#  are valid:
#    bˣ⁺ʸ = bˣbʸ, (bˣ)ʸ = bˣʸ
#  whenever x and y are integers."
#
#  Ok this is from Knuth books, I found the phrase "easy to
#  prove" a bit offensive:). Nevermind these books are extremely
#  hard to read, but it's worth the effort( I hope ), so ok this
#  proof seems a bit tedious to be honest
#
#  The plan of campain is very simple fix x to be any integer
#  and make an induction on y, but we have to consider two
#  scenarios y ≥ 0 and y ≤ 0
#  y ≥ 0)
#  1) check for y = 0:
#     bˣ⁺⁰ = bˣ = bˣb⁰, be coz b⁰ = 1 by definition
#  2) assume bˣ⁺ʸ = bˣbʸ for some y
#  3) prove bˣ⁺ʸ⁺¹ = bˣbʸ⁺¹:
#     from the definition regardless wheter x + y is positive or
#     negative we have bˣ⁺ʸ⁺¹ = bˣ⁺ʸb, by assumption bˣ⁺ʸ = bˣbʸ,
#     so bˣ⁺ʸ⁺¹ = bˣbʸb = bˣbʸ⁺¹, again by definition
#  As a corollary of this prove we have the following:
#  1 = b⁰ = bˣ⁻ˣ = bˣb⁻ˣ, so b⁻ˣ = 1/b⁻ˣ
#  y ≤ 0)
#  Here we can write bˣ⁻ʸ = bˣb⁻ʸ = bˣ/bʸ, where y ≥ 0
#  1) check for y = 0:
#     bˣ⁻⁰ = bˣ = bˣ/b⁰
#  2) assume bˣ⁻ʸ = bˣ/bʸ
#  3) prove bˣ⁻ʸ⁻¹ = bˣ/bʸ⁺¹
#     by definition bˣ⁻ʸ⁻¹ = bˣ⁻ʸ/b = bˣ/bʸb( by assumption ) =
#     bˣ/bʸ⁺¹, by definition                                   «
#  Same for the other law (bˣ)ʸ = bˣʸ ..
# 
################################################################
################################################################
################################################################
################################################################
with open( 'NPUT', 'r' ) as f:
    sys.stdin = f        
    a = parse_ints()
    print( Solution().sortByFreq( a ))
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                 1110 / 1110
# Points Scored:                                           4 / 4
# Your Total Score:                                         1922 
# Time Taken:                                               0.98
# DeBuga™: Do we l i v e in a simulation? Who knows! Is there an
# existence outside this reality? Again w e ' d probably have to
# ask some YouTuber. It seems the definition of l i f e can't be
# absolute, but must be defined in context. T o define what life
# is, we f i r s t have to define the environment a n d how life
# interacts with i t. For example, a computer v i r u s might be
# considered alive within the context o f a computer system. But
# does a r e a l bug exist i n a computer program? Obviously not
