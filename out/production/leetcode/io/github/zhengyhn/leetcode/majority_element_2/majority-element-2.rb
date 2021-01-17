# @param {Integer[]} nums
# @return {Integer[]}
def majority_element(nums)
  m1, m2, m1Count, m2Count = 0, 0, 0, 0
  nums.each do |num|
    if num == m1
      m1Count += 1
    elsif num == m2
      m2Count += 1
    elsif m1Count == 0
      m1 = num
      m1Count = 1
    elsif m2Count == 0
      m2 = num
      m2Count = 1
    else
      m1Count -= 1
      m2Count -= 1
    end
  end

  m1Count = m2Count = 0
  nums.each do |num|
    if num == m1
      m1Count += 1
    elsif num == m2
      m2Count += 1
    end
  end

  res = []
  if m1Count > (nums.size / 3)
    res.push(m1)
  end

  if m2Count > (nums.size / 3)
    res.push(m2)
  end

  return res
end

puts majority_element([3, 2, 3])
