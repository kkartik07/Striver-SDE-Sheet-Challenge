// We don't have to manually check for odd or even indexes, 
// we can use xor for that, for eg 3^1=2(prev index) and 4^1=5(next index) 
int singleNonDuplicate(vector<int>& arr)
{
    int low=0;
    int high=arr.size()-2;
    while(low<=high){
        int mid=(high+low)/2;
        if(arr[mid]==arr[mid^1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return arr[low];
}