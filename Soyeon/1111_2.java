import java.util.*;
public class Main {

	public static void main(String[] args) {//boj14503
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int m=in.nextInt();
		int arr[][]=new int[n][m];
		int r=in.nextInt();
		int c=in.nextInt();
		int d=in.nextInt();//d=0:앞, d=1:오, d=2:뒤, d=3:왼
		int dr[]= {-1, 0, 1, 0};
		int dc[]= {0, 1, 0, -1};
		for(int i=0;i<n;i++) 
		{
			for(int j=0;j<m;j++)
			{
				arr[i][j]=in.nextInt();
			}
		}

		int ans=0;
		while(true) 
		{
			//System.out.println(ans);
			if(arr[r][c]==0)
			{//현재 위치 청소
				ans++;
				arr[r][c]=-1;
			}

			if(arr[r-1][c]*arr[r][c-1]*arr[r+1][c]*arr[r][c+1]!=0 && arr[r+dr[(d+2)%4]][c+dc[(d+2)%4]]==1)
			{//네 방향 모두 청소 또는 벽, 후진 불가능
				break;
			}
			else if(arr[r-1][c]*arr[r][c-1]*arr[r+1][c]*arr[r][c+1]!=0 && arr[r+dr[(d+2)%4]][c+dc[(d+2)%4]]==-1)
			{//네 방향 모두 청소 또는 벽, 후진 가능
				r=r+dr[(d+2)%4];
				c=c+dc[(d+2)%4];
			}
			else if(arr[r+dr[(d+3)%4]][c+dc[(d+3)%4]]==0)
			{//왼쪽방향에 청소 안되어 있으면
				d=(d+3)%4;
				r=r+dr[d];
				c=c+dc[d];
			}
			else if(arr[r+dr[(d+3)%4]][c+dc[(d+3)%4]]!=0)
			{//왼쪽방향 이미 청소 또는 벽, 왼쪽으로 회전
				d=(d+3)%4;
			}

		}
		System.out.println(ans);
	}
}
