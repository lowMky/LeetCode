//˼·��ά��������Ԫ��

class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int head = 1;
        int remain = n;
        int tmp =1;

        while(remain>1){
            if(remain%2 || left)
                head = head+tmp;
            left = !left;
            remain/=2;
            tmp*=2;
        }
        return head;
    }
};
