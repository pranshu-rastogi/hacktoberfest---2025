double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 1;              // current position in merged array (starting from 1)
    int i1 = 0, i2 = 0;     // current element index of input arrays (starting from 0)
    int pos1, pos2;         // location of mean number(s) of merged array
    int n, n1 = 0, n2 = 0;  // current value and values at the correct locations when reached

    // calculate median location of two combined arrays. both are the same in case of even length of elements
    pos2 = (nums1Size + nums2Size) / 2 + 1;
    pos1 = pos2 + ((nums1Size + nums2Size) % 2) - 1;

    while (1) {
        if (i1 == nums1Size) {                  // no more elements in 1st array
            // optimisation: get values by index when only one array remains
            if (i <= pos1)                      // first number is also in remaining array
                n1 = nums2[pos1 - nums1Size - 1];
            n2 = nums2[pos2 - nums1Size - 1];   // second number is always in remaining array
            break;
            // without optimisation just continue with 2nd array
            // n = nums2[i2++];
        } else if (i2 == nums2Size) {           // no more elements in 2nd array
            // optimisation: get values by index when only one array remains
            if (i <= pos1)                      // first number is also in remaining array
                n1 = nums1[pos1 - nums2Size - 1];
            n2 = nums1[pos2 - nums2Size - 1];   // second number is always in remaining array
            break;
            // without optimisation just continue with 1st array
            // n = nums1[i1++];
        } else {                                // take smaller element
            if (nums1[i1] < nums2[i2]) {
                n = nums1[i1++];
            } else {
                n = nums2[i2++];
            }
        }
        if (i >= pos1) {                // pos1 has been reached, take first and/or second number
            if (i == pos1)
                n1 = n;
            if (i == pos2)
                n2 = n;
            if (i == pos2)              // pos2 has been also reached, we have both bumbers and finish
                break;
        }
        i++;
    }
    return((double)(n1 + n2) / 2);
}
