/** list마다 숫자가 써 있는데, 
 * list가 해당 칸에서 최대 점프할 수 있는 길이일 때, 
 * 첫 번째 -> 마지막 칸에 다다를수 있는지 : boolean toEnd(LinkedList<Integer>)
 * 첫 번째 -> 마지막 칸에 다다르는 최소의 점프 수: int minJump(LinkedList<Integer>)
 **/
import java.util.*;
public class Main {

	public static void main(String[] args) {	
		//[2, 0, 1, 1, 2] -> true
		//[1, 0, 2, 1, 3] -> false
		int list[]= {3,0,8,2,0,0,1};
		System.out.println(list);
	}
	public static boolean toEnd(int[] list) {
		int length=list.length;
		int reach[]=new int[length];// reach[i]: i번째 칸에 도달할 수 있으면 1, 없으면 0
		
		//시간 복잡도 O(N^2)
        reach[0]=1;
		for(int idx=0;idx<length;idx++) {
			//도달 할 수 있는 경우에만 체크해야 하는 것 빼먹지 말자
			if(reach[idx]==1){// list에 원소 하나있을 때 주의
			    for(int jump=1;jump<=list[idx];jump++) {
			    	if(idx+jump<length)
				    	reach[idx+jump]=1;
			    }
            }
		}
		
		boolean isPossible=false;
		if(reach[length-1]==1)
			isPossible=true;
		
		return isPossible;
	}
	public static int minJump(LinkedList<Integer> list) {
		int jump=0;
		
		
		return jump;
	}
}
