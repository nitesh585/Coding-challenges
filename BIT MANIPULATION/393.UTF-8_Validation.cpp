/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

    For 1-byte character, the first bit is a 0, followed by its unicode code.
    For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.

*/

class Solution {
public:

    int setbits(int num){
        int cnt=0;
        int tmp=128;
        while(num&tmp){
            cnt++;
            tmp>>=1;
        }
        return cnt;
    }
    
    bool validUtf8(vector<int>& data) {
        for(int  i=0;i<data.size() ; ++i){
            int nSetBits = setbits(data[i])-1;
            if( (nSetBits==0 ) ||  (nSetBits>=4) ){
                return false;
            }
            
            for(int j=0;j<nSetBits; ++j){
                ++i;
                if(i<data.size()){
                   if( !( (data[i]|128) == data[i] ) ){
                    return false;
                    }    
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
