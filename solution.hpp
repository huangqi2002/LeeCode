#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  //hq026
  //����һ�� ���ϸ�������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����
  //���� nums ��ΨһԪ�ص�����Ϊ k ������Ҫ����������ȷ����������Ա�ͨ����
  //�������� nums ��ʹ nums ��ǰ k ��Ԫ�ذ���ΨһԪ�أ���������������� nums �г��ֵ�˳�����С�nums ������Ԫ���� nums �Ĵ�С����Ҫ��
  //���� k ��
  int removeDuplicates(vector<int>& nums) {
    int k = 0;
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] != nums[k])
      {
        k++;
        nums[k] = nums[i];
      }
    }
    return k + 1;
  }

  //hq027
  //����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�ء�Ԫ�ص�˳����ܷ����ı䡣Ȼ�󷵻� nums ���� val ��ͬ��Ԫ�ص�������
  //���� nums �в����� val ��Ԫ������Ϊ k��Ҫͨ�����⣬����Ҫִ�����²�����
  //���� nums ���飬ʹ nums ��ǰ k ��Ԫ�ذ��������� val ��Ԫ�ء�nums ������Ԫ�غ� nums �Ĵ�С������Ҫ��
  //���� k��
  int removeElement(vector<int>& nums, int val) {
    int count = 0, nums_size = nums.size();
    for (int i = 0; i < nums_size; i++)
    {
      while (nums_size > i and nums[nums_size - 1] == val)
      {
        nums_size--;
      }
      if (nums_size > i and nums[i] == val)
      {
        nums[i] = nums[nums_size - 1];
        nums_size--;
      }
    }
    return nums_size;
  }

  //hq088
  //���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
  //���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
  //ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    while (m!=0 or n!=0)
    {
      if (m == 0)
      {
        nums1[m + n - 1] = nums2[n - 1];
        n -= 1;
      }
      else if (n == 0)
      {
        nums1[m + n - 1] = nums1[m - 1];
        m -= 1;
      }
      else
      {
        int count = 0;
        while (m - 1 - count >= 0 and nums1[m - 1 - count] > nums2[n - 1])
          count++;
        for (int i = 0; i < count; i++)
        {
          nums1[m + n - 1] = nums1[m - 1];
          m -= 1;
        }
        nums1[m + n - 1] = nums2[n - 1];
        n -= 1;
      }
    }
  }
};