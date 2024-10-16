
################################################################
################################################################
################################################################
############                        ################### der Grad
###########                          ########################### 
########### ######################## ########################### 段 
########### ###       ##        #### ########################### だん
########### ###       ##        #### ########################### 
########### ### ######### ##### # ## ###########################
########### ###       ##  #####   ## ###########################
########### ###       ## ####### ### ########################### 
########### ### #################### ########################### 
########### ###       ##         ### ###########################
########### ###       ##         ### ###########################
########### ### #########       #### ########################### 
########### ##        ##         ### ###########################
########### ##        ##    #    ### ###########################
########### ### #################### ########################### 
###########                          ########################### 
############                        ###################### lE GRAdE 
################################################################
################################################################
################################################################
################################################################
#                                                     Word Break
################################################################
# Given a string s and a dictionary of n words dictionary, find
# out if "s" can be segmented into a space-separated sequence of
# dictionary words. Return 1 if it is possible to break the s
# into a sequence of dictionary words, else return 0. 
# Note: From the dictionary dictionary each word can be taken
# any number of times and in any order
################################################################
# Input: n = 6 s = "ilike" dictionary = { "i", "like", "sam",
# "sung", "samsung", "mobile"} Output: 1 Explanation: The string
# can be segmented as "i like"
################################################################
# Expected Time Complexity: O(len(s)^2)
# Expected Space Complexity: O(len(s))
################################################################
# 1 ≤ n ≤ 12
# 1 ≤ len(s) ≤ 1100
################################################################
class Solution:
    """"""
    def dp( self, i ):
        """"""
        if i == self.n: return True
        if self.checked[ i ]: return False
        for j in range( i + 1, self.n + 1 ):
            prefix = self.s[ i:j ]
            if prefix in self.Dict:
                if self.dp( j ): raise Exception( "ok" )
        self.checked[ i ] = True
        return False
    
    def wordBreak( self, n_words, s, Dict ):
        ''''''
        self.s = s 
        self.Dict = Dict
        n = len( self.s )
        self.checked = [ False ] * n
        self.n = n
        try: self.dp( 0 )
        except Exception as e: return True
        return False
    
################################################################
if __name__=='__main__': #######################################
        test_case=int(input()) #################################
        for _ in range(test_case): #############################
                n=int(input()) #################################
                dictionary=[w for w in input().strip().split() ]
                s=input().strip() ##############################
                ob=Solution() ##################################
                res=ob.wordBreak(n,s,dictionary) ###############
                print( int( res )) #############################
################################################################
# Test Cases Passed:                                 1120 / 1120
# Points Scored:                                           4 / 4
# Your Total Score:                                         1706 
# Time Taken:                                               0.07
