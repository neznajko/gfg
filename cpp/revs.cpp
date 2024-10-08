//      ########################=======###############-------###
//      ########################-------###############=======###
//      ########################=======###############-------###
//      ########################-------###############=======###
//      ########################=======###############-------###
//      ||||||||||||||||||||||||-------|||||||||||||||=======|||
//      ||||||||||||||||||||||||=======|||||||||||||||-------|||
//      ||||||||||||||||||||||||-------|||||||||||||||=======|||
//      ||||||||||||||||||||||||=======|||||||||||||||-------|||
//      ||||||||||||||||||||||||---                       ===|||
//      ################      ##=======############       ---###
//      #####       ###       ##---                       ===###
//      ||||||       ||       ||=======||||||||||||       ---|||
//      ######       ##       ##---                       ===###
//      ######       ##       ##=======###############-------###
//      ||||||       ||       ||                             |||
//      |||||||      ||       ||=======||||       ||||-------|||
//      |||||||||||||||       ||---                       ===|||
//      ||||||||||||||       |||===       |       |       ---|||
//      ############       #####---       #       #       ===###
//      ||||||||||||||||||||||||=======||||       ||||-------|||
//      |||||t|o| |r|e|t|u|r|n||-------||||       ||||=======|||
//      ||||||||||||||||||||||||=======|||||||||||||||-------|||
//      ||||||||||||||||||||||||-------|||||||||||||||=======|||
//      ||||||||||||||||||||||||=======|||||||||||||||-------|||
//      ||||||||||||||||||||||||-------|||||||||||||||=======|||
//      ########################=======###############-------###
//      ########################-------###############=======###
//      ########################=======###############-------###
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Reverse each word in a given string, 帰、き ki かえ.る kaeru
////////////////////////////////////////////////////////////////
// Given a String. Reverse each word in it where the words are 
// separated by dots.
////////////////////////////////////////////////////////////////
// Input: S = "i.like.this.program.very.much"
// Output: i.ekil.siht.margorp.yrev.hcum
// Explanation: The words are reversed as follows:
// "i" -> "i", "like"->"ekil", "this"->"siht",
// "program" -> "margorp", "very" -> "yrev", "much" -> "hcum"
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)
////////////////////////////////////////////////////////////////
// 1 <= |S| <= 10^5
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// nabel = navel; liegen = lie; kurz = short; dar- = there;
// nabel //////// liegen ////// kurz //////// dar- /////////////
// nabel //////// liegen ////// kurz //////// dar- /////////////
// nabel //////// liegen ////// kurz //////// dar- /////////////
//       ////////        //////      ////////      /////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <string>
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// - Wie komme ich bitte zur Jugendherberge?
// - Gehen Sie diese Strasse entlang bis zum Bahnhof ..
//   .. dann nehmen Sie die dritte Strasse rechts.
////////////////////////////////////////////////////////////////
// jugend youth; herberge hostel; diese these; entlang along;
// jugend ////// herberge /////// diese ////// entlang /////////
// jugend ////// herberge /////// diese ////// entlang /////////
// jugend ////// herberge /////// diese ////// entlang /////////
//        //////          ///////       //////         /////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
public:
    string& reverseWords( string& s );
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int find( string& s, int i ){
    while( s[ ++i ] != '.' )
        ;
    return i;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void revs( string& s, int i, int j ){
    while( ++i < --j ){
        auto t{s[i]}; s[i] = s[j]; s[j] = t;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
string& Solution::reverseWords( string& s ){
    const int n = s.size();
    int j{ -1 };
    s.push_back( '.' );
    while( j < n ){
        int i{ j };
        j = find( s, i );
        revs( s, i, j );    
    }
    s.pop_back();
    return s;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){int t;cin>>t;while(t--){string s; cin>>s;Solution ob;
cout<<ob.reverseWords(s)<< endl;}}//////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 1000 2000 3000 4000 5000 6000 7000 | 8000 9000
// せん｜にせん｜さんぜん｜よおせん｜ごせん｜ろくせん｜ななせん
// はっせん｜きゅうせん
////////////////////////////////////////////////////////////////
// 10,000 20,000 30,000 40,000 50,000 60,000 70,000 | 80,000 90,000
// いちまん｜にまん｜さんまん｜よんまん｜ごまん｜ろくまん｜ななまん
// はちまん｜きょうまｎ
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// たんじょう日｜は｜いつ｜です｜か。yep
// らい年｜日本｜に｜いきましょう。yes
// 毎日｜本｜を｜よみます。córrec4 
// あなた｜の｜きょうだい｜は｜なん人｜います｜か。tscheck
// わたし｜の｜たんじょう日｜は｜一日｜です。?
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    60 / 60
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1550
// Total Time Taken:                                        0.04
