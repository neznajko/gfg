#   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   
#  /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /
# /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   / 
#/   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /  
#   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   
#  /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /
# /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   / 
#    \...\...\...\...\...\...\...\...\...\...\...\...\...\...\...\..
#    .\...\...\...\...\...\...\...\...\...\...\...\...\...\...\...\.
#    ..\...\...\.. \   \   \   \   \   \   \   \   \   \...\...\...\
#    ...\...\...\.  \   \  .\...\...\...\...\.  \   \  .\...\...\...
#    \...\...\...\   \   \ ..\...\...\...\...\   \   \ ..\...\...\..
#    .\...\...\...\   \   \   \   \   \   \   \   \   \...\...\...\.
#    ..\...\...\...\...\...\...\...\...\...\...\...\...\...\...\...\
#    ...\...\...\.  \   \   \   \   \   \   \   \   \  .\...\...\...
#    \...\...\...\   \   \ ..\...\...\...\...\   \   \ ..\...\...\..
#|||||||         |||||||||||||||||||         |||||||||||||
#|||||||                                     |||||||||||||
#|||||||         |||||||||||||||||||         |||||||||||||
#|||||||         |||||||||||||||||||         |||||||||||||
#|||||||                                     |||||||||||||
#|||||||         |||||||||||||||||||         |||||||||||||
#|||||||         |||||||||||||||||||         |||||||||||||
#############                                     ############## 
################################################################ 
####################  #################  #######################  
###################  #  #############      ##################### 
#################  ##  #  #########          ################### 
###############  ##  ##  ##########          #  ################
#############  ##  ##  ##############      #    #  #############
##########  ###  ##  ##################  #    #    ##  #########
######  ####  ###  #######################  #    ##    ###  ####
##  ####  ####  #############################  ##    ###    ####
####  ####  #####################################  ###    ######
######  ##############################################  ########
################################################################
################################################################
# 職「員」以 外 立 入 禁 止 Само за оторизиран [ персонал ]
################################################################
# Aggressive Cows
################################################################
# You are given an array with unique elements of stalls[], which
# denote the position of a stall. You are also given a n integer
# k which denotes the number of aggressive cows. Your task is to
# assign stalls to k cows such that the minimum distance between
# any two of them is the maximum possible
################################################################
# Input: stalls[] = [1, 2, 4, 8, 9], k = 3
# Output: 3
# Explanation: The f i r s t cow can be placed at stalls[0], the
# second cow can be placed at stalls[2] and the third cow can be
# placed at stalls[3].  The minimum distance between c o w s, in
# this case, i s 3, which also is the largest among all possible
# ways.
################################################################
# 2 <= stalls.size() <= 10⁶
# 0 <= stalls[i] <= 10⁸
# 2 <= k <= stalls.size()
################################################################
# 郵 mail ユウ
# 便 tidings ビン
# 局 office キョク
# 葉書 postcard はがき
# まで until
# じゃあ so ....
# 切手 stamp きって
# 枚 counter for flat objects まい
# それから and then
# 願 to request ねがう 
################################################################
# 19. If a|(b + c) a n d (b,c) = 1, prove that (a,b) = 1 = (a,c)
#
# F r o m a|b + c we have b + c = au, f o r some integer u, from
# (b,c) = 1, w e have 1 = bv + cw; v,w ∈ Z , z o bv + cv = auv =
# 1 - cw + cv = 1 - c(w - v), zo 1 = cs + at f o r some integers
# s and t; (a,c) should divide b o t h sides of this equation zo
# (a,c) = 1, similar for (a,b)                                 «
################################################################
from math import inf
################################################################
def prev_dst( stalls, j ):
    return abs( stalls[ j ] - stalls[ j - 1 ])
################################################################
def range_report( stalls ):
    mindst = inf
    for j in range( 1, len( stalls )):
        mindst = min( mindst, prev_dst( stalls, j ))
    return stalls[ 0 ], stalls[ -1 ], mindst
################################################################
# 8.[25] Let m b e a positive integer. Prove that every positive
# real number u has a u n i q u e positive mth root b y giving a
# method t o construct successively the values n, d₁, d₂, ... in
# the decimal expansion of the root
#
# This is t h e Newton method for finding roots so if we want to
# find ᵐ√u, then we can write:
# ᵐ√u = x, u = xᵐ, f(x) = xᵐ - u = 0, this is a pol y n  o m ial
# equation, don't know very much details, but we start from some
# initial point x₀ = u and calculate t h e derivative of f at x₀,
# it will cross the x axis at some point x₁ which is the n e x t
# approximation and so forth so the formula will be:
# 
# f'(xₙ) = f(xₙ)/(xₙ - xₙ₊₁), zoooooooo xₙ₊₁ = xₙ - f(xₙ)/f'(xₙ)
# xₙ₊₁ = xₙ - (xₙᵐ - u)/mxₙᵐ⁻¹
#
# let's m = 3, u = 2 a n d start with x₀ = 2, that is we want to
# compute ³√2 say up to the 6 digits a f t e r the decimal point
# Pluging in x₀ = 2 into the formula will give:
# x₁ = 1.5
# x₂ = 1.2962962962962963
# x₃ = 1.2609322247417485
# x₄ = 1.2599218605659261
# x₅ = 1.2599210498953948
#
# After the fifth iteration there is n o change in the first six
# digits after the decimal point zo ³√2 = 1.259921 ...    
################################################################
def ck( stalls, m, k ):
    dst = 0
    for j in range( 1, len( stalls )):
        dst += prev_dst( stalls, j )
        if dst >= m:
            k -= 1
            if k == 0:
                return True
            dst = 0
    return False
################################################################
################################################################
class Solution:
    def aggressiveCows( self, stalls, k ):
        stalls.sort()
        minpos, maxpos, mindst = range_report( stalls )
        l = mindst
        u = ( maxpos - minpos ) // ( k - 1 )
        while l <= u:
            m = ( l + u ) // 2
            if ck( stalls, m, k - 1 ):
                l = m + 1
            else:
                u = m - 1
        return u
################################################################
# 2.1.42. W h y is it easier to pull o u t a nail that is firmly
# stuck in a log if you simultaneously rotate i t around its own
# axis while pulling it out?
#
################################################################
################################################################
#######   ########` .        #### If we pull and rotate the nail
#####       ######    ` .    ###################################
#### A       #####        ` .### The velocities a t two opposite
####       B #####      . `  ###################################
#####       ######  . `      ##### points A and B will look like
#######   ########`          ###################################
################################# in fig. L  E  F T zo becoz the
#### F R ONT ##### L  E  F T ###################################
################################ frictions are opposite to t h e
################################################################
#### velocity the sum vector force will have length smaller then
################################################################
### the sum of the forces which is the case of non rotating nail
################################################################
################################################################
################################################################
################################################################
def parse_ints(): ##############################################
    numbers=list(map(int,input().strip().split())) #############
    return numbers #############################################
################################################################
# 43. S   h   o   w that for any e   v   e   n   t   s A a n d B,
# P(A) + P(B) − 1 ≤ P(A ∩ B) ≤ P(A ∪ B) ≤ P(A) + P(B):
# For each o f these three inequalities, give a simple criterion
# for when the inequality i s actually an equality (e.g., give a
# simple condition such that P(A ∩ B) = P(A ∪ B) if and only i f
# the condition holds)
#
# If we split the union into d  i  s  j  o  i  n  t sets we have:
# A ∪ B = A\B + B\A + A ∩ B w h e r e A\B is the difference of A
# and B, belongs to A but not t o B, becoz the sets are disjoint
# from the second axiom we can write:
# P(A ∪ B) = P(A\B) + P(B\A) + P(A ∩ B), f r o m here it follows
# that P(A ∩ B) ≤ P(A ∪ B), the equality will hold when A = B  «
#
# Now w e can s    p    l    i    t A and B in s i m i l a r way:
# A = A\B + A ∩ B
# B = B\A + A ∩ B, so
# P(A) + P(B) = P(A\B) + P(B\A) + 2P(A ∩ B) =
# = P(A ∪ B) + P(A ∩ B), so P(A ∪ B) ≤ P(A) + P(B), with
# equality when P(A ∩ B) = 0                                   «
#
# F    r    o    m P(A) + P(B) = P(A ∪ B) + P(A ∩ B), we h a v e:
# P(A) + P(B) - P(A ∩ B) = P(A ∪ B), so the first inequality can
# be rewriten as P(A ∪ B) ≤ 1 which is the first axiom         «
################################################################
################################################################
################################################################
import sys #####################################################
################################################################
with open("NPUT","r") as f: ####################################
    sys.stdin = f ##############################################
    stalls=parse_ints() ########################################
    k=parse_ints()[0] ##########################################
    print(Solution().aggressiveCows(stalls,k)) #################
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                 1111 / 1111
# Points Scored:                                           4 / 4
# Time Taken:                                               1.87
# Your Total Score:                                         1942
