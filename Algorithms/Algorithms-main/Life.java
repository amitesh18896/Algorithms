import java.util.Scanner;

public class Question1 {
	public static void main(String[] args) throws InterruptedException {
		Scanner sc = new Scanner(System.in);
		/*If YOU want to GIVE grid as an Input then Uncomment this part of code!!!!
		 * System.out.println("Enter the value of m : "); int m = sc.nextInt();
		 * System.out.println("Enter the value of n : "); int n = sc.nextInt(); int[][]
		 * myGrid = new int[m][n];
		 * 
		 * System.out.println("Enter the Grid Elements : "); for (int i=0;i<m;i++) {
		 * for(int j=0;j<n;j++) { int temp = sc.nextInt(); if(temp<=0) myGrid[i][j]=0;
		 * if(temp>0) myGrid[i][j]=1;
		 * 
		 * } }
		 */

		int m = 10, n = 30;
		int[][] myGrid = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
				{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,0, 0, 0, 1, 1, 0, 0, 0, 0, 0,0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }, 
				{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,0, 0, 1, 1, 0, 0, 0, 0, 0, 0,0, 0, 1, 1, 0, 0, 0, 0, 0, 0 }, 
				{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,0, 0, 0, 0, 0, 1, 0, 0, 0, 0,0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

		System.out.println("The Original Generation was : ");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (myGrid[i][j] == 0)
					System.out.print(".");
				else
					System.out.print("*");
			}
			System.out.println();
		}
		System.out.println();
		int h = 1;
		while (h == 1) {

			System.out.println("Press 1 to Print Next Generation and 0 to Exit : ");
			int temp = sc.nextInt();
			if (temp > 0) {
				nextGenerationFunction(myGrid, m, n);
				

			} else
				break;
		}
	}

	static void nextGenerationFunction(int myGrid[][], int m, int n) {
		int[][] futureGeneration = new int[m][n];

		for (int l = 1; l < m - 1; l++) {
			for (int z = 1; z < n - 1; z++) {

				int noOfAliveNeighbours = 0;
				for (int i = -1; i <= 1; i++)
					for (int j = -1; j <= 1; j++)
						noOfAliveNeighbours += myGrid[l + i][z + j];

				noOfAliveNeighbours -= myGrid[l][z];

				if ((myGrid[l][z] == 1) && (noOfAliveNeighbours < 2))
					futureGeneration[l][z] = 0;

				else if ((myGrid[l][z] == 1) && (noOfAliveNeighbours > 3))
					futureGeneration[l][z] = 0;

				else if ((myGrid[l][z] == 0) && (noOfAliveNeighbours == 3))
					futureGeneration[l][z] = 1;

				else
					futureGeneration[l][z] = myGrid[l][z];
			}
		}

		System.out.println("The Next Generation is : ");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (futureGeneration[i][j] == 0)
					System.out.print(".");
				else
					System.out.print("*");
			}
			System.out.println();
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				myGrid[i][j] = futureGeneration[i][j];
			}
			System.out.println();
		}
	}
}
