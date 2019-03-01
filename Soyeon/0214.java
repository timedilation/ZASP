/** 이진 트리의 같은 깊이의 노드를 연결리스트로 연결하는 방법을 구하라 **/
import java.util.*;
public class Main {

	public static void main(String[] args) {
		//input tree
		Node node1=new Node(1);
		Node node2=new Node(2);
		Node node3=new Node(3);
		Node node4=new Node(4);
		Node node5=new Node(5);
		Node node6=new Node(6);
		Node node7=new Node(7);
		Node node8=new Node(8);
		
		node1.left=node2; node1.right=node3;
		node2.left=node4; node2.right=node5;
		node3.left=node6; node3.right=node7;
		node4.left=node8; node4.right=null;
		node5.left=null; node5.right=null;
		node6.left=null; node6.right=null;
		node7.left=null; node7.right=null;
		node8.left=null; node8.right=null;
		Node root=node1;

		LinkedList<LinkedList<Node>> answer=findSameDepth(root);
		System.out.println(answer);
	}
	public static LinkedList<LinkedList<Node>> findSameDepth(Node root){
		LinkedList<LinkedList<Node>> answer=new LinkedList<LinkedList<Node>>();
		LinkedList<Node> sameDepth=new LinkedList<Node>();

		sameDepth.add(root);
		answer.add(sameDepth);

                //시간 복잡도 O(N^2) ??
		while(true) {
			LinkedList<Node> nextDepth=new LinkedList<Node>();
			for(Node d:sameDepth) {
				if(d.left!=null)
					nextDepth.add(d.left);
				if(d.right!=null)
					nextDepth.add(d.right);
			}
			sameDepth=nextDepth;
			if(!sameDepth.isEmpty())
				answer.add(sameDepth);
			else
				return answer;
		}
	}
}
class Node{
	int value;
	Node left;
	Node right;
	public Node() {

	}
	public Node(int value) {
		this.value=value;
	}
	public String toString() {
		return String.valueOf(value);
	}
}
