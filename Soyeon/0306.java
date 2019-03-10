/* boj 14501 */
import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in=new Scanner(System.in);
		int days=in.nextInt();
		int time[]=new int[days+1];
		int pay[]=new int[days+1];
		int pos[]=new int[days+1];
		for(int d=1;d<=days;d++) {
			time[d]=in.nextInt();
			pay[d]=in.nextInt();
		}
		for(int d=1;d<=days;d++) {
			for(int idx=time[d]+d;idx<=days;idx++) {
				pos[idx]=Math.max(pos[idx], pos[d]+pay[d]);
			}
		}
		for(int idx=1;idx<=days;idx++) {
			pay[idx]+=pos[idx];
			
			if(idx+time[idx]-1>days)
				pay[idx]=-1;
		}
		Arrays.sort(pay);
		System.out.println(pay[days]);
	}

}

