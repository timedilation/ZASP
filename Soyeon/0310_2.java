/* boj 13460 */
import java.util.*;
public class Main {
	public static int n, m, row, col;
	public static int visit[][][][];
	public static int Rrow, Rcol, Brow, Bcol;
	public static char mat[][];
	public static int dr[] = { 0,0,1,-1 },
	                  dc[] = { 1,-1,0,0 };// 오른쪽 왼쪽 아래 위
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		row=in.nextInt();
		col=in.nextInt();
		mat=new char[row][col];
		Queue<move> queue=new LinkedList<move>();
		visit=new int[row][col][row][col];
		for(int i=0;i<row;i++) {
			String str=in.next();
			mat[i]=str.toCharArray();
			for(int j=0;j<col;j++) {
				if(mat[i][j]=='R') {
					Rrow=i;
					Rcol=j;
				}
				else if(mat[i][j]=='B') {
					Brow=i;
					Bcol=j;
				}
			}
		}
		visit[Rrow][Rcol][Brow][Bcol]=1;
		queue.offer(new move(Rrow, Rcol, Brow, Bcol));
		
		int ans=0;
		while(!queue.isEmpty()) {
			int size=queue.size();
			while(size!=0) {
				move m=queue.poll();
				int rr=m.Rrow;
				int rc=m.Rcol;
				int br=m.Brow;
				int bc=m.Bcol;
				
				if(mat[rr][rc]=='O') {
					System.out.println(ans);
					return;
				}
				for(int i=0;i<4;i++) {
					int nbr=br;
					int nbc=bc;
					int nrr=rr;
					int nrc=rc;
					boolean BlueFalls=false;
					
					//장애물 만나기 전까지 옮긴다
					while(isBoundary(nrr+dr[i],nrc+dc[i]) && mat[nrr+dr[i]][nrc+dc[i]]!='#' && mat[nrr][nrc]!='O') {
						nrr+=dr[i];
						nrc+=dc[i];
					}
					while(isBoundary(nbr+dr[i],nbc+dc[i]) && mat[nbr+dr[i]][nbc+dc[i]]!='#' && mat[nbr][nbc]!='O') {
						nbr+=dr[i];
						nbc+=dc[i];
						
						if(mat[nbr][nbc]=='O')
							BlueFalls=true;
					}
					//파란공과 빨간공 중 어느 공이 먼저 움직이는지 파악
					if(nrr==nbr && nrc==nbc) {//둘이 만나면
						if(i==0) {//오른쪽
							if(bc>rc)
								nrc-=1;
							else
								nbc-=1;
						}
						else if(i==1) {//왼쪽
							if(bc>rc)
								nbc+=1;
							else
								nrc+=1;
						}
						else if(i==2) {//아래
							if(br>rr)
								nrr-=1;
							else
								nbr-=1;
						}
						else {//위
							if(br>rr)
								nbr+=1;
							else
								nrr+=1;
						}
					}
					if(BlueFalls)//파란구슬이 빠져나오는 경우
						continue;
					if(visit[nrr][nrc][nbr][nbc]==1)
						continue;
					
					queue.offer(new move(nrr, nrc, nbr, nbc));
					visit[nrr][nrc][nbr][nbc]=1;
				}
				size--;
			}
			ans++;
			if(ans>10) {
				System.out.println("-1\n");
				return;
			}
		}
		System.out.println("-1");
	}
	public static boolean isBoundary(int ROW,int COL) {
		if(ROW>=0 && ROW<row && COL>=0 && COL<col)
			return true;
		else
			return false;
	}
}
class move{
	int Rrow, Rcol, Brow, Bcol;
	public move() {
		
	}
	public move(int Rrow, int Rcol, int Brow, int Bcol) {
		this.Rrow=Rrow;
		this.Rcol=Rcol;
		this.Brow=Brow;
		this.Bcol=Bcol;
	}
}
