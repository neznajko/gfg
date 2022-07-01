################################################################
# Get minimum element from stack
################################################################
# Medium Accuracy: 24.49% Submissions: 100k+ Points: 4
################################################################
# Lamp:
# This problem is part of GFG SDE Sheet. Click here to view more.  
################################################################
# You are given N elements and your task is to Implement a Stack
# in which you can get minimum element in O(1) time.
################################################################
# Example: 1
# Input:   push(2)
#          push(3)
#          pop()
#          getMin()
#          push(1)
#          getMin()
# Output:  3 2 1
# Explanation:
# push(2)  Insert 2 into the stack. The stack will be {2}
# push(3)  Insert 3 into the stack. The stack will be {2 3}
# pop()    Remove top elemnt from stack. Poppd element will be 3
#          the stack will be {2}
# getMin() Return the minimum element, min element will be 2 
# push(1)  Insert 1 into the stack. The stack will be {2 1}
# getMin() Return the minimum element, min element will be 1
################################################################
# Your Tsk: You are required to cmplete the three methods push()
# which take one argumnt an integr 'x' to be pushd into the stk,
# pop() which retrns a ntegr poppd out from the stk and getMin()
# which returns the min element from the stk. (-1 wil be returnd
# if for pop() and getMin() the stack is empty.)
# 
# Expected Time Complexity : O(1) for all the 3 methods.
# Expected Auixilliary Space : O(1) for all the 3 methods.
# 
# Constraints:
# 1 <= Number of queries <= 100
# 1 <= values of the stack <= 100
# 
# If you are facing any issue on this page. Please let us know.
################################################################
MOD = 101
def pack( a, mvl ): return a*MOD + mvl
def unpack( a ): return a//MOD, a%MOD
class stack:
    def __init__( self ):
        self.mvl = MOD - 1 # minimum value
        self.stk = []      # stack
        
    def push( self, a ):
        if a < self.mvl:
            # a is the new minimum value
            # pack a and old mvl to stack
            self.stk.append( pack( a, self.mvl ))
            # update mvl
            self.mvl = a
        else:
            self.stk.append( a )
            
    def pop( self ):
        if len( self.stk ) == 0: return -1
        # check if pop value is packed
        if self.stk[-1] < MOD: # nop
            return self.stk.pop()
        else:             # yep
            a, mvl = unpack( self.stk.pop())
            self.mvl = mvl
            return a
        
    def getMin( self ):
        if len( self.stk ) == 0: return -1
        return self.mvl
################################################################
if __name__ == '__main__':
    t = int( input())
    for _ in range(t):
        q = int( input())
        arr = [int(x) for x in input().split()]
        stk = stack()  
        qi = 0
        qn = 1
        while qn <= q:
            qt = arr[qi]
            if qt == 1:
                stk.push( arr[qi + 1])
                qi += 2
            elif qt == 2:
                print( stk.pop(), end=' ')
                qi += 1
            else:
                print( stk.getMin(), end=' ')
                qi += 1
            qn += 1
        print()
################################################################
# log: - Do you know why in America they accepted a new abortion
# rule? Becuse they are very good pray 3 times a day and believe
# in Jesus? It could be, but I think they want to compensate for
# the negative image from the current mass shootings of children
# in Uvalde so the party which is defending guns strive to label
# themselves as pro-life what-ever. So you might say how is that
# possible; to play with lives and destinies of milln women just
# to clear your reputatn? But after all what can you expect from
# a guy how has acknowledge the military genius of Putin?:)
#
# Test Cases Passed: 100 / 100
# Total Time Taken: 0.03 / 1.02
