/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
  var m1, m2, m1Count, m2Count;

  m1 = m2 = m1Count = m2Count = 0;

  for (var i = 0; i < nums.length; ++i) {
    if (m1 == nums[i]) {
      ++m1Count;
    } else if (m2 == nums[i]) {
      ++m2Count;
    } else if (m1Count == 0) {
      m1 = nums[i];
      m1Count = 1;
    } else if (m2Count == 0) {
      m2 = nums[i];
      m2Count = 1;
    } else {
      --m1Count;
      --m2Count;
    }
  }

  m1Count = m2Count = 0;
  for (var i = 0; i < nums.length; ++i) {
    if (m1 == nums[i]) {
      ++m1Count;
    } else if (m2 == nums[i]) {
      ++m2Count;
    }
  }
  var res = [];
  if (m1Count > (nums.length / 3)) {
    res.push(m1);
  }
  if (m2Count > (nums.length / 3)) {
    res.push(m2);
  }
  return res;
};

var res = majorityElement([3, 2, 3]);
console.log(res);
