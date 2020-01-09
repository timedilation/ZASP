/*boj14499*/
import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		//지도 가로 세로
		int N=in.nextInt();
		int M=in.nextInt();
		//주사위 위치 (row, col)
		int x=in.nextInt();
		int y=in.nextInt();
		//명령 개수
		int K=in.nextInt();

		int map[][]=new int[N][M];
		for(int r=0;r<N;r++) {
			for(int c=0;c<M;c++) {
				map[r][c]=in.nextInt();
			}
		}

		int dice[]=new int[7];
		for(int i=0;i<K;i++) {
			int move=in.nextInt();
			if(move==1) {//동
				if(inBoundary(N,M,x,y+1)) {
					y+=1;

					int temp=dice[1];
					dice[1]=dice[3];
					dice[3]=dice[6];
					dice[6]=dice[4];
					dice[4]=temp;

					if(map[x][y]==0) {
						map[x][y]=dice[6];
					}
					else {
						dice[6]=map[x][y];
						map[x][y]=0;
					}
					System.out.println(dice[1]);
				}
			}
			else if(move==2) {//서
				if(inBoundary(N,M,x,y-1)) {
					y-=1;
					
					int temp=dice[1];
					dice[1]=dice[4];
					dice[4]=dice[6];
					dice[6]=dice[3];
					dice[3]=temp;

					if(map[x][y]==0) {
						map[x][y]=dice[6];
					}
					else {
						dice[6]=map[x][y];
						map[x][y]=0;
					}
					System.out.println(dice[1]);
				}
			}
			else if(move==3) {//북
				if(inBoundary(N,M,x-1,y)) {
					x-=1;

					int temp=dice[1];
					dice[1]=dice[2];
					dice[2]=dice[6];
					dice[6]=dice[5];
					dice[5]=temp;

					if(map[x][y]==0) {
						map[x][y]=dice[6];
					}
					else {
						dice[6]=map[x][y];
						map[x][y]=0;
					}
					System.out.println(dice[1]);
				}
			}
			else if(move==4) {//남
				if(inBoundary(N,M,x+1,y)) {
					x+=1;

					int temp=dice[1];
					dice[1]=dice[5];
					dice[5]=dice[6];
					dice[6]=dice[2];
					dice[2]=temp;

					if(map[x][y]==0) {
						map[x][y]=dice[6];
					}
					else {
						dice[6]=map[x][y];
						map[x][y]=0;
					}
					System.out.println(dice[1]);
				}
			}
		}
	}
	public static boolean inBoundary(int N, int M, int r, int c) {
		if(r>=0 && r<N && c>=0 && c<M) 
			return true;
		return false;
	}
}
