# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
  if s.length != t.length
    return false
  end

  first = Array.new(26, 0)
  second = first.dup

  s.each_byte do |c|
    first[c - 'a'.ord] += 1
  end
  t.each_byte do |c|
    second[c - 'a'.ord] += 1
  end

  first.each_with_index do |n, i|
    if n != second[i]
      return false
    end
  end
  
  return true
end

puts is_anagram('', '')
puts is_anagram('rat', 'cat')
