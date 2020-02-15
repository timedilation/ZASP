#codeJAM IO WOMAN 2020 1번
import java.util.*;
public class Solution {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int testcase=in.nextInt();
		for(int t=1;t<=testcase;t++) {
			String input=in.next();
			Stack<String> stack=new Stack<String>();
			StringTokenizer st=new StringTokenizer(input, "IOio", true);
			while(st.hasMoreTokens()) {
				String token=st.nextToken();
				stack.add(token);
			}
			
			int ans=0;
			int I=0;
			int i=0;
			int O=0;
			int o=0;
			while(!stack.isEmpty()) {
				String pop=stack.pop();
				if(pop.equals("O")) {
					O++;
				}
				else if(pop.equals("o")) {
					o++;
				}
				else if(pop.equals("I")) {
					if(O>=1) {
						ans++;
						O--;
					}
					else {
						o--;
					}
				}
				else {
					if(o>=1) {
						o--;
					}
					else {
						O--;
					}
				}
			}
			System.out.println("Case #"+t+": "+ans);
		}
	}

}
