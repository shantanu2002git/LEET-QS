public class Solution {
    public int rev(int n) {
        int re = 0;
        while (n > 0) {
            re = re * 10 + n % 10;
            n /= 10;
        }
        return re;
    }

    public long fact(int n) {
        if (n == 1)
            return 1;
        return n + fact(n - 1);
    }

    public int countNicePairs(int[] nums) {
        long count = 0;
        final int mod = 1000000007;

        for (int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        Map<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if (entry.getValue() > 1) {
                count = (count % mod + fact(entry.getValue() - 1)) % mod;
            }
        }

        return (int) count;
    }
}