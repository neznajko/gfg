////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Smallest number on left
////////////////////////////////////////////////////////////////
// Given an array  a of integers  of length n,  find the nearest
// smaller number  for  every  element  such  that  the  smaller
// element  is  on left side. If no small element present on the
// left print -1
////////////////////////////////////////////////////////////////
// Input: n = 6, a = {1, 5, 0, 3, 4, 5}, Output: -1 1 -1 0 3 4
// Explaination: Upto 3 it is easy to see the smaller numbers. 
// But for 4 the smaller numbers are 1, 0 and 3. But among them
// 3 is closest. Similary for 5 it is 4
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)
////////////////////////////////////////////////////////////////
// 1 ≤ n ≤ 10000
// 0 ≤ a[i] ≤ 10^4  
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
import java.io                                               .*;
import java.util                                             .*;
////////////////////////////////////////////////////////////////
class  GFG { public  static  void  main ( String args[] ) throws 
IOException   {   BufferedReader in  =  new BufferedReader ( new 
InputStreamReader(System.in));int t=Integer.parseInt(in.readLine
());while(t-->0){int n=Integer.parseInt(in.readLine());String a1
[]=in.readLine().trim().split("\\s+");int a[]=new int[n];for(int
i=0; i<n; i++) a[i] = Integer.parseInt(a1[i]); Solution ob = new 
Solution(); List <Integer> ans=new ArrayList<Integer>(); ans=ob.
leftSmaller(n,a);for(int i=0;i<n;i++)System.out.print(ans.get(i)
+" ");System.out.println();}}}//   /////////////////////////////
/////////////////////////  / //   //////////////////////////////
////////////////////////  / //   ///////////////////////////////
///////////////////////  / //   ////////////////////////////////
//////////////////////  / //   /////////////////////////////////
class Solution {
    static List <Integer> leftSmaller( int n, int[] a )
    {
        Integer[] b = new Integer[ n ];
        var stack = new Stack <Integer> ();
        for( int j = 0; j < n; ++j ){
            while( true ){
                if( stack.isEmpty()){
                    stack.push( a[ j ]);
                    b[ j ] = -1;
                    break;
                }
                int top = stack.peek();
                if( top >= a[ j ]){
                    stack.pop();
                } else {
                    stack.push( a[ j ]);
                    b[ j ] = top;
                    break;
                }
            }
        }
        return Arrays.asList( b );
    }
}
////////////////////////////////////////////////////////////////
// 図書館で本を読みます。
// Ich werde Bücher in der Bibliothek lesen.
////////////////////////////////////////////////////////////////
// うちでテレビを見ます。
// Ich werde zu Hause fernsehen.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  207 / 207
// Points Scored:                                          4 / 4
// Your Total Score:                                        1790 
// Time Taken:                                               1.2
