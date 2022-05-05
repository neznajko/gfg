////////////////////////////////////////////////////////////////
//      -       =       \       ,       _       *       ;       ,
//      IPL     2021    -       Final
////////,/////// ///////_///////`///////:///////=///////.///////_
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
//  Hard    Accuracy:   45.07   %   Submisns:   7097    Points: 8
////////////////////////////////////////////////////////////////
//__--``**==,,__==``kk__,,``==::;;__**==<<  >>!!||__<<  **  ..,,
//  IPL 2021  Finals  are here  and it  is  between the most
//  successful  team  of  the IPL Mumbai  Indians and the team
//  striving  to  garb  their first trophy  Royal Challengers
//  Banglore. Rohit Sharma, captain of  the team  Mumbai
//  Indians has the most  experience  in  IPL finals, he  feels
//  lucky if  he  solves  a   programming   question  before
//  the IPL finals. So, he  asked   the team's  head    coach
//  Mahela  Jayawardene for a   question.   Question    is,
//  given   a   string  S   consisting  only    of  opening and
//  closing parenthesis 'ie '(' and ')',    the task    is  to
//  find    out the length  of  the longest valid   parentheses
//  substring.
//  --  --  --  --  **  **  **  **  **  **  --  **  __  **  %%  
////////////////////////////////////////////////////////////////
//  NOTE:   The length  of  the smallest    valid   substring
//  ()  is  2.
////////////////////////////////////////////////////////////////
//,,--,,--,,--,,--,,--,,--,,--,,--,,--,,--,,--,,--,,--,,--,,--,,
//  Example:  2
//  Input:  S = "()(())("
//  Output: 6
//  Explanation:  The longest valid substring is  "()(())".
//  Length  = 6.
////////////////////////////////////////////////////////////////
//--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--
//  Your  Task: You don't   need  to  read  input or  print
//  anything. Complete  the function  findMaxLen()  which takes
//  S as  input parameter and returns the max length.
//--____--____--____--____--____--____--____--____--____--____--
//  Constraints:    1 ≤   |S|   ≤ 10^5
////////////////////////////////////////////////////////////////
//--____--____--____--____--____--____--____--____--____--____--
#   include   <string>
#   include   <iostream>
using   namespace   std                                        ;
////////////////////////////////////////////////////////////////
class   Solution    {
public:
    int   findMaxLen( const string&   s)                       ;
}                                                              ;
////////////////////////////////////////////////////////////////
//__====````````,,__====````````,,__====````````,,__====````````
int main()      {
    int t                                                      ;
    cin >>      t                                              ;
    while(      t--){
        string  S                                              ;
        cin     >>  S                                          ; 
        Solution    ob                                         ;
        cout    <<  ob.findMaxLen(  S)  <<      endl           ;
    }
}

////////////____////////////////////////////////////////////////
////    ____````,,,,----====````,,,,====>>>>    ||||%%%%,,,,====
int     stack   [   /* STACKLEN */  100000] ;
int     _   ;   // stack pointer
#   define  push(   Y)  ::stack[    ++_]    =   Y   ;
#   define  pop()   ::stack[    _--]
#   define  empty() (   _   <   0)
#   define  reset() _   =   -1
////    ____````,,,,----====````,,,,====>>>>    ||||%%%%,,,,====
//==__==__++++__==__++++__==__++++__==__++++__==__++++__==__++++
//  Test  Cases Passed  : 123 /   123
//  Total Time  Taken   : 0.01    / 1.12
//==__==__++++__==__++++__==__++++__==__++++__==__++++__==__++++
int Solution::findMaxLen( const   string&   s){
    reset()   ;
    int maxlen  = 0 ;
    int n = s.length()  ;
    int len[  n + 1]    = { 0,}   ;
    for(  int j = 0 ;   j < n; j++){
        if(   s[  j]    ==  '(')  {
              push( j)  ;
        } else  {
              if( empty())  continue;
              int left  = pop()   ;
              int cure  = j - left  + 1 +   len[  left] ;
              len[  j   + 1]  =   cure;
              if( maxlen  < cure) maxlen    = cure;
        }
    }
    return    maxlen;
//==__==__++++__==__++++__==__++++__==__++++__==__++++__==__++++
}
////////========--------********________))))))))>>>>>>>>........
//      chill   :       Rooftop thoughts
