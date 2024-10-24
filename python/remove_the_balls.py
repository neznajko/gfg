#>~#\]]/;\8]/"]~;*@#2;;2>@01#//1"1/"..08*7@[\[;2./_\8_[~
#>">*]].~\88**8>~>10[~\0[2_/@;#;70[""1220.".8@"2.]]\#7\"
#872/>1"\@_00[2.[/@*7@@~>2[81\*~/012~/[//__2;#]#;["#_.@*
#;@\8*_2\_1~/];\["[>;~_78*@;]*018@*@;7*170.0@@;\7*#1]8;>
#7["17;8[0";@@**]~727"]/\2/#_#1_\#\]@[_0;>;_12#87].[.[71
#1#/@"7/@].701[].;7#]>_#>/7.#.@207"#>;*#[\_"7>0]2>]2#8".
#]_1[.;\~*70.""0_7;@;"\_][].*\20#@~/[[*@@"~#/.78/]17]]7#
#8;*../_1>*_~\;\/8~*1;02[7~2200_.1;;[8~].@[2[782.[108;/*
##0"#888@2][.>;@@#.~/0@;*8*#>#@@8\..;\#*[0]~~]>#".0#;1/1
#1[*[*8[]*]@0>[]]8"]8#>8_7\~>72_1[1;[21[\8#\_7][>]*~">~2
#1>*_7.[[*]/0"20_*[__#*/7[@/\[@/@~[[20;*.>77[7./>[0@[.._
##80>"/2/0@#[2\11..]\@77["__*87>2[[*~8;880*7@#>;.*..*\01
#""[1\1][[>~#02\1*"\8[8_]**/~@//72~>]0]2~~>*#71/8;1\.;#\
#_*]#0>_1">8#22[@~#"\/~\0.7_//~~*]1>[[1\]_8/]/088#8*@*"8
#;#/;8[~1".>7#27#">_@20_@2**"~~~12#__@8;]>[;7>2[[\_8207_
#_;7]\1>71/\"12"/70>#_@;.;1#>_#""#@2@8/28#[;/17"">[._0_/
#1]7;\7>]08[8;2#81*_1072]\~/0*]#2[*_;1#2"#/8;1~2.~/>*"8;
#@;.@[_]1._~@\@[2[..0["@2\[;;0">*[*217[\12#12*\2~2/]][;7
#7.@8@/2#\;~>[.018@]71~8/*\7;@0"*~>>;@.1/"7[[;/.@>~*~~_*
##"#\[~#1."7#_."2[07"_27_"2/\1@~\.0;#[00~\~71;~71~>02[.0
########################################################
########################################################
########################################################
########################################################
# cat /dev/urandom | tr -dc '[~@#>[*_.;"//\78120]' |
# fold -w ${1:-55} | head -n 20
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
# Remove the balls
########################################################
########################################################
########################################################
########################################################
# Imagine an imaginary array of length N containing balls.
# Given 2 arrays color and radius of length N each, where
# color[i] represents the color of the ith ball while radius[i]
# represents the radius of ith ball. If two consecutive balls
# have the same color and size, both are removed from the
# array. Geek wants to know the length of the final imaginary
# array.
########################################################
########################################################
########################################################
########################################################
# Input: N = 4  color[] = {1, 3, 3, 1} Output: 0
#              radius[] = {2, 5, 5, 2}
# Explanation: ...
########################################################
########################################################
########################################################
########################################################
# Expected Time Complexity: O(n)
# Expected Auxiliary Space: O(n)
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
# 1 2 3 3 2 6
#           i j
# [0]
# 2
class Solution:
    def finLength( self, n, color, radius ):
        i, j = 0, 1
        stk = []
        push, pop = stk.append, stk.pop
        c = n
        def aresame( i, j ):
            return( color[ i] == color[ j] and
                    radius[i] == radius[j] )
        while j < n:
            if aresame( i, j ):
                c -= 2
                if not stk:
                    i = j + 1
                    j = i + 1
                else:
                    i = pop()
                    j += 1
            else:
                push( i )
                i = j
                j += 1
        return c
#######################################################=
########################################################
########################################################
########################################################
class IntArray: ########################################
    def Input(self,n): #################################
        arr=[int(i) for i in input().strip().split()] ##
        return arr #####################################
    def Print(self,arr): ###############################
        for i in arr: ##################################
            print(i,end=" ") ###########################
        print() ########################################
########################################################
########################################################
########################################################
########################################################
if __name__=="__main__": ###############################
    t = int(input()) ###################################
    for _ in range(t): #################################
        N = int(input()) ###############################
        color=IntArray().Input(N) ######################
        radius=IntArray().Input(N) #####################
        obj = Solution() ###############################
        res = obj.finLength(N, color, radius) ##########
        print(res) #####################################
########################################################
########################################################
########################################################
########################################################
# 1. okaasan 2. oniisan 3. kooki 4. heewa 5. soodan 6. suuji
########################################################
# 1. おじいさん
# 2. おばあさん
# 3. つうやく
# 4. がくせい
# 5. おとうさｎ
# 6. とうきょう
#0123456789012345678901234567890123456789012345678901234
#1######## ,   ,   ,   ,   ,   ,   ,  #########=========
#2######## .......................... #########=========
#3######## - - - - - - - - - - - - -  #########=========
#4######## .......................... #########=========
#5######## ;;;;;;;;;;;    ;;;;;;;;;;; #########=========
#6######## ===========    =========== ##################
#7######## %%%%%%`,%%%    %%%%%`  ,%% ##################
#8######## @@@@` ,@@@@    @@@@` ,@@@@ ##################
#9######## @@`  ,##@@@    @@@`,@@@@@@ ##################
#0######## @@@@@@@@@@'    '@@@@@@@@@@ ##################
#1######## @@@@@@@@@'  ,.  '@@@@@@@@@ ##################
#2######## @@@@@@@@'  .@@.  '@@@@@@@@ ##################
#3######## @@@@@@"  .@@@@@@.  "@@@@@@ ##################
#4######## @@@@" _.@@@@@@@@@@._ "@@@@ ##################
#5######## @@@@@@@@@@@@@@@@@@@@@@@@@@ ##################
#6########.                          ,##################
#7######################################################
#8######################################################
#9######################################################
#0######################################################
#1############################################# f i r e 
#2######################################################
# Test Cases Passed:                         1111 / 1111
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1330
# Total Time Taken:                                 0.08
