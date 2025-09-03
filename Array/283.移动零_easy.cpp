/*
283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
*/

/**
 * 1. offset 偏移量
 * offset 初始为 0
 * 不为 0 就进行 offset 偏移
 * 遇到 0 则 offset+1
 */
class Solution {
public:
    void moveZeros(vector<int>& nums) {
        int offset = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++offset;
                continue;
            }
            if (offset == 0) {
                continue;
            }

            nums[i - offset] = nums[i];
            nums[i] = 0;
        }
    }
};


/**
 * 2. 双指针
 * 左指针 始终指向第一个 0
 * 右指针 依次遍历，与左指针不重叠就 swap
 */
