//BOJ 9466
import java.util.*;
import java.io.*;
public class Main {
	public static int n;
	public static int ans;
	public static int arr[] = new int[100001];	
	public static StringTokenizer st = null;
	public static int node;
	public static int pop;
	public static Stack<Integer> stack=new Stack<Integer>();
	public static void main (String args[]) throws Exception{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); //선언
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//선언
		int test = Integer.parseInt(bf.readLine()); //Int
		for(int t=0;t<test;t++) {
			n = Integer.parseInt(bf.readLine());
			st = new StringTokenizer(bf.readLine());
	        for (int i = 1; i <= n; i++) {
	            // 배열에다 토큰을 하나씩 불러서 입력해줌
	            arr[i] = Integer.parseInt(st.nextToken());
	        }
			ans=0;
			int visited[]=new int[n+1];
			for(int i=1;i<=n;i++) {
				if(visited[i] == 0) {
					stack.clear();
					stack.add(i);
					visited[i] = 1;
					node = i;
					
					Cycle:
					while(true) {
						if(visited[arr[node]] == 1 && stack.contains(arr[node])) {
							while(!stack.isEmpty()) {
								pop = stack.pop();
								visited[pop] = -1;
								ans++;
								//System.out.println(pop);
								if(arr[node] == pop) {
									while(!stack.isEmpty()) {
										visited[stack.pop()] = -1;
									}
									break Cycle;
								}
							}
						}
						if(visited[arr[node]] == -1) {
							while(!stack.isEmpty()) {
								visited[stack.pop()]=-1;
							}
							break Cycle;
						}
						
						node= arr[node];
						visited[node] = 1;
						stack.add(node);	
					}
				}
			}
			bw.write(n-ans+"\n");//출력
			bw.flush();//남아있는 데이터를 모두 출력시킴
		}
		bw.close();
	}
}

