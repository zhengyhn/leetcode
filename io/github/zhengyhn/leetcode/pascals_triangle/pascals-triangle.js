/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
  var result = [[]];    

  if (numRows <= 0) {
    return [];
  }

  for (var i = 0; i < numRows; ++i) {
    var row = [];
    row[0] = row[i] = 1;

    for (var j = 1; j < i; ++j) {
      row[j] = result[i - 1][j - 1] + result[i - 1][j];
    }
    result[i] = row;
  }

  return result;
};

console.log(generate(10));
