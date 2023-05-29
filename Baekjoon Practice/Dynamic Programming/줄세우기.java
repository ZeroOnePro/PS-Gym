import java.util.*;
import java.io.IOException;

class Main{
    public static void main(String args[]) throws IOException{
       int[] dp = new int[200];
       int[] line = new int[200];
       int max = 1;
       Scanner scanner = new Scanner(System.in);

       int n = scanner.nextInt();

       for(int i=0; i<n; ++i){
           line[i] = scanner.nextInt();
       }
       for(int i=0; i<n; ++i){
           dp[i] = 1;
           for(int j=0; j<i; ++j){
               if(line[j] < line[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
               }
           }
           if(max < dp[i]){
            max = dp[i];
        }
       }
       System.out.println(n-max);
    }
}