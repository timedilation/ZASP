import java.util.*;
public class Main {//boj14891

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int index[]=new int[4];
		char arr[][]=new char[4][8];
		for(int i=0;i<4;i++) 
		{
			String str=in.next();
			char ch[]=str.toCharArray();
			for(int j=0;j<8;j++) 
			{
				arr[i][j]=ch[j];
			}
		}
		int rotate=in.nextInt();
		for(int r=0;r<rotate;r++)
		{
			int num=in.nextInt()-1;
			int dir=in.nextInt();
			boolean doRotate[]=new boolean[4];
			doRotate[num]=true;
			//맞닿아 있는 부분 0,2 - 1,6 / 1,2 - 2,6 / 2,2 - 3,6
			for(int goright=num+1;goright<4;goright++) 
			{
				if(arr[goright-1][(index[goright-1]+2)%8]!=arr[goright][(index[goright]+6)%8])
				{
					doRotate[goright]=true;
				}
				else break;
			}
			for(int goleft=num-1;goleft>=0;goleft--) 
			{
				if(arr[goleft][(index[goleft]+2)%8]!=arr[goleft+1][(index[goleft+1]+6)%8])
				{
					doRotate[goleft]=true;
				}
				else break;
			}
			for(int n=0;n<4;n++) {
				if(doRotate[n])
				{
					if(Math.abs(n-num)%2==0)
					{
						if(dir==1)
						{//시계
							index[n]+=7;
							index[n]%=8;
						}
						else
						{
							index[n]++;
							index[n]%=8;
						}
					}
					else
					{
						if(dir==1)
						{//반시계
							index[n]++;
							index[n]%=8;
						}
						else
						{
							index[n]+=7;
							index[n]%=8;
						}
					}
				}
			}
		}
		int ans=0;
		if(arr[0][index[0]%8]=='1') ans+=1;
		if(arr[1][index[1]%8]=='1') ans+=2;
		if(arr[2][index[2]%8]=='1') ans+=4;
		if(arr[3][index[3]%8]=='1') ans+=8;
		System.out.println(ans);
	}
}
