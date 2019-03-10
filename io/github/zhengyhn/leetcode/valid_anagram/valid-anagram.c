#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
  int slen = strlen(s);
  int tlen = strlen(t);
  if (slen != tlen) {
    return false;
  }

  int first[26] = {0};
  int second[26] = {0};

  for (int i = 0; i < slen; ++i) {
    first[s[i] - 'a'] += 1;
  }
  for (int i = 0; i < tlen; ++i) {
    second[t[i] - 'a'] += 1;
  }

  for (int i = 0; i < 26; ++i) {
    if (first[i] != second[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  if (isAnagram("rat", "cat")) {
    printf("t\n");
  } else {
    printf("f\n");
  }
}
