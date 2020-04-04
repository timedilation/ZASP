//코드잼 Qualification Round - Nesting Depth
import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int test=in.nextInt();
		for(int t=1;t<=test;t++) {
			String s=in.next();
			StringTokenizer st=new StringTokenizer(s,"0123456789",true);
			Stack<String> stack=new Stack<String>();
			System.out.print("Case #"+t+": ");
			
			int num=Integer.valueOf(st.nextToken());
			int total=0;
			for(int i=0;i<num;i++) {
				stack.add("(");
				total++;
				System.out.print("(");
			}
			stack.add(String.valueOf(num));
			System.out.print(num);
			
			while(st.hasMoreTokens()) {
				String sub=st.nextToken();
				int now=Integer.valueOf(sub);
				String bf=stack.peek();
				int before=Integer.valueOf(bf);
				if(now==before) {
					stack.add(sub);
					System.out.print(sub);
				}
				else if(now>before) {
					for(int i=0;i<now-before;i++) {
						stack.add("(");
						total++;
						System.out.print("(");
					}
					stack.add(sub);
					System.out.print(sub);
				}
				else {
					for(int i=0;i<before-now;i++) {
						stack.add(")");
						total--;
						System.out.print(")");
					}
					stack.add(sub);
					System.out.print(sub);
				}
			}
			for(int i=0;i<total;i++) {
				stack.add(")");
				System.out.print(")");
			}
			System.out.println();
		}
	}
}
