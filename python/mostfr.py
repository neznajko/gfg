########################################################
########################################################
########################################################
########################################################
########################################################
#########`.`.`.`.`.`.`.`.`.`.`.`.`.`.  `.`.`.`.`.`.`.`.`
#########`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.  `.`.`.`.`.`.`.`
#########`.`.`.` ` ` ` `        .`.`.`.`.  `.`.`.`.`.`.`
#########`.`.`. . . .   . .`.`.`.`.`.`.`.`.  `.`.`.`.`.`
#########`.`.`.`.`.`.`  .`.`.`.`.`.`.`.`.`.`.  `,`.`.`.`
#########`.`.                     .`.`.`.`.`.`  .`.`.`.`
#########`.`.`.`.`.`.`  .`.`.`.`.`.`.`.`.`.`  .`.`.`.`.`
#########`.`.`.`.`.`.`  .`.`.`.`.`.`.`.`.`  .`.`.`.`.`.`
#########`.`.`.`.`.`.`  .`.`.`.`.`.`.`.`  .`.`.`.`.`.`.`
#########  `.`.`.`.`.`  .`.`.`.`.`.`.`  .`.`.`.`.`.`.`.`
#########`.  `.`.`.`.`.`.`.`.`.`.`.`  .`.`.`.`.`.`.`.`.`
#########`.`.  `.`.`.`.`.`.`.`.`.`  .`.`.`.`.`.`.`.`.`.`
#########`.`.`.  `.`.`.`.`.`.`.`  .`.`.`.`.`.`.`.`.`.`.`
#########`.`.`.`.  `.`.`.`.`.`  .`.`.`.`.`.`.`.`.`.`.`.`
#########`.`.`.`.`.  `.`.`.`  .`.`.`.`.`.`.`.`.`.`.`.`.`
#########`.`.`.`.`.`.  `.`  .`.`.`.`.`.`.`.`.`.`.`.`.`.`
#########`.`.`.`.`.`.`.   .`.`.`.`.`.`.`.`.`.`.`.`.`.`.`
#########`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`
#########`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`
#########`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`
#########`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
FRQ = 0
FYORST = 1
class Solution:
########################################################
########################################################
########################################################
########################################################
    def mostFrequentWord( self, a, n ):
########################################################
########################################################
########################################################
########################################################
        tab = {}
        maxoccur = [ 0, -1 ]
        maxkey = None
        for j, key in enumerate( a ):
            if key in tab:
                occur = tab[key]
                occur[FRQ] += 1
                if maxoccur[FRQ] < occur[FRQ]:
                    maxoccur = occur
                    maxkey = key
                elif maxoccur[FRQ] == occur[FRQ]:
                    if occur[FYORST] > maxoccur[FYORST]:
                        maxoccur = occur
                        maxkey = key
            else:
                tab[key] = [ 1, j ]
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
        return maxkey
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
if __name__ == '__main__':##############################
    t=int(input())######################################
    for _ in range(t):##################################
        n=int(input())##################################
        arr=[x for x in input().strip().split()]########
        obj = Solution()################################
        print(obj.mostFrequentWord(arr,n))##############
########################################################
########################################################
########################################################
########################################################
########################################################
#　せんせい　せんせい　せんせい　せんせい　せんせい　せんせい
#　そうです　そうです　そうです　そうです　そうです　そうです
#　だいがく　だいがく　だいがく　だいがく　だいがく　だいがく
#　でんわ　でんわ　でんわ＿でんわ　でんわ　でんわ　でんわ
#　ともだち＿どもだち　ともだち　ともだち　ともだち　ともだち
#＿なまえ　なまえ　なまえ＿なまえ　なまえ　なまえ　なまえ
#〜ねんせい　〜ねんせい　〜ねんせい　〜ねんせい＿ねんせい
#　りゅうがくせい　りゅうがくせい　りゅうがくせい　りゅうがくっせい
#　わたし　わたち　わたち　わたし　わたし　わたし　わたし
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
# Test Cases Passed:                           301 / 301
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1302
# Total Time Taken:                                 0.06
