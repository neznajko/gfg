////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/////////0123456789abcdef0123456789abcdef///////////////////////
////////0################################///////////////////////
////////1################################///////////////////////
////////2###############  ###############///////////////////////
////////3#######`. `.###  ###.` .`#######///////////////////////
////////4#########`. `.#  #.` .`#########///////////////////////
////////5###############  ###############///////////////////////
////////6######        h  a        ######///////////////////////
////////7###############  ###############///////////////////////
////////8###############  ###############///////////////////////
////////9###############  ###############///////////////////////
////////a####          l  f          ####///////////////////////
////////b###############  ###############///////////////////////
////////c###############  ###############///////////////////////
////////d###############  ###############///////////////////////
////////e################################///////////////////////
////////f################################///////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 半（ハン）
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Count Subarray with k odds
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// You are given array nums of n elements and integer K, and count
// the number of subarrays that has k odd numbers.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Input: n = 5, nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: ...
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)
////////////////////////////////////////////////////////////////
// 1 <= n <= 50000
// 1 <= nums <= 10^5 
// 1 <= k <= n
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
import java.io.*;///////////////////////////////////////////////
import java.util.*;/////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class IntArray{public static int[] input(BufferedReader br,int n)
throws IOException{String[] s=br.readLine().trim().split(" ");
int[] a=new int[n];for(int i=0;i<n;i++)a[i]=Integer.parseInt(s[i]);
return a;}public static void print(int[] a){for(int e:a)System.out
.print(e+" ");System.out.println();}public static void print(ArrayList
<Integer>a){for(int e:a)System.out.print(e+" ");System.out.println();
}}//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class GFG{public static void main(String[] args)throws IOException 
{BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int t;t=Integer.parseInt(br.readLine());while(t-->0){int n;n=Integer
.parseInt(br.readLine());int[] nums=IntArray.input(br,n);int k;k=
Integer.parseInt(br.readLine());Solution obj=new Solution(); int res
=obj.countSubarray(n,nums,k);System.out.println(res);}}}////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//                                                           ich
// - Guten Tag, \\ie heißt du?                                du
//                                                            er
// - Max, und du?                                            sie
//                                                 \\ie heißt du?
// - Ich heiße Monika.                                 ich heiße
//                                                 \\ie heißt er?
// - Das ist mein Freund Er heißt Peter.                er heißt
//                                                     sie heißt
// - \\er ist das?                               \\ie heißen sie?
//                                                    sie heißen
// - Das ist mein Freundin. Sie heist Sonia.        \\er ist das?
//                                                       das ist
// - \\ie heißen sie?                          mein(e) Freund(in)
//                                                           und
// - Sie heißen Klaus und Daniel.                             ja
//                                                          nein
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////_
class Solution {
    Deque<Integer> deq;
    boolean odd[];
    int n;
    int a[];
    int k;
    void initialize() {
        deq = new LinkedList<>();
        odd = new boolean[n + 1]; // +guard
        for( int j = 0; j < n; ++j ){
            odd[j] = ( a[j] & 1 ) > 0;
        }
        odd[n] = true;
        for( int j = 0; j < n; ++j ){
            if( odd[j] ){
                deq.offer( j );
                if( deq.size() == k ) break;
            }
        }
    }
    int get_next_pos(){
        int j = deq.peekLast();
        while(! odd[++j] )
            ;
        return j;
    }
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
    int countSubarray( int n, int a[], int k ){
        this.n = n;
        this.a = a;
        this.k = k;
        initialize();
        if( deq.size() < k ) return 0;
        int total = 0;
        int fyorst = 0;
        while( true ){
            int next_pos = get_next_pos();
            int left = deq.peekFirst() - fyorst + 1;
            int ryte = next_pos - deq.peekLast();
            total += left * ryte;
            if( next_pos == n ) break;
            fyorst = deq.pollFirst() + 1;
            deq.offerLast( next_pos );
        }
        return total;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//　は　ハ　ハ　ハ　ハ
//　ひ　ヒ　ヒ　ヒ　ヒ
//　ふ　フ　フ　フ　フ
//　へ　ヘ　ヘ　ヘ　ヘ
//　ほ　ホ　ホ　ホ　ホ
////////////////////////////////////////////////////////////////
//　とうきようは　いま　なんじですか。
//　ごぜん　さんじです。
//　１．ロンドンは　いま　なんじですか。
//　ごご　ろくじです。
//　２．ストックホルムは　いま　なんじですか。
//　ごご　しちじです。
////////////////////////////////////////////////////////////////
// London: ロンドン (Rondon)                         [ ChatGPT ]
// Stockholm: ストックホルム (Sutokkuhorumu)
// Nairobi: ナイロビ (Nairobi)
// New Delhi: ニューデリー (Nyū Derī)
// Bangkok: バンコク (Bankoku)
// Sydney: シドニー (Shidonī)
// New York: ニューヨーク (Nyū Yōku)
// Rio de Janeiro: リオデジャネイロ (Rio de Janeiro)
////////////////////////////////////////////////////////////////
//　３．ナイロビは　いま　なんじですか。
//　ごご　くじです。
//　４．ニューデリーは　いま　なんじですか。
//　ごご　じゅういちじはんです。
//　５．バンコクは　いま　なんじですか。
//　ごぜん　いちじです。
//　６．シドニーは　いま　なんじですか。
//　ごぜん　よじです。
//　７．ニューヨークは　いま　なんじですか。
//　ごご　いちちです。
//　８．リオデジャネイロは　いま　なんじですか。
//　ごご　さんじです。
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                              10117 / 10117
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1362
// Total Time Taken:                                        0.48