public class QuickSort {
    public static int partition(int[] A,int p, int r){
        int temp;
        int x = A[r];
        int i = p-1;
        for (int j=p;j<=r-1;j++){
            if(A[j]<=x){
                i = i+1;
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        temp = A[i+1];
        A[i+1] = A[r];
        A[r] = temp;
        return i+1;
    }
    public static int[] quickSort(int[] A,int p, int r ){
        if (p<r){
            int q= partition(A, p, r);
            quickSort(A, p,q-1);
            quickSort(A, q+1, r);
        }
        return A;
    }
    public static void main(String[] args) {
        System.out.println("Hello and welcome! This is a simple Test for the quick sort!");
        int []A = new int[]{9, 4, 6, 3, 2};
        A = quickSort(A, 0, A.length - 1);
        for (int i = 0; i < A.length; i++) {
            System.out.println("i = " + A[i]);
        }

    }
}