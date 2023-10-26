/*/////////////////                          ///////////
///////////////////                          ///////////
///////////////////                          ///////////
///////////////////                          ///////////
################################################################
################################################################
################################################################
#####################################    #######################
#######################                      ///////////   #####
##################################    ##########################
###############################    #############################
###########################    #################################
######################    #####              //////#############
###############################    ############////#############
###############################    ############////#############
###############################    ############////#############
###############################              //////#############
################################################################
################################################################
################################################################
///////////////////                          ///////////
///////////////////                          ///////////
///////////////////                          ///////////
///////////////////                          /////////*/
// Shortest XY distance in Grid, 右、みぎ
////////////////////////////////////////////////////////
// Given a N*M grid of characters 'O', 'X', and 'Y'. 
// Find the minimum Manhattan distance between a X and
// a Y.
////////////////////////////////////////////////////////
// Manhattan Distance :
// |    row_index_x -    row_index_y | +
// | column_index_x - column_index_y |
////////////////////////////////////////////////////////
// Input: N = 4, M = 4, grid = {{X, O, O, O}
// Output: 1                    {O,*Y, O, Y}
// Explanation: *               {X,*X, O, O}
//                              {O, Y, O, O}},
////////////////////////////////////////////////////////
// Input: N = 3, M = 3, grid = {{X,`X, O}
// Outpus: 2                    {O, O,`Y}
// Explanation: `               {Y, O, O}}
////////////////////////////////////////////////////////
// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(N*M)
////////////////////////////////////////////////////////
// 1 ≤ N*M ≤ 10^5 
////////////////////////////////////////////////////////
// There exists at least one 'X' and at least one 'Y' 
// in the grid.
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// In der Oberlänge liegt die Brustwarzenachse in den
// meisten Fällen unter dem oberen Körperviertel
// (gestrichelte Linie)
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//       liegt |              - lies
//       Brust ||             - breast
//      Warzen |||            - nipples
//       Achse ||||           - axis
//     meisten |||keine       - most
//      Fällen ||||Bewegung   - cases
//   streichen ||||||oo  ..   - to stroke
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
import java.io.*;import java.util.*;
////////////////////////////////////////////////////////
//  die Bananen \ bananas
//   die Trauben \ grapes
//   die Obstorte \ fruit cake
// der Orangensaft \ orange juice
//         das Brot \ bread
//          der Käse \ cheese
//       der Schinken \ ham
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
class GFG{public static void main(String args[]) throws 
IOException{BufferedReader read=new BufferedReader(new 
InputStreamReader(System.in));int t=Integer.parseInt(
read.readLine());while(t-->0){String S[]=read.readLine
().split(" ");int N=Integer.parseInt(S[0]);int M=
Integer.parseInt(S[1]);ArrayList<ArrayList<Character>>
grid=new ArrayList<>();for(int i=0;i<N;i++){ArrayList
<Character> col=new ArrayList<>();String S1[]=read.
readLine().split(" ");for(int j=0;j<M;j++){col.add
(S1[j].charAt(0));}grid.add(col);}Solution ob=new 
Solution();System.out.println(ob.shortestXYDist(grid,
N,M));}}}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
class Solution {
    static final int inf = Integer.MAX_VALUE;
    int dis[][];
    class Point {
        int i;
        int j;
        Point( int i, int j ){
            this.i = i;
            this.j = j;
        }
        @Override
        public String toString() {
            return "(" + i + "," + j + ")";
        }
    };
    Queue<Point> q = new LinkedList<>();
    ArrayList<Point> y = new ArrayList<>();
    void setup( ArrayList<ArrayList<Character>> grid,
                int n,
                int m )
    {
        dis = new int[n+2][m+2];
        for( int i = 0; i < n; ++i ){
            for( int j = 0; j < m; ++j ){
                int i1 = i + 1;
                int j1 = j + 1;
                switch( grid.get( i ).get( j )){
                case 'X':
                    q.offer( new Point( i1, j1 ));
                    break;
                case 'Y':
                    y.add( new Point( i1, j1 ));
                default:
                    dis[i1][j1] = inf;
                    break;
                }
            }
        }
    }
    void debug()
    {
        System.out.println( y.toString());
        System.out.println
            ( Arrays.toString( q.toArray() ));
        for( int i = 0; i < dis.length; ++i ){
            System.out.println
                ( Arrays.toString( dis[i] ));
        }
    }
    void update( int d, int i, int j ){
        if( dis[i][j] > d ){
            dis[i][j] = d;
            q.offer( new Point( i, j ));
        }
    }
    void check( int i, int j ){
        int d = 1 + dis[i][j];
        update( d, i-1, j );
        update( d, i, j+1 );
        update( d, i+1, j );
        update( d, i, j-1 );
    }
    int get_min_y()
    {
        int min_y = inf;
        for( Point p: y ){
            int d = dis[p.i][p.j];
            if( min_y > d ){
                min_y = d;
            }
        }
        return min_y;
    }
    int shortestXYDist
        ( ArrayList<ArrayList<Character>> grid,
          int n,
          int m )
    {
        setup( grid, n, m );
        while( !q.isEmpty() ){
            var p = q.poll();
            check( p.i, p.j );
        }
        if( false ){ debug(); }
        return get_min_y();
    }
};
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
///////////////////////////////////////////// //////////
///////////////////////////////////////////// //////////
// jinzu                                jeans ジンズ
// jisho                           dictionary じしょ
// jitensha                           bicycle じてんしゃ
// shinbun                          newspaper しんぶん
// tiishatsu                          T-shirt Ｔシャツ
// tokee                          watch;clock とけい
// nooto                             notebook ノート
// pen                                    pen ペン
// booshi                             hat;cap ぼうし
// hon                                   book ほん、本
///////////////////////////////////////////// //////////
///////////////////////////////////////////// //////////
///////////////////////////////////////////// //////////
////////////////////////////////////////////////////////
// Test Cases Passed:                        1115 / 1115
// Total Points Scored:                            4 / 4
// Your Total Score:                                1450
// Total Time Taken:                                 1.7
