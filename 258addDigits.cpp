/*
����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����

ʾ��:

����: 38
���: 2 
����: ��λ��ӵĹ���Ϊ��3 + 8 = 11, 1 + 1 = 2�� ����?2 ��һλ�������Է��� 2��
����:
����Բ�ʹ��ѭ�����ߵݹ飬���� O(1) ʱ�临�Ӷ��ڽ�����������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-digits
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int addDigits(int num) {
        int tmp;
        return (num<10)?num:(tmp=num%9)?tmp:9;
    }
};


// class Solution {
// public:
//     int addDigits(int num) {
//         while (num/10) {
//             int tmp=0;
//             while (num) {
//                 tmp+=num%10;
//                 num/=10;
//             }
//             num=tmp;
//         }
//         return num;
//     }
// };


