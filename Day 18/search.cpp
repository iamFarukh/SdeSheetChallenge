int search(int* arr, int n, int key)
{
    int st = 0, end = n - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == key)
          return mid;
        else if (arr[mid] >= arr[st])
        {
            if (arr[st] <= key && key <= arr[mid])
                end = mid - 1;
             else
                st = mid + 1;         
        }
        else
        {
            if (arr[end] >= key && key >= arr[mid])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
