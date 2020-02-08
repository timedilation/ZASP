//boj 10974
import java.util.*;
import java.io.*;
public class Main {
	public static void main (String args[]) throws Exception{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=i+1;
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		printPermutation(arr, n);
	}
	public static int findIndex(int arr[], int n) {
		for(int i=n-1;i>=1;i--) {
			if(arr[i-1]<arr[i])
				return i;
		}
		return -1;
	}
	public static void printPermutation(int arr[], int n) {
		while(true) {
			int idex = findIndex(arr, n);
			if(idex == -1) return;
			
			int jdex=0;
			for(int j=n-1;j>=idex;j--) {
				if(arr[j]>arr[idex-1]) {
					jdex=j;
					break;
				}
			}

			int temp=arr[jdex];
			arr[jdex]=arr[idex-1];
			arr[idex-1]=temp;

			int brr[]=new int[n];
			int bindex=0;
			for(int i=0;i<idex;i++) {
				brr[bindex++]=arr[i];
				System.out.print(arr[i]+" ");
			}
			for(int i=n-1;i>=idex;i--) {
				brr[bindex++]=arr[i];
				System.out.print(arr[i]+" ");
			}
			arr=brr;
			System.out.println();

		}
	}
}
