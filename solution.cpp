#include "solution.h"

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace sol1198;
using namespace std;

/*takeaways - findSCE
  - this solution is for the case where the numbers might
    be duplicated within a row
  - find the intersection among all rows
  - return the smallest number in the intersection
*/
/*takeaways - findSCE2
  - this solution assumes there is no duplicate
    in any given row
  - it's easier as you only need to scan through
    each number in each row until you find the very
    first number whose number of occurrences is
    the same as the number of rows
    - since every row is in ascending order, so
      the first qualified number is the smallest
    - only if that number appears in every row
      will the number of occurrences be the same
      as the number of rows
*/

int Solution::findSCE(vector<vector<int>> &mat)
{
  auto intersec = unordered_set<int>(mat[0].cbegin(), mat[0].cend());

  for (int i = 1; i < mat.size(); i++)
  {
    /* this will empty out intersec */
    const auto a = move(intersec);
    /* create a set out of mat[i] to remove duplicates */
    auto b = unordered_set(mat[i].cbegin(), mat[i].cend());

    /*copy the numbers that are both in a and b back to
      the intersec
      - use a as the source and compare to the numbers
        in b (a set)
    */
    copy_if(a.begin(), a.end(), inserter(intersec, intersec.begin()),
            /* check if the number from a is in b as well */
            [&b](const int x)
            { return b.count(x); });

    if (intersec.empty())
      return -1;
  }

  /*return the samllest number */
  return *min_element(intersec.begin(), intersec.end());
}

int Solution::findSCE2(vector<vector<int>> &mat)
{
  const int N = mat.size();
  auto freq = unordered_map<int, int>();
  for (const auto &row : mat)
    for (const auto &num : row)
    {
      freq[num]++;
      /* first number to achieve this
         will be the smallest number
         among those who appear in
         all rows as we are scanning
         the numbers in ascending
         order
      */
      if (freq[num] == N)
        return num;
    }

  return -1;
}