/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isTrionic = function(nums) {
    const n = nums.length;
    let i = 1;
    while (i < n && nums[i] > nums[i - 1]) i++;
    if (i === 1 || i === n) return false;
    while (i < n && nums[i] < nums[i - 1]) i++;
    if (i === n) return false;
    while (i < n && nums[i] > nums[i - 1]) i++;
    return i === n;
};
