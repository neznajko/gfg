////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////                                                        ////
//// 0123456789abcdefghijklmnop0123456789abcdefghijklmnop   ////
////                                                        ////
//// ==========================-------------------------- 0 ////
//// ==========================-------------------------- 1 ////
//// ==========================-------------------------- 2 ////
//// ==========================-------------------------- 3 ////
//// ==========================-------------------------- 4 ////
//// ===============       ====------                 --- 5 ////
//// =============  @@@@@@@  ==-----                   -- 6 ////
//// ============= @@@@@@@@@ ==------                 --- 7 ////
//// ============= @@@@@@@@@ ==-------------      ------- 8 ////
//// =====          @@@@@@@@         -------       ------ 9 ////
//// ===  @@@@@@@@@@  @@@@@@ @@@@@@@@  -----       ------ a ////
//// == @@@@@@@@@@@@@@ @@@@@ @@@@@@@@@@ ----       ------ b ////
//// |||  @@@@@@@@@@  @@@@@@ @@@@@@@@  #####       ###### 0 ////
//// |||||          @@@@@@@@         #######       ###### 1 ////
//// |||||||||||  @@@@@@@@@@@  #############       ###### 2 ////
//// ||||||||   @@@@@@@@@@@@@@@   ##########       ###### 3 ////
//// |||||   @@@@@@@@@@@@@@@@@@@@@   #######       ###### 4 ////
//// |||  @@@@@@@@@@@@@ @@@@@@@@@@@@@  #####       ###### 5 ////
//// || @@@@@@@@@@@@  ||  @@@@@@@@@@@@@ ####       ###### 6 ////
//// || @@@@@@@@@   ||||||   @@@@@@@@@@ #          ###### 7 ////
//// |||  @@@@   ||||||||||||   @@@@@  ##          ###### 8 ////
//// |||||    |||||||||||||||||#     ######      ######## 9 ////
//// ||||||||||||||||||||||||||########################## a ////
//// ||||||||||||||||||||||||||########################## b ////
////                                                        ////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 雨 が　や　み 、 　　   Когато дъждът отмине,
// 虹 の「灯」が 輝 く。 [ светлината ] на дъгата изгрява
////////////////////////////////////////////////////////////////
// Maximum occured integer
////////////////////////////////////////////////////////////////
// Given n integer ranges, the t a s k is t o return the maximum
// occurring integer in the given ranges. I f more than one such
// integer exists, return t h e smallest one. The ranges are i n
// two arrays l[] and r[]. l[i] consists of t h e starting point
// of the range and r[i] consists o f the corresponding endpoint
// of the range & a maxx w h i c h is the maximum value o f r[].
// For example, consider the following ranges.
// l[] = {2, 1, 3}, r[] = {5, 3, 9}
// Ranges represented by the above arrays are.
// [2, 5] = {2, 3, 4, 5}
// [1, 3] = {1, 2, 3}
// [3, 9] = {3, 4, 5, 6, 7, 8, 9}
// The maximum occurred integer in these ranges is 3.
////////////////////////////////////////////////////////////////
// 1 ≤ n ≤ 10⁶
// 0 ≤ l[i],r[i] ≤ 10⁶
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// ロバート：いい天気ですね。
// け　ん：そうですね。でも、ちょっと暑いですね。
// ロバート：ええ。わあ、きれいな海
// け　ん：泳ぎましよう。
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <algorithm>
# include <vector>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// We are given some intervals like [1,10],[2,5],[3,8],[5,5] and
// want t o b u i l d f  r  e  q  u  e  n  c  y histogram, like:
//
//           *
//       : : :
//     - - - - : : :
//   = = = = = = = = = =
// 0 1 2 3 4 5 6 7 8 9 a
//   ^                 ^
//     ^     ^
//       ^         ^
//           ^
//
// T h i s problem has beautiful O(n) solution, and to be honest
// I've f o u n d it only by checking t h e hints:), what to do?
////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxOccured( int n, int l[], int r[], int maxx ){
        vector <int> h( maxx + 2 );
        for( int j = 0; j < n; ++j ){
            ++h[ l[j] ];
            --h[ r[j] + 1 ];
        }
        for( int j = 1; j <= maxx; ++j ){
            h[j] += h[j - 1];
        }
        return max_element( h.begin(), h.end() ) - h.begin();
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 2.1.37. The air resistance force a c t i n g on raindrops i s
// proportional to the p r o d u c t of the square of t h e drop
// velocity and t h e square of their radius: f = Aρ₀r²v², where
// ρ₀ ~ 1.3 kg/m³ i s the a i r density, a n d the dimensionless
// coefficient A for r o u n d drops is of the order of 1. Which
// drops, large or small, fall to the ground with greater speed?
// Estimate the speed of a drop of radius r = 1 mm when it falls
// from a great height.
//
// Before couple of p r o b l e m s carelessly wrote t h a t the
// coefficient α in the resistance force f = αv², depends on the
// object's shape and m a s s, yea I have to apologies be cos it
// doesn't depends neither o f its mass nor its d e n s i t y 8)
// Ok in a state o f balance we'll have f = Aρ₀r²v² = mg, now we
// can use the f    o    r    m    u    l    a m = ρV = 4πρr³/3:
// Aρ₀r²v² = 4πρgr³/3, and v² = 4πρgr/3Aρ₀ ~ r, s o larger drops
// fall with g r e a t e r speed. For the estimation we'll have:
// v² = 4πρrg/3Aρ₀, w i t h ρ = 1000 kg/m³, a  n  d ρr = 1 kg/m²
// v² = 4(3.14)(9.8)/3(1.3) m²/s² = 31.56 m²/s² zo v ≈ 5.6 m/s «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    int n;
    cin >> n;
    int* l = new int[n];
    int* r = new int[n];
    for( int j = 0; j < n; ++j ) cin >> l[j];
    for( int j = 0; j < n; ++j ) cin >> r[j];
    int maxx = *max_element( r, r + n );
    cout << Solution().maxOccured( n, l, r, maxx ) << endl;
    delete[]( l );
    delete[]( r );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 41. Each of n b a l l s is independently placed into one of n
// boxes, with all boxes equally likely. What is the probability
// that exactly one box is empty?
//
// Ok the m o s t important thing in this kind of problems is to
// define the elementary outcomes, be coz it's very easy t o get
// wrong answer by defining not equally likely events. L e t ' s
// mark the boxes with letters a, b, c, .., then one event might 
// look like (b, d, a, a, ..), meaning the first ball is i n box
// b, the s e c o n d ball in d and so on. T h e total number of
// outcomes is then n**n, now we have to c o u n t the number of 
// cases where one box is empty, we can use again the i d e a of
// blank balls, and f i r s t work out the n u m b e r o f their
// arrangements, then fill with concrete ball numbers, s o if we
// have 8 b o x e s one a  r  r  a  n  g  e  m  e  n  t will be:
//                 meaning box 3 i s empty and box 4 has 2 balls
//       *         T h e number of such arrangements is n(n - 1)
// * *   * * * * * be c o z there are n ways to select the empty
// 1 2 3 4 5 6 7 8 box and then n - 1 w a y s t o select the two
// balls box, now we can write numbers on t h e balls, there are
// n! such possibilities, but we have t o take into account that
// the order inside the double b a l l box doesn't matter so the
// number of possitive outcomes is N = n(n - 1)n!/2, a n d t h e
// probability is P = N/n**n = n(n - 1)n!/2n**n                «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    615/615
// Points Scored:                                            4/4
// Your Total Score:                                        1918 
// Time Taken:                                              0.39
// Crossbar: M a n y football fans before s o m e important game
// write poems plan choreography paint inspiring slogans and s o
// on and after losing the game behave l i k e a child whose toy
// has been taken away. O n e advice; my favorite club is called 
// Colchester United, (We A r e Colchester!!!), after losing two
// consecutive games a g a i n s t Oxford and Cambridge w e have 
// dropped o u t in the 3rd d i v i s i o n i f not mistaken ...
// Life is better when not INSISTING whatever from your favorite
// club, if you win you are h a p p y if you lose you are sad it
// is r  e  a  l  l  y s       i       m       p       l       e
