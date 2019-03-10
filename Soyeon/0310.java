/* boj 16236 priority queue, compareTo */
import java.util.*;
public class Main {
	public static int size=2, eat, n;
	public static int start_row, start_col;
	public static int mat[][];
	public static int dc[] = { 0,1,0,-1 };
	public static int dr[] = { 1,0,-1,0 };

	public static PriorityQueue<move> pos=new PriorityQueue<move>();
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		n=in.nextInt();
		mat=new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				mat[i][j]=in.nextInt();

				if(mat[i][j]==9) {
					start_row=i;
					start_col=j;
				}
			}
		}
		System.out.println(EatFish());
	}
	public static void resetVisit(int visit[][]) {
		for(int i=0;i<n;i++) {
			Arrays.fill(visit[i], 0);
		}
		return;
	}
	public static boolean isBoundary(int row,int col) {
		if(row>=0 && col>=0 && row<n && col<n)
			return true;
		else return false;
	}
	public static void bfs() {
		Queue<move> queue=new LinkedList<move>();
		boolean[][] visited = new boolean[n][n];
		int dist = Integer.MAX_VALUE;

		queue.offer(new move(0, start_row, start_col));
		visited[start_row][start_col]=true;

		while (!queue.isEmpty()) {

			move node = queue.poll();
			int row = node.row;
			int col = node.col;
			int cnt = node.count;

			for (int i = 0; i < 4; i++) {

				int nr = row + dr[i];
				int nc = col + dc[i];

				if (isBoundary(nr, nc) && !visited[nr][nc] && cnt < dist && mat[nr][nc] <= size) {

					if (mat[nr][nc] > 0 && mat[nr][nc] < size) {

						dist = Math.min(dist, cnt + 1);
						pos.offer(new move(cnt+1, nr, nc));
						visited[nr][nc] = true;

					}
					else if (mat[nr][nc] == 0 || mat[nr][nc] == size) {

						queue.offer(new move(cnt + 1, nr, nc));
						visited[nr][nc] = true;
					}
				}
			}
		}
	}
	public static int EatFish() {
		int ans=0;
		while (true) {
			 
            bfs();
            if (pos.isEmpty())
                return ans;
 
            move fish = pos.poll();
            ans += fish.count;
            mat[start_row][start_col] = 0;
            start_row = fish.row;
            start_col = fish.col;
            eat += 1;
 
            if (eat == size) {
                size += 1;
                eat = 0;
            }
            pos.clear();
        }
	}
}
class move implements Comparable<move>{
	Integer count, row, col;

	public move() {

	}
	public move(int count, int row, int col) {
		this.count=count;
		this.row=row;
		this.col=col;
	}
	@Override
	public int compareTo(move o) {
		 if (this.row == o.row) {
	            return col.compareTo(o.col);
	     } 
		 else {
	            return row.compareTo(o.row);
	     }
	}
	public String toString() {
		return count+" "+row+" "+col+"\n";
	}
}
