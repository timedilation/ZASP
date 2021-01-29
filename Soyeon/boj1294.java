// https://sysgongbu.tistory.com/138
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();

		PriorityQueue<StringBuffer> queue = new PriorityQueue<StringBuffer>();
		for (int i = 0; i < n; i++) {
			queue.add(new StringBuffer(in.next() + "a"));
		}

		while (!queue.isEmpty()) {
			StringBuffer alphabet = queue.poll();

			System.out.print(alphabet.charAt(0));
			alphabet.deleteCharAt(0);

			if (alphabet.length() > 1) {
				queue.add(alphabet);
			}
			alphabet = null;
		}
		System.out.println();
	}
}
