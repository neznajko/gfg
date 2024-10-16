//////////////////////////////////////////////////////////
//                                                      //
//                                                      //
//                      /\\\\\                          //
//                      \/////\\\\\                     //
//                      /\\\/ /////                     //
//                      \/// ///\\\\\                   //
//                  /\\\/\/ /// /////                   //
//                  \///\   \/ ///\\\\\                 //
//                  /\\\/ /\  /// /////                 //
//                  \///\///\ \/ /////                  //
//                  /\\\/\\\\\  /////                   //
//                  \ \\\/////\ \\\\\                   //
//                  /  \\\\\   \ \\\\\                  //
//                  \/\ \\\\\   \/////                  //
//                  /\\\ \\\\\   m a k e                //
//                  \///\ \\\\\                         //
//                       \ \\\\\                        //
//                        \ \\\\\                       //
//                         \/////                       //
//                                                      //
//                                                      //
/////////////////////////////////////////////////////// //
// Longest valid Parentheses, 作、サク
// ///////////////////////////////////////////////////////
// Given a string S consisting of opening and closing
// parenthesis '(' and ')'. Find length of the longest
// valid parenthesis substring. A parenthesis string is
// valid if:
// For every opening parenthesis, there is a closing 
// parenthesis. Opening parenthesis must be closed in
// the correct order.
//////////////////////////////////////////////////////////
// Input: S = ((() Output: 2
// Explaination: The longest valid parenthesis substring
// is "()"
//////////////////////////////////////////////////////////
// Input: S = )()()) Output: 4
// Explaination: The longest valid parenthesis substring
// is "()()".
//////////////////////////////////////////////////////////
// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)
//////////////////////////////////////////////////////////
// 1 ≤ |S| ≤ 10^5  
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
using namespace std;
//////////////////////////////////////////////////////////
# include <iostream>
# include <string>
# include <algorithm>
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// meist - mostly        /////            /////
// reichen - enough     /////            /////
// gelenk - joint      /////            /////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//// die Tomaten - tomatoes
//// die Äpfel - apples
//// die Milch - milk
//// die Eier - eggs                                   oo
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
# define H_MA8_SIZE 100001
//////////////////////////////////////////////////////////
int h[ H_MA8_SIZE ];
//////////////////////////////////////////////////////////
class Solution {
public:
    int maxLength( string& s );
};
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
int Solution::maxLength( string& s ){
    int levl{};
    int ma8{};
    h[levl] = -1;
    for( int j{}, n = s.size(); j < n; ++j ){
        if( s[j] == '(' ){
            ++levl;
            h[levl] = j;
        } else {
            if( levl ){
                --levl;
                ma8 = max( ma8, j - h[levl] );
            } else {
                h[levl] = j;
            }
        }
    }
    return ma8;
}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// suzuki san wa ii hito desu
// Ms Suzuki is a nice person.
// すずき｜さん｜は｜いい｜人｜です。
// watashi wa nihon jin desu
// I am Japanese.
// わたし｜は｜日ほん｜じん｜です。
// ashita wa ichigatsu mikka desu
// Tomorrow is January 3rd.
// あした｜は｜一がつ｜みっか｜です。
// ichigatsu wa totemo samui desu
// January is very cold.
// １月｜は｜とても｜さむい｜です。
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
int main(){ int t; cin>>t; while( t--){ string S; cin >>S;
Solution ob;cout<<ob.maxLength(S)<<"\n";}}////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// jisho wa ikura desu ka( Dictionary )
// じしょ｜は｜いくら｜です｜か。
// sanzennanahyaku en desu( 3,700 )
// さんぜんななひゃく｜えん｜です。
// kutsu wa ikura desu ka( Shoes )
// くつ｜は｜いくら｜です｜か。
// yonsengohyaku en desu( 4,500 )
// よんせんごひゃく｜えん｜です。
// T-shatsu wa ikura desu ka( T-shirt )
// Tシャツ｜は｜いくら｜です｜か。
// kyuusen en desu( 9,000 )
// きゅうせん｜えん｜です。
// jiinzu wa ikura desu ka( Jeans )
// ジインズ｜は｜いくら｜です｜か。
// nanasen en desu( 7,000 )
// ななせん｜えん｜です。
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// Test Cases Passed:                            105 / 105
// Total Points Scored:                              8 / 8
// Your Total Score:                                  1570
// Total Time Taken:                                  0.03
