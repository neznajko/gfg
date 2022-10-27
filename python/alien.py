                            ########
########################(ø)#################(ø)###########(o)##=
# Alien Dictionary #####   ## ## ##### #####   ###### # ##   ###
# ##### # ###### #######   ## ## ##### #####   ###### # ## Ś ##_
# ##### # ###### #######   ## ## ##### #####   ###### # ##   ###
# ##### # ###### ####### Y ## ## ##### #####   ###### # ##   ###
# ##### # ###### #######   ## ## ##### ##### ë ###### # ##   ###
# ##### # ###### #######   ## ## ##### #####   ###### # ##   ###
# Given a sorted dictionar of an alien languag having N word and
# - -------- --------- -- ######## ----------. ---- ### ----- --
# # ^^^^^^^^ --------- "" -------- ----------. ==== ### ''''' --
# - -------- ######### -- ________ ##########. ---- ### ----- --
# - -------- --------- -- -------- ----------. ---- --- ----- --
# k starting alphabets of standard dictionary. Find the order of
# __________ __ ___ _____ ######### > > > > > > > > > > > > > > >
# __________ ## --- _____ ________. ____________________________
# __________ __ ___ _____ ________. ___________________________-
# characters in the alien language. ###########   #######   ####
#######################   #####   #############   #######   ####
#######################   #####   ############# r #######   ####
#######################   #####   #############   ####### , ####
####################### e #####   #############   #######   ####
#######################   ##### e #############   #######   ####
#######################   #####   #############   #######   ####
# Note: Many orders may b possibl for a particula test case thus
#   ######### _ ############################   #################
#   ######### _ ############################   #################
#             _ ############################   #################
############# _ ############################   #########       l
############# n ###             _   ########   #########  =#####
############# _ ###  Œ Ŵ       | |  ########              =#####
############# _ ############################ =##################
############# _ ############################ =##################
############# _ ############################ =##################
############# _ ############################ =##################
# you may retur any valid order and output wil be 1 if the order
# of string returned by the function is correct, else 0 denoting 
# incorrect string returned. ###################################
################################################################
# Example:                                                     1
# Input:                                            N = 5, K = 4
#                       dict = {"baa","abcd","abca","cab","cad"}
# Output:                                                      1
# Explanation:    Here order of characters is 'b', 'd', 'a', 'c',
#      note that words are sorted and in the given language "baa"
#     comes before "abcd", therefore 'b' is before 'a' in output.
#                             Similarly we can find other orders.
################################################################
# Your Task: You don't need to read or print anything. Your task
# is to complete the function findOrder() which takes the string
# array dict[, its size N and the intege K as input paramete and
# ---------   ------------------------ r -----------------   ---                
# =========   ========================   =================   ===
# _________   ________________________   _________________   ___
# ,,,,,,,,, ] ,,,,,,,,,,,,,,,,,,,,,,,,   ,,,,,,,,,,,,,,,,,   ,,,
# :::::::::   ::::::::::::::::::::::::   ::::::::::::::::: r :::
# *********   ************************   *****************   ***
# returns a string denoting the order of characters in the alien
# language.
################################################################
# Expected Time Complexity: O(N*|S|+K) where |S| denotes maximum
#                           length.
# Expected Space Compelxity: O(K)
################################################################
# Constraints: 1 ≤ N ≤ 300, 1 ≤ K ≤ 26, 1 ≤ Length of words ≤ 50
################################################################
BAS = ord( 'a' )
################################################################
def off(  ch ): return ord( ch ) - BAS
def cha( off ): return chr(  off + BAS )
################################################################
# Trie 01: 698 / 1102 Time Limit Exceeded
# Trie 02: 256 / 1102 ( After optimization )
# Trie 03: 320 / 1102 Ok let's check the Hint
# Trie 04: 721 / 1102 One last time, before that
# Grph 05: IndexError
################################################################
class Trie: #                                     retrieval tree
    # Topological sorting stuff
    succ = None
    pred = None
################################################################
def relate( s, t ):
    j = 0
    try:
        while s[j] == t[j]: j += 1
        Trie.succ[ off( s[j] )].add( off( t[j] ))
        Trie.pred[ off( t[j] )].add( off( s[j] ))
    except IndexError: pass
################################################################
# Test Cases Passed: 1102 / 1102 Wow! That is an old problem I'd
# Total Points Scored: 8 / 8     gave up long time ago wanting a
# Your Total Score: 930          Trie solution now, failing five
# Total Time Taken: 0.79         times 4 before failures I don't 
# Your Accuracy: 10%             remember the reasons, but Oky:)
# Attempts No.: 10 <------You--------can't--------touch----this!
################################################################
class Solution:
    def findOrder( self, dict, n, k ): # in this chaos
        Trie.succ = [ set() for j in range( k )]
        Trie.pred = [ set() for j in range( k )]
        for j in range( 1, len( dict )):
            relate( dict[ j - 1 ], dict[ j ])
        return topsort()
###############################################################=
def topsort():
    """ Knuth """
    lst = []
    que = []
    cunt = list( map( len, Trie.pred ))
    for j, c in enumerate( cunt ):
        if not c: que.append( j )
    while len( que ) > 0:
        j = que.pop()
        lst.append( cha( j ))
        for i in Trie.succ[ j ]:
            cunt[ i ] -= 1
            if not cunt[ i ]: que.append( i )
    return "".join( lst )
###############################################################_
# log: - Do you know why Musk bought twitter? Be cos of fox news
# flaterings. Don't trust fox and don't trust news!
###############################################################_
print( Solution().findOrder(
    [ "baa", "abcd", "abca", "cab", "cad" ],
    # "baa", "abcd", "abca", "cab", "cad"
    5,
    4
    ))
################################################################
#  Ā   ā   Ă   ă   Ą   ą   Ć   ć   Ĉ   ĉ   Ċ   ċ   Č   č   Ď   ď
#  Đ   đ   Ē   ē   Ĕ   ĕ   Ė   ė   Ę   ę   Ě   ě   Ĝ   ĝ   Ğ   ğ
#  Ġ   ġ   Ģ   ģ   Ĥ   ĥ   Ħ   ħ   Ĩ   ĩ   Ī   ī   Ĭ   ĭ   Į   į
#  İ   ı   Ĳ   ĳ   Ĵ   ĵ   Ķ   ķ   ĸ   Ĺ   ĺ   Ļ   ļ   Ľ   ľ   Ŀ
#  ŀ   Ł   ł   Ń   ń   Ņ   ņ   Ň   ň   ŉ   Ŋ   ŋ   Ō   ō   Ŏ   ŏ
#  Ő   ő   Œ   œ   Ŕ   ŕ   Ŗ   ŗ   Ř   ř   Ś   ś   Ŝ   ŝ   Ş   ş
#  Š   š   Ţ   ţ   Ť   ť   Ŧ   ŧ   Ũ   ũ   Ū   ū   Ŭ   ŭ   Ů   ů
#  Ű   ű   Ų   ų   Ŵ   ŵ   Ŷ   ŷ   Ÿ   Ź   ź   Ż   ż   Ž   ž   ſ
################################################################
####                                                        ####
