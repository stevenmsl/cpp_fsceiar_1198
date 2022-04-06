#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1198;

/*
Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5
*/

tuple<vector<vector<int>>, int> testFixture1()
{

  return make_tuple(vector<vector<int>>{
                        {1, 2, 3, 4, 5},
                        {2, 4, 5, 8, 10},
                        {3, 5, 7, 9, 11},
                        {1, 3, 5, 7, 9}},
                    5);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<1>(f)) << endl;
  cout << "result: " << to_string(Solution::findSCE(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<1>(f)) << endl;
  cout << "result: " << to_string(Solution::findSCE2(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}