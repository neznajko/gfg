//##############################################################
//##############################################################
//##############################################################
//##############################################################
//##        ########                                 ###########       
//##        ########   .`.`.`\\\\\\,,,,,,\\\\\\------###########
//#####        ########      ######      ######      ###########
//#####        ########------######``````######......###########
//#####        ########                              ###########
//#####        ########,,,,,,''''''((((((::::::______###########
//#####        ########      ######      ######      ###########
//#####        ########^^^^^^######,,,,,,######>>>>>>###########
//#####        ########                              ###########
//#####    oo  ########......""""""______''''''`,`,`,###########
//##############################################################
//#############      ##################      ###################
//#############......#######      #####''''''###################
//###############      #####______#########      ###############
//###############,,,,,,#######      #######------###############
//#################      #####,,,,,,############      ##########
//#########      ##______#######################\\\\\\##########
//#########......######      ###################################    
//#######      ########``````###################################    
//#######______############      ############      #############    
//#####      ##############------############______#############    
//#####//////##################      ######      ###############    
//#############################......      """"""###############    
//###################################,,,,,,#####################    
//##############################################################    
//##############################################################
// Maximum Profit, 084 思、omo, おも THINK
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// In the stock  market, a  person  buys a stock and sells it on
// some  future  date. Given  the stock  prices of N  days in an
// array A[]  and  a positive  integer K,  find  out the maximum
// profit a  person  can  make  in  at  most  K  transactions. A
// transaction   is  equivalent to  buying + selling  of a stock
// and   new  transaction  can  start  only  when  the  previous
// transaction has been completed. /////////////////////////////                      
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Input: K = 2, N = 6, A = { 10, 22, 5, 75, 65, 80 }
// Output: 87
// Explaination: 1st transaction: buy at 10 and sell at 22,
// 2nd transaction: buy at 5 and sell at 80.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Input: K = 1, N = 5, A = { 100, 90, 80, 50, 25 }
// Output: 0
// Explaination: Selling price is decreasing daily. So seller
// cannot have profit.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(NK)
// Expected Auxiliary Space: O(NK)
////////////////////////////////////////////////////////////////
// 1 ≤ N ≤ 500
// 1 ≤ K ≤ 200
// 1 ≤ A[ i ] ≤ 1000
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// / / / / / / / / / / / \ \ \ / / / / / / / / / / / / / / / / /
//
// Die gegenüberstehende Tafel macht sich zur Aufgabe, nach der
// vorseitigen Abbildung mit ihrem prägnant geschnittenen
// Umrißcharacter ..                         
// 
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// stehen - stand
// tafel - panel
// aufgabe - task
// vorseitig - in advance
// abbildung - illustration
// prägnant - concise
// schneiden - cut
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
import java  .             io . *                   ;
import java .    util   .          * ;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class  GFG { public static void  main (  String args [] ) throws 
IOException  {  BufferedReader  in  =  new  BufferedReader ( new 
InputStreamReader ( System.in )); int t = Integer.parseInt ( in.
readLine () ); while ( t-- > 0 ) { int K = Integer.parseInt( in.
readLine () ); int N = Integer.parseInt( in.readLine ()); String 
input_line[] = in.readLine().trim().split("\\s+"); int A[] = new 
int[ N ]; for ( int i = 0; i < N; i++ ) A[i] = Integer.parseInt(
input_line[i]); Solution ob = new Solution(); System.out.println
(ob.maxProfit(K, N, A)); }}}////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////// 2:) Was kosten die Rosen bitte?
//////////////////////////////// 8:" Drei Euro zehn das Stück.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////// 2:* Also, sieben Stück, bitte.
//////////////////////////////// 8:)
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////// ...das Stück            ...each 
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// I: bought, this' book; on" Sunday.
// nichiyoobi ni kono hon wo kaimashita
// 日曜日、に、この、本、を、かいました。
////////////////////////////////////////////////////////////////
// Let's meet at the entrance.
// iraguchi de aimashyoo.
// 入口｜で｜あいましょう。
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
    int[][] buycache;
    int[][] selcache;
    int[] a;
    int n;
    ////////////////////////////////////////////////////////////
    int buy( int k, int j ){
        if( k == 0 || j >= n ){
            return 0;
        }
        if( buycache[k][j] > 0 ){
            return buycache[k][j];
        }
        // buy jth stock or skip
        int taike = sel( k, j + 1 ) - a[j];
        int skp = buy( k, j + 1 );
        return buycache[k][j] = Math.max( taike, skp );
    }
    ////////////////////////////////////////////////////////////
    int sel( int k, int j ){
        if( k == 0 || j >= n ){
            return 0;
        }
        if( selcache[k][j] > 0 ){
            return selcache[k][j];
        }
        // sell jth stock or not
        int ok = a[j] + buy( k - 1, j + 1 );
        int not = sel( k, j + 1 );
        return selcache[k][j] = Math.max( ok, not );
    }
    ////////////////////////////////////////////////////////////
    int maxProfit( int k, int n, int[] a ){
        this.a = a;
        this.n = n;
        buycache = new int[k + 1][n];
        selcache = new int[k + 1][n];
        return buy( k, 0 );
    }                      
}                          
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 1) kore wa  dare no    kutsu desu ka( shoes )
//    これはだれの　くつですか。
//    Suu  san no   kutsu desu
//    スーさんの　くつです。
// 2) kore wa dare no kutsu desu ka( shoes )
//    これはだれの　くつですか。
//    Mearii  san  no kutsu desu
//    メアリーさんの　くつです。
// 3) kore wa dare no hon desu ka( book )
//    これはだれの　本ですか。
//    Yamashita    sensee no   hon desu
//    やましたせんせいの　本です。
// 4) kore wa kaban no desu ka( bag )
//    これはかばんの　ですか。
//    Robaato no    kaban   desu
//    ロバートの　かばんです。
// 5) kore wa dare no jitensha desu ka( bicycle )
//    これは　だれの　じてんしゃですか。
//    Takeshi san  no jitensha desu
//    たけしさんの　じてんしゃです。
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////// ########
//////////////////////////////////////////////////////////////// ########
//////////////////////////////////////////////////////////////// ########
//////////////////////////////////////////////////////////////// ########
//////////////////////////////////////////////////////////////// ########
//////////////////////////////////////////////////////////////// ########
// Test Cases Passed:                                  215 / 215 ########
// Total Points Scored:                                    8 / 8 ########
// Your Total Score:                                        1626 ########
// Total Time Taken:                                        0.34 ########
