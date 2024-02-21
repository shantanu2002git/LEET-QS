class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // Find the common prefix of left and right by shifting right until they are equal
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        // Shift back the common prefix to its original position
        return left << shift;
    }
};
/*if say ^ :

class Solution {
public:
    int rangeBitwiseXOR(int left, int right) {
        int xorResult = 0;
        // Find the common prefix of left and right by shifting right until they are equal
        while (left < right) {
            left >>= 1;
            right >>= 1;
        }
        // Calculate XOR of the common prefix
        xorResult = left ^ right;
        return xorResult;
    }
};




or :
int rangeBitwiseOr(int left, int right) {
    int result = 0;
    // Find the common prefix of left and right by shifting right until they are equal
    while (left < right) {
        left >>= 1;
        right >>= 1;
        result |= left;
    }
    return result;
}

*/