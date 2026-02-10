function longestBalanced(nums: number[]): number {
    let ans : number = 0, n : number = nums.length;
    for(let i : number = 0; i < n - 1; i++) {
        const even = new Set();
        const odd = new Set();
        for(let j : number = i; j < n; j++) {
            (nums[j] % 2 == 0) ? even.add(nums[j]) : odd.add(nums[j]);
            if(even.size == odd.size) ans = Math.max(ans, j - i + 1);
        }
    }
    return ans;  
};