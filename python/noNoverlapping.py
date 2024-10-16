###############                        
###############                        
###############     ::    ::           
###############    :@@::::@@:::::      
###############   :@  @@@@  @@@@@:     
###############   :@             @:    
###############  :@  @@@@@  @@@@@::    
###############   :@@@@@@@  @@@@@@@:   
###############  :@                @:  
###############   :@@@@  @@@@  @@@@:   
###############    :::@  @::@  @:@@::  
###############    :@@  @: :@  @@  @:  
###############   :@  @@:   :@    @:   
###############    :@@::     :@@@@:    
###############     ::        ::::     
###############                        
###############                                       ..
###############           oo ahead                   oo
############################                        ,,``
# Non-overlapping Intervals                        .. oo
############################                      oo..--
# Givn an 2D array intervals                     ..oo **
# of siz N represntng intvls                    ==,,oo``  
# where intrvls [i]=[starti,                   ..,,'' oo
# endi ), return the minimum                  -- oo ..``
# nmber of intervls you need                 xo ..oo--^^
# to remove to make the rest                ..oo -- ..oo
# of the ntrvls non-ovlapng.               oo ..`` -- ,,
########################################################
# Input: N = 4, intervals [] = {{1,2},{2,3},{3,4},{1,3}}
# Output: 1
# Explanation: {1, 3} can be removed and the rest of the
# intervals are non-overlapping.
########################################################
# Expected Time Complexity: O(NlogN)
# Expected Auxiliary Space: O(1)
########################################################
# 1 ≤ N ≤ 10^5
# |intervalsi| == 2
# -5*10^4 ≤ starti < endi <=5*10^4
########################################################
########################################################
######################################################## 
########################################################
########################################################
########################################################
########################################################
######################################################## 
########################################################
########################################################
# Er ist ein geeignetes Grundmaß (Modul) für weitere
# Streckenermittlungen nach Höhe und Tiefe (siehe hierzu
# auch die Profilfiguren). 
########################################################
# geeignetes -_-_-_-_-_-_-_-_-_-_-_-_-_-_-      suitable
# Grund      ,`,`,`,`,`,`,`,`,`,`,`,`,`,`,          base
# maß        v>v>v>v>v>v>v>v>v>v>v>v>v>v>v   measurement
# weitere    -:-:-:-:-:-:-:-:-:-:-:-:-:-:-       further
# Strecke    \/\/\/\/\/\/\/\/\/\/\/\/\/\/\          path
# Ermittlung '\'\'\'\'\'\'\'\'\'\'\'\'\'\' investigation
# nach       ,.,.,.,.,.,.,.,.,.,.,.,.,.,.,         after
# Höhe       ->->->->->->->->->->->->->->-        height
# Tiefe      ;`;`;`;`;`;`;`;`;`;`;`;`;`;`;         depth
# siehe      ^v^v^v^v^v^v^v^v^v^v^v^v^v^v^           see
# hierzu     ~`~`~`~`~`~`~`~`~`~`~`~`~`~`~          here
########################################################
########################################################
########################################################
######################################################## 
########################################################
########################################################
########################################################
########################################################
########################################################
######################################################## 
########################################################
########################################################
########################################################
# Stefan is saying he is hungry.
# :O Ich habe Hunger.
########################################################
# The chef wants you to enjoy your meal.
# :s Guten Appetit!
########################################################
# Heidi wants her friend to help himself.
# :) Bedien dich bitte.
########################################################
# Peter wants someone to pass him a glass.
# O. Kannst du mir bitte das Wasser reichen?
########################################################
########################################################
########################################################
########################################################
########################################################
######################################################## 
########################################################
from math import inf
########################################################
########################################################
########################################################
########################################################
class Solution:
    def binsrch( self, v, n ): 
        l, u = 0, n-1
        while l <= u:
            m = (l+u)//2
            if self.R[m][1] > v:
                u = m-1
            else:
                l = m+1
        return l
    def setup( self, intvals ):
        self.L = sorted( intvals, key=lambda y: y[0])
        self.R = sorted( intvals, key=lambda y: y[1])
    def minRemoval( self, n, intvals ):
        self.setup( intvals )
        s = 0
        limit = inf
        for v, w in reversed( self.L[1:]):
            if w > limit: continue
            b = self.binsrch( v, n )
            s += n-b-1
            n = b
            limit = v
        return s
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
if __name__ == '__main__':############################## 
    t = int(input ())###################################
    for _ in range (t):#################################
        N = int(input())################################
        intervals = [list(map(int, input().split()))####
                     for i in range(N)]#################
        ob = Solution()#################################
        res = ob.minRemoval(N, intervals)###############
        print(res)######################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
# (1) よんひゃくななじゅう、470
# (2) はっぴゃくごじゅうさん、853
# (3) せんさんひゃく、1,300
# (4) いちまんななせん、17,000
# (5) さんぜんろっぴゃくじゅうに、3,612
# (6) ごせんひゃくきゅうじゅうはち、5,198
# (7) よんまんろくせんきゅうひゃく、46,900
# (8) きゅうまんにひゃくじゅう、90,210
########################################################
########################################################
########################################################
########################################################
# Stranger: Whose wallet is this?
# しらないひと：　これは　だれの　さいふですか。
# Mary: It's my wallet. Thank you very much.
# メアリー：　わたしの　さいふです。ありがとう　ございます。
########################################################
########################################################
########################################################
########################################################
# Test Cases Passed:                       40574 / 40574
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1466
# Total Time Taken:                                 8.81
