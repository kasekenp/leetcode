import scala.collection.mutable.HashMap

object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        var hashMap = new HashMap[Int, Int]
        for (i <- 0 until nums.size) {
            if (hashMap contains (target - nums(i))) {
                return Array(i, hashMap(target - nums(i)))
            }
            hashMap(nums(i)) = i
        }
        return Array(-1, -1)
    }
}
