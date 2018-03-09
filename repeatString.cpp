class Solution {
public:
    /*
     * @param : string A to be repeated
     * @param : string B
     * @return: the minimum number of times A has to be repeated
     */
    int repeatedString(string &A, string &B) {
        size_t aSize = A.size();
        size_t pos = A.find(B.at(0));
        //only validate if string A contains first char of B
        if (pos != string::npos) {
            //only validate if string A contains first char of B 
            //and the following chars
            while (A.substr(pos) != B.substr(0,aSize - pos)) {
                pos = A.find(B.at(0), pos+1);
                if (pos == string::npos) {
                    return -1;
                }
            }
            size_t count = 0;
            if (B.size() > aSize) {
                count ++;
                B = B.substr(aSize - pos);
            }else if (A.find(B) != string::npos) {
                return 1;
            }
            while (A == B.substr(0, aSize)) {
                B = B.substr(aSize);
                count ++;
            }
            if (aSize > B.size()) {
                if ((B.size() > 0) && (A.substr(0,B.size()) == B)) {
                    count ++;
                }
                return count;
            }
        }
        return -1;
    }
};
