//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high){
            return;
        }
        int p=partition(arr,low, high);
        
        //left
        quickSort(arr,low, p-1 );
        //right
        quickSort(arr, p+1,high);
        
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int countpivot=0;
       int p=arr[low];
       for(int i=low+1; i<=high; i++){
           if(arr[i]<=p){
               countpivot++;
           }
       }
       int shift= low+countpivot;
       int i=low;
       int j=high;
       swap(arr[low], arr[shift]);
       while(i<shift && j>shift){
          while(arr[i]<=p){
              i++;
          }
          while(arr[j]>p){
              j--;
          }
          if(i<shift && j>shift){
              swap(arr[i++], arr[j--]);
          }
       }
       return shift ;
       
       
       
       
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends