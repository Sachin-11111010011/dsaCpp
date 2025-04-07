void moveZerosToLeft(int *arr, int n) {
    vector<int> temp;

    // Step 1: Collect all non-zero elements
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    int zeros = n - temp.size();  // Number of zeros to be placed at the front

    // Step 2: Fill the start with zeros
    for (int i = 0; i < zeros; i++) {
        arr[i] = 0;
    }

    // Step 3: Copy non-zero elements after zeros
    for (int i = 0; i < temp.size(); i++) {
        arr[zeros + i] = temp[i];
    }
}