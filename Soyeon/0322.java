//Kickstart20-A 2번 시간초과 줄여야댐
import java.util.*;
public class Solution {
	public static int max=0, n=0, k=0, p=0;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int test=in.nextInt();
		for(int t=0;t<test;t++) {
			n=in.nextInt();
			k=in.nextInt();
			p=in.nextInt();
			max=0;
			List<List<Integer>> plates = new ArrayList<List<Integer>>();
			for(int i=0;i<n;i++) {
				List<Integer> plate=new ArrayList<Integer>();
				for(int j=0;j<k;j++) {
					int input=in.nextInt();
					plate.add(input);
				}
				plates.add(plate);
			}
			findAll(plates, 0, 0, 0);
			System.out.println("Case #"+(t+1)+": "+max);
		}
	}
	public static void findAll(List<List<Integer>> plates, int listIndex, int Nplate, int Nbeauty) {
		if(Nplate==p || listIndex==n) {
			if(max<Nbeauty)
				max=Nbeauty;
			return;
		}
		int NEWbeauty=Nbeauty;
		findAll(plates, listIndex+1, Nplate, NEWbeauty); 
		for(int i=0;i<k;i++) {
			NEWbeauty+=plates.get(listIndex).get(i);
			if(Nplate+i+1<=p) {
				findAll(plates, listIndex+1, Nplate+i+1, NEWbeauty); 
			}
			else break;
		}
	}
}
