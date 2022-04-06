
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <stack>
#include <string>
using namespace std;
namespace sol1198
{
    class Solution
    {
    private:
    public:
        static int findSCE(vector<vector<int>> &mat);
        static int findSCE2(vector<vector<int>> &mat);
    };
}
#endif