////////////////................................................
////////////////................................................
////////////////................................................
////////////////................................................
////////////////................................................
////////////////. . . . . . . . . . . . . . . . . . . . . . . .
//////////////// . . . . . . . . . ||||| . . . . . . . . . . . .
////////////////...................|||||........................
////////////////.......`````````````````````````````............
////////////////.......`````````````````````````````............
////////////////................................................
////////////////........./____/ ............\====\..............
////////////////          /____/           \====\               
////////////////.  .  .  . /____/ .  .  . \====\ .  .  .  .  .  
////////////////            /____/       \====\                 
////////////////  .  .  .  . /____/ .  .\====\  .  .  .  .  .  .
////////////////               /____/ \====\                    
////////////////................./____/==\......................
////////////////. . . . . . . . . \/____/ . . . . . . . . . . . 
////////////////.  .  .  .  .  .\====/____/.  .  .  .  .  .  .   
////////////////  .   .   .  \====\   . /____/.   .   .   .   .   
////////////////.    .  \====\ .    .    .   /____/.    .    .   
////////////////.     .     .     .     .     .     .     .     
////////////////  .      .      .      .      .      .      .   
//                                                    t
//                             i                           r
//              l                t     e r                     e
//                                            a
//                                                     u
// Handshakes, ブン、文                               
////////////////////////////////////////////////////////////////
// We have N persons sitting on a round table. Any person can do 
// a handshake with any other person.
////////////////////////////////////////////////////////////////
// 
//       1
//  2         3
//       4
// 
// Handshake with 2-3 and 1-4 will cause cross.
////////////////////////////////////////////////////////////////
// In how many ways these N people can make handshakes so that 
// no two handshakes cross each other. N would be even. 
////////////////////////////////////////////////////////////////
// Input: N = 2 Output: 1
// Explanation: {1,2} handshake is possible.
////////////////////////////////////////////////////////////////
// Input: N = 4 Output: 2
// Explanation: {{1, 2},{3, 4}} are the two handshakes possible,
// {{1, 3},{2, 4}} is another set of handshakes possible.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(2^N)
// Expected Space Complexity: O(1)
////////////////////////////////////////////////////////////////
// 1 <= N <= 30
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// vorderseitige    voi   e rds   e ert   i voe   s rde   t eri
// + vorder - front  ert svi eee trs ive eet sri eve tes ire evt
// + seite  - side  s   er  t   io  e   sd  e   tr  i   eo  s  re
//////////////////////////////////////////////////////////////// er
// hals - neck  a s a s a s a s     a     s     a     s     a     s
//             h l h l h l h l h   h l   l h   h l   l h   h l   l
//////////////////////////////  a s   s a   a s   s a   a s   s a
//////////////////////////////   l     h     l     h     l     h
////////////////////////////////////////////////////////////////
// kinn - chin kinn    kinn     kinn    kinn    kinn    kinn
///////////////////kinn////kinn/////kinn////kinn////kinn////kinn
////////////////////////////////////////////////////////////////
// grube - groove g
//////////////////r
//////////////////u            ube grube grube g
//////////////////b           r////////////////r
//////////////////e           g////////////////u
////////////////// grube grube ////////////////be grube grube grube
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// beträgt - be b         beträgt b    e               trägt bet
////////////////e////////t/////////t//////////////////e/////////r
////////////////t////////g/////////r//////////////////b/////////ä
////////////////rägt beträ/////////ägt beträgt beträgt /////////g
////////////////////////////////////////////////////////////////t
// brust - breast b    r  u     s      t    b   r  u   s  t   b r  u  s  t
////////////////////////////////////////////////////////////////
// warzen - nipples, ( o )( o ) warzen (o  )(  o) warzen (.)(.) warzen
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// We want to partition n people into group of two and count only
// those vhere there are no cross handshakes, for n = 4 we have
// 1---2 1 2 | 3 4, 1 3 | 2 4, 1 4 | 2 3, total 3 partitions, but
// |   | in 1 3 | 2 4, there is a cross. I will not be surprised
// 4---3 to see a O(1), that is a formula, but could have made it
// up to a linear O(n) DP solution.
// Let's take 6 people and put them in a row:
//
// 1---2---3---4---5---6, what are the choices the fyorst can make?
// If the number of people between handshakers is odd there will
// be a cross, that is if 1 picks 3 or fai, so 1 can choose between
// 2,4 and 6. After that for every pick the fyorst make that will
// split the problem into two subproblems with lesser sizes, so we
// we can use dynamic programming to solve the problem.
//
// If fyorst pics 2, the number between 1 and 2 are 0, and the
// people above 2 are 4, so we have 0-4 split, if 4 is picked then
// we have 2-2 split and if 6th is selected 4-0 split. If we denote
// the number of handshakes without cross as a function of n as f(n),
// then we'll have: f(6) = f(0)*f(4) + f(2)*f(2) + f(4)*f(0), with
// base case scenario: f(0) = 1, so one could easily write a 
// general math like formula, but I didn't bother figuring it out.
////////////////////////////////////////////////////////////////
const MA8N = 30;
////////////////////////////////////////////////////////////////
function cons( n ){
    const a = Array( n );
    a[0] = 1;
    return a;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// ~:. Entschuldigung Wie komme ich zum Bahnhof, bitte?
// %:[ Nehmen Sie die erste Straße rechts und die zweite Straße 
//     links.
// %:[ Der Bahnhof ist auf der rechten Seite.
// ~8.  
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
const cache = cons( MA8N + 1 );
////////////////////////////////////////////////////////////////
class Solution {
    count( n ){
        if( cache[n] !== undefined ){
            return cache[n];
        }
        let i = 0;
        let j = n - 2;
        let s = 0;
        while( j >= 0 ){
            s += this.count( i ) * this.count( j );
            i += 2;
            j -= 2;
        }
        cache[n] = s; 
        return s;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//// 月曜日｜に｜日本｜に｜いきます。no need to mention, còrrect  
////////////////////////////////////////////////////////////////
//// まい年｜わたし｜は｜日本｜に｜いきます。not cross
////////////////////////////////////////////////////////////////
//// わたし｜は｜日本人｜です。ck
////////////////////////////////////////////////////////////////
//// おちゃ｜を｜一つ｜ください。v
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
console.log( new Solution().count( 12 ));
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 100 200 300 400 500 | 600 700 800 900
// ひゃく｜にひゃく｜さんびゃく｜よんひゃく｜ごひゃく
// ろっぴゃく｜ななひゃく｜はっぴゃく｜きゅうひゃく
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    30 / 30
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1546
// Total Time Taken:                                        0.05
