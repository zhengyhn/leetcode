# @param {Integer} num_rows
# @return {Integer[][]}
def generate(num_rows)
  result = [[]]

  if num_rows <= 0
    return []
  end

  0.upto(num_rows - 1) do |i|
    row = []
    row[0] = row[i] = 1

    1.upto(i - 1) do |j|
      row[j] = result[i - 1][j - 1] + result[i - 1][j]
    end
    result[i] = row
  end

  return result
end

res = generate(5)
res.each do |row|
  row.each do |elem|
    print elem
    print ' '
  end
  print "\n"
end
