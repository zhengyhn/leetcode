/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
  if (s.length != t.length) {
    return false;
  }
  var first = Array.apply(null, Array(26)).map(function () { return 0; });
  var second = first.slice();

  for (var i = 0; i < s.length; ++i) {
    first[s[i].charCodeAt(0) - 'a'.charCodeAt(0)] += 1;
  }
  for (var i = 0; i < t.length; ++i) {
    second[t[i].charCodeAt(0) - 'a'.charCodeAt(0)] += 1;
  }

  for (var i = 0; i < 26; ++i) {
    if (first[i] != second[i]) {
      return false;
    }
  }
  return true;
};

console.log(isAnagram('rat', 'cat'));
