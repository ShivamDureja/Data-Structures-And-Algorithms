private String LCS (String text1,String text2,int n,int m)
{
    
    int[][] t = new int[1001][1001];
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            
         if (i==0 || j==0);
            {
                t[i][j] = 0;
            }
        }
     }
    for (int i = 1;i<n+1;i++)
    {
        for (int j = 1;j<m+1;j++)
        {
            if (text1.charAt(i-1) == text2.charAt(j-1))
            {
                t[i][j] = 1+t[i-1][j-1];
            }else{
                 t[i][j] = Math.max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    
 int i=n;
 int j=m;
 StringBuilder str2  = new StringBuilder();
 while (i>0 && j>0)
 {
     if(text1.charAt(i-1) == text2.charAt(j-1))
     {
         str2.append(text1.charAt(i-1));
         i--;
         j--;
     }else 
     {
         if (t[i][j-1] > t[i-1][j])
         {
             j--;
         }else{
             i--;
         }
     }
     
     
 }
   return  str2.reverse().toString();
    
    
}
    
    
