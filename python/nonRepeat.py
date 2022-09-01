################################################################
# https://practice.geeksforgeeks.org/problems/
# first-non-repeating-character-in-a-stream1216/1
################################################################
# First non-repeating character in a stream
################################################################
#  Given an input stream of A of n characters consisting only of
#        lower case alphabets. The task is to find the first non
#  repeating character, each time a character is inserted to the
#   stream. If there is no such character then append '#' to the 
#                                                        answer.
################################################################
# Example 1:
# Input: A = "aabc"
# Output: "a#bb"
# Explanation: For every character first non repeating character
# is as follows:
# "a" - first non-repeating character is 'a'
# "aa" - no non-repeating character so '#'
# "aab" - first non-repeating character is 'b'
# "aabc" - first non-repeating character is 'b'
################################################################
# Your Task: You don't need to read or print anything. Your task
#  is to complete the function FirstNonRepeating() which takes A
#   as input parameter and returns a string after processing the
#                                                  input stream.
################################################################
# Expected Time Complexity: O(26*n)
# Expected Space Complexity: O(26)
################################################################
# Constraints:
# 1 <= n <= 10^5
################################################################
from collections import deque
################################################################
# Test Cases Passed: 305 / 305
# Total Points Scored: 4 / 4
# Your Total Score: 770
# Total Time Taken: 0.17
# Your Accuracy: 100%
# Attempts No.: 1
class Solution:
    def FirstNonRepeating( self, A ):
        # Initialization Block
        output_list = []
        hashtab = [0] * 26
        deq = deque() # candidates
        #
        for c in A: # aabc
            j = ord( c ) - ord( 'a' )
            hashtab[j] += 1
            if hashtab[j] < 2: deq.append( j )
            while len( deq ):
                j = deq[0]
                if hashtab[j] < 2:
                    output_list.append( chr( ord( 'a' ) + j ))
                    break
                deq.popleft()
            else:
                output_list.append( '#' )
        return "".join( output_list )
################################################################
if __name__ == '__main__':                     # >>> Driver Code
    T = int( input() )                         # Driver Code <<<
    for i in range( T ):                       # >>> Driver Code
        A = input()                            # Driver Code <<<
        ob = Solution()                        # >>> Driver Code
        ans = ob.FirstNonRepeating( A )        # Driver Code <<<
        print( ans )                           # >>> Driver Code
################################################################
