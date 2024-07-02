#include "solution.hpp"
#include <chrono>

int main()
{
  vector<int> nums1 = { 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
  Solution sol;

  auto beforeTime = std::chrono::steady_clock::now();
  int k = sol.removeDuplicates(nums1);
  auto afterTime = std::chrono::steady_clock::now();

  for (int i =0;i<k;i++)
    cout << nums1[i] << endl;

  //Î¢Ãî¼¶
  double duration_microsecond = std::chrono::duration<double, std::micro>(afterTime - beforeTime).count();
  std::cout << duration_microsecond << "Î¢Ãë" << std::endl;
}