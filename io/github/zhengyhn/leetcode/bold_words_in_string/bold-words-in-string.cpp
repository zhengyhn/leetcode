#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string boldWords(vector<string>& words, string S) {
      int start = -1;
      int end = -1;
      string ret;

      for (int i = 0; i < S.size(); ++i) {
        bool isFound = false;
        for (int j = 0; j < words.size(); ++j) {
          int len = (i + words[j].size());
          if ((S.substr(i, words[j].size()) == words[j]) && (len > end)) {
            if (start == -1) {
              start = i;
              end = i + words[j].size();
            } else {
              end = i + words[j].size();
            }
            isFound = true;
          }
        }
        if (!isFound || i == S.size() -1) {
          if (start == -1) {
            ret.push_back(S[i]);
          } else if (i >= end) {
            // std::cout << "i >= end " << i << " " << end << std::endl; 
            ret.append("<b>");
            ret.append(S, start, end - start);
            ret.append("</b>");
            ret.push_back(S[i]);
            start = -1;
            end = -1;
          } else if (i == S.size() -1) {
            ret.append("<b>");
            ret.append(S, start, end - start);
            ret.append("</b>");
          }
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<string> words = {"di","r","buhozb","lofjmyjj","qagllw","zzuid","loyugfh","w","hcfg","ttd","vjqigvx","u","mhbivve","x","nzbvyfzx","zs","j","zgtud","zm","huevyex","szwigrlwzm","vlrjmobu","b","h","gcmdgyv","anyfelm","vtcejv","myjjzn","jznnj","awcxmjn","lw","sju","szszwigrl","eze","ffikvecua","bklrhsju","gyazwel","pdhnsxsod","zn","rhsjus","zk","gctgu","vzndt","mfd","jlws","j","zxgaudyo","apa","znvixpdh","tgubzczgt"};
  string str = "wwcyuaqzgtudmpjkluqoseslygywzkixjqghsocvjqigvxwqloyugfhcjscjghqmiglgyazwelshzapaezqgmcmrmfrfzttdgquizyducbvxzzuiddcnwuaapdunzlbagnifndbjyalqqgbramhbivvervxrtcszszwigrlwzmuteyswzagudtpvlrjmobuhozbghkhvoxawcxmjnazlqlkqqqnoclufgkovbokvkoezeknwhcfgcenvaablpvtcejvzndtzncrelhedwlwiqgdbdgctgubzczgtovufncicjlwsmfdcrqeaghuevyexqdhffikvecuazrelofjmyjjznnjdkimbklrhsjusbstqhvlejtjcczqnzbvyfzxgaudyosckysmminoanjmbafhtnbrrzqagllwxlxmjanyfelmwruftlzuuhbsjexoobjkmymlitiwjtdxscotzvznvixpdhnsxsodieatipiaodgcmdgyv";

  std::cout << sln.boldWords(words, str) << std::endl;

  return 0;
}
