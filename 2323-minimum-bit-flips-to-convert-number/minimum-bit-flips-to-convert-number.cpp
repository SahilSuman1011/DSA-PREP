class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int differentBit = start ^ goal;

        while(differentBit){
            if(differentBit & 1){
                count ++;
            }
            differentBit = differentBit >> 1;
        }
        return count;
    }
};