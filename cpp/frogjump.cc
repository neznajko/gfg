////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// #############################################################
// -------------------------------------------------------------
// -------------------------------------------------------------
// -------------------------------------------------------------
// ----------%%%%%%%%%%%%%%%%%%%%-------------------------------
// ----------%%%%%%%   %%%%%%%%%%//////////////////-------------
// ----------%%%%%   %%%   %%%%%%/////  /////////// ------------
// ----------%%%   %%%   %%%%%%%%/////  /////////// ------------
// ##########%%%%%%%   %%%%%%%%%               //// ############
// ##########%%%%%   %%%%%   %%%%/////  /////////// ############
// ##########%%%              %%               //// ############
// ##########%%%%%%%%%   %%%%%%%%////////////////// ############
// ##########%%%%   %%   %%   %%%/            ///// ############
// ###########  |   ||   ||   |||| 123 567891 111   ############
// #############|   ||   ||   ||||2131 15 6171819 ##############
// #############|   ||   ||   ||||202  22 2425262 ##############
// #############||||||   ||||||| |72  930 1323334 ##############
// #############||||||   ||||||||   36373  940 14 ##############
// #############||||||||||||||||||243444546   849 ##############
// #############||||||||||||||||||505052535455565 ##############
// ###############                758596061626364 ##############
// ################################               ##############
// #############################################################
// #############################################################
// #############################################################
// #############################################################
// #############################################################
// 雨 が 降 り「続」け る [ не спира ] да вали
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Frog                                                     Jump
////////////////////////////////////////////////////////////////
// Given an integer  array  height[ ] where height[i] represents
// the  height  of  the ith  stair, a frog starts from the first
// stair and wants to reach  the top. From any stair i, the frog
// has two options: it  can  either jump to the (i+1)th stair or
// the ( i + 2 )th stair. The  cost  of  a  jump is the absolute
// difference  in height between  the  two stairs. Determine the
// minimum total  cost  required for the  frog  to reach the top.
////////////////////////////////////////////////////////////////
// Input:                           heights[] = [20, 30, 40, 20] 
// Output:                                                    20
// Explanation:     Minimum cost is incurred when the frog jumps
//                                 from stair 0 to 1 then 1 to 3
////////////////////////////////////////////////////////////////
// Input:                       heights[] = [30, 20, 50, 10, 40]
// Output:                                                    30
// Explanation:    Minimum cost will be incurred when frog jumps
//                                 from stair 0 to 2 then 2 to 4
////////////////////////////////////////////////////////////////
// 1 <=                 height.size()                    <= 10^5
// 0 <=            height[i]                             <= 10^4
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include                                               <vector>
# include                                               <string>
# include                                              <sstream>
# include                                             <iostream>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// ##### dictionary form #### past affirmative ### past negative
// ####                 ####                  ###              
// ##                 ####                  ###
//                 ####                  ###
////////////////////////////////////////////////////////////////
// U-verbs
// 1. drink    | 飲む | のむ | のみました | のみませんでした |
// 2. speak    | 話す | はなす | はなしました | はなしませんでした |
// 3. listen   | 聞く | きく | ききました | ききませんでした |
// 4. buy      | 買う | かう | かいました | かいませんでした |
// 5. take     | 取る | とる | とりました | とりませんでした |
// 6. write    | 書く | かく | かきました | かきませんでした |
// 7. wait     | 待つ | まつ | まちました | まちませんでした |
// 8. there is | 有る | ある | ありました | ありませんでした |
////////////////////////////////////////////////////////////////
// Ru-verbs and Irregular Verbs
//  9. eat    | 食べる | たべる | たべました | たべませんでした |
// 10. get up | 起きる | おきる | おきました | おきませんでした |
// 11. do     | 為る | する | しました | しませんでした |
// 12. come   | 来る | くる | きました | きませんでした |
////////////////////////////////////////////////////////////////
// 1.2.4. Produce an infinite collection of sets A(1), A(2),A(3),
// .... with the property that every A(i) has an infinite number
// of elements, A(i)A(j) = { } for all i != j, and the u n i o n
// U { A(j), j=1,2,.. } = N
// 
// So we have to split 1, 2, 3, 4, ..... into infinite sets that
// have no intersections. One idea is to split into odd and even
// numbers { 1, 3, 5, 7, ..... } + { 2, 4, 6, 8, .. }, now if we
// look at the even n   u   m   b  e   r  s we can write them as:
// 2 * { 1, 2, 3, 4, ..... }; we have the same set we've started
// multiplied by 2, so we can c  o n t  i  n u e in the same way:
// { 1, 2, 3, 4, ...................... } = { 1, 3, 5, 7, .. } +
//                                      2 * { 1, 3, 5, 7, .. } +
//                                      4 * { 1, 3, 5, 7, .. } +
//                                      8 * { 1, 3, 5, 7, .. } +
//                                      ........................,
// so each set can be r   e   p   r   e   s   e  n  t   e   d as:
// A(j) = 2^(j - 1) * { 1, 3, 5, 7, ......................., and
// { 1, 2, 3, 4, ................... } = { 1,  3,  5,  7, .. } +
//                                       { 2,  6, 10, 14, .. } +
//                                       { 4, 12, 20, 28, .. } +
//                                       { 8, 24, 40, 56, .. } +
//                                       .......................
////////////////////////////////////////////////////////////////
// <> 2.1.25. A thread thrown  over a block with a fixed axis is
// passed through a  slit. Loads of mass m1 and m2 are suspended
// at the ends of the thread. Determine  the acceleration of the
// loads if, when the  thread moves, a constant friction force f
// acts on it from the side of the slit.
// #############################################################
// ############################ Let's assume we a r e moving ccw 
// #########   ################ m₁g - T₁ = m₁a 
// ########  o  ############### T₂ - m₂g = m₂a, b e c o z  t h e 
// ########|   |##### T ####### thread is massless w e can write
// ########|###|##### 1 ####### T₁ = T₂ + f, zo
// #### T #|###|################################################
// #### 1 #|# =|= ##############################################
// ########|###|##### T # f ###### a(m₁ + m₂) = g(m₁ - m₂)     +
// #######|m|##|##### 2 ##########  + T₂ - T₁ = g(m₁ - m₂) -   f,
// #######|1|##|################################################
// ############|### T ##########      g(m₁ - m₂) - f  
// #### m g ###|### 2 ########## a =            ---------------- 
// #### 1   ##|m|###############               m₁ + m₂
// ###########|2|###############################################
// ################ m g ######## Here f is s o me critical value  
// ################ 2   ######## say equal to _N, where _ is the   
// ############################# coefficient of f r iction and N
// ############################# N is the reaction from the slit,
// ############################# so if T₁ - T₂, by m o d u le is 
// ############################# less t h e n f, the system wont
// ############################# move c  c  w or cw, t h i s i s 
// ############################# equivalent t  o t h e condition
// ############################# g|m₁ - m₂| <= f
// #############################################################
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCost( vector <int> &h ){
        h.push_back( h.back());
        h.push_back( h.back());
        vector <int> c( h.size());
        for( int j = h.size() - 3; j >= 0; --j ){
            c[j] = min( abs( h[j + 1] - h[j] ) + c[j + 1],
                        abs( h[j + 2] - h[j] ) + c[j + 2]);
        }
        return c[0];
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 33. A jar contains r red balls and g green balls, where r and
// g are fixed positive integers. A b a ll is drawn from the jar
// randomly( with all possibilities equally likely ), and then a
// second ball is drawn randomly.
// (a) Explain intuitively why the probability of the s e c o nd
// ball being green is the same as the probability o f the first
// ball being green
// (b) Define notation for the sample space o f the problem, and
// use this t o compute the probabilities from (a) and show that
// they are the same.
// (c) Suppose t h a t there are 16 balls in total, and that the
// probability that the two balls are the same color is the same
// as the probability that they are different colors. What are r
// and g (list all possibilities)?
//
// (a) be cos there is a symmetry
// (b) so we can n u m b e r the balls from 1 to N = r + g, with
// first r balls being r e d, the sample space will be all pairs:
// (i, j) where i != j. So sample space size iz Total = N(N - 1),
// if we fix one ball to be g r e e n this can be done in g ways,
// the o t h e r ball can b e selected in N - 1 ways, zo P = g/N
// (c) Probability that they are same:    P(RR) = r(r - 1)/Total
//                                        P(GG) = g(g - 1)/Total
//                                       P(same) = P(RR) + P(GG)
//     Probability that they are diff:          P(RG) = rg/Total
//                                              P(GR) = gr/Total
//                                        P(diff) = 2rg/N(N - 1)
//     p(same) = p(diff):              r(r - 1) + g(g - 1) = 2rg,
//  r² - r + g² - g = 2rg, r² - 2rg + g² = r + g = 16 = (r - g)²,
//       zo r - g = 4 r = N - g = N + 4 - r, 2r = N + 4, 2r = 20,
//                                                 r = 10, g = 6
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){string str;getline(cin,str);int t=stoi(str);while(t--
){getline(cin,str);stringstream ss(str);vector<int> arr;int num;
while(ss>>num){arr.push_back(num);}Solution ob;cout<<ob.minCost(
arr)<<endl;}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 1.2.5 ( De Morgan’s Laws ). Let A and B be s u b s e t s of R.
// (a) If x ∈ (A ∩ B)ᶜ, explain why x ∈ Aᶜ ∪ Bᶜ. This shows that
// (A ∩ B)ᶜ ⊆ Aᶜ ∪ Bᶜ
// (b) Prove the r e v e r s e inclusion (A ∩ B)ᶜ ⊇ Aᶜ ∪ Bᶜ, and
// conclude that (A ∩ B)ᶜ = Aᶜ ∪ Bᶜ
// (c) Show (A ∪ B)ᶜ = Aᶜ ∩ Bᶜ by demonstrating inclusion b o th
// ways
////////////////////////////////////////////////////////////////
// (a)
// This is a bit tedious h a v e to admit, if x ∈ (A ∩ B)ᶜ, that
// means x ∉ A ∩ B, zo if x ∈ A, then x ∉ B, that is x ∈ Bᶜ that
// is x ∈ Bᶜ ⊆ Aᶜ ∪ Bᶜ otherwise x ∉ A, that is x ∈ Aᶜ ⊆ Aᶜ ∪ Bᶜ
// zo in both scenarios x ∈ Aᶜ ∪ Bᶜ
// (b)
// Now the other way around, if x ∈ Aᶜ, then x ∉ A and x ∉ A ∩ B
// zo x ∈ (A ∩ B)ᶜ, if x ∉ Aᶜ, then x ∈ Bᶜ, that is the saaaaame
// position: x ∉ B, zo x ∉ A ∩ B, hence my instant communication:
// x ∈ (A ∩ B)ᶜ
// (c)
// I fhink I'm going to use truth tables here:
// | A | B | A ∪ B | (A ∪ B)ᶜ | Aᶜ | Bᶜ | Aᶜ ∩ Bᶜ |
// | 0 | 0 |     0 |        1 |  1 |  1 |       1 |
// | 0 | 1 |     1 |        0 |  1 |  0 |       0 |
// | 1 | 0 |     1 |        0 |  0 |  1 |       0 |
// | 1 | 1 |     1 |        0 |  0 |  0 |       0 |
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1115 / 1115
// Points Scored:                                          4 / 4
// Your Total Score:                                        1906 
// Time Taken:                                              0.12
