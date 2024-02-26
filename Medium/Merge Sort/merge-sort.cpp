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
    void merge(int arr[], int l, int r){
        int mid=(l+r)/2;
        int l1=mid-l+1;
        int l2=r-mid;
        int *first=new int[l1];
        int *second=new int[l2];
        
        int k=l;
        
        for(int i=0;i<l1;i++){
            first[i]=arr[k++];
        }
         k=mid+1;
        for(int i=0;i<l2; i++){
            second[i]=arr[k++];
        }
        
        //merge 2 sorted array
        int i=0;
        int j=0;
        int y=l;
        while(i<l1 && j<l2){
            if(first[i]>second[j]){
                arr[y++]=second[j++];
             
            }
            else{
                if(first[i]<=second[j]){
                arr[y++]=first[i++];
               
                }
           
            }
        
    }
    while(i<l1){
        arr[y++]=first[i++];
    }
    while(j<l2){
        arr[y++]=second[j++];
    }
    } 
    public:
    void mergeSort(int arr[], int l, int r)
    {
       if(l>=r){
           return;
       }
       int mid=l+(r-l)/2;
       
       mergeSort(arr,l,mid);
       mergeSort(arr,mid+1,r);
       
       merge(arr,l,r);
       
       
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends