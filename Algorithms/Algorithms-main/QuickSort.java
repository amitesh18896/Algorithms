import java.util.*;

/*
	worst-case time complexity -- O(n^2)
	best-case time complexity --  O(n.logn)
	average-case time complexity --  O(n.logn)

*/



public class QuickSort{
	// considering last element as pivot
	public int partition(int[] arr, int low, int high){
		int i = (low-1);
		int pivot = arr[high];
		for(int j=low;j<high;j++){
			if(arr[j] < pivot){
				i++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		int temp = arr[i+1];
		arr[i+1] = arr[high];
		arr[high] = temp;

		return i+1;
		
	}

	public void sortFunction(int[] arr, int low, int high){
		if(low < high){
			int index = partition(arr, low, high);
			sortFunction(arr, low, index-1);
			sortFunction(arr, index+1, high);
		}	
	}

	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int n;
		System.out.print("Enter size of array : ");
		n = input.nextInt();
		int[] array = new int[n];
		System.out.print("Enter the elements of array : ");
		for(int i=0;i<n;i++){
			array[i] = input.nextInt();
		}

		QuickSort obj = new QuickSort();
		obj.sortFunction(array, 0, n-1);

		System.out.print("Sorted array is : ");
		for(int i=0;i<n;i++)
			System.out.print(array[i]+" ");
		System.out.println();

	}
}