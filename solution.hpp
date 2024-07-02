#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  //hq026
  //给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
  //考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
  //更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
  //返回 k 。
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
  //给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
  //假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
  //更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
  //返回 k。
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
  //给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
  //请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
  //注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
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