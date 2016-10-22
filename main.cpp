#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

class solution {
public:
  int characterReplacement(const std::string & s, int k) {
    std::unordered_map<char,std::vector<std::pair<size_t,size_t>>> dict;
    for (auto ch : s) {
      if (dict.find(ch) == dict.end()) {
	// std::cout << ch << std::endl;
	size_t begin, end;
	begin = s.find_first_of(ch);
	while (begin != std::string::npos) {
	  // std::cout << "begin = " << begin << std::endl;
	  end = s.find_first_not_of(ch, begin);
	  // std::cout << "end = " << end << std::endl;
	  if (dict.find(ch) == dict.end())
	    dict[ch] = std::vector<std::pair<size_t,size_t>>();
	  if (end == std::string::npos)
	    dict[ch].push_back(std::make_pair(begin, s.size()));
	  else
	    dict[ch].push_back(std::make_pair(begin, end));
	  begin = s.find_first_of(ch, end);
	}
	// if (begin != std::string::npos && end == std::string::npos) {
	// 	if (dict.find(ch) != dict.end())
	// 	  dict[ch] = std::vector<std::pair<size_t,size_t>>();
	// 	dict[ch].push_back(std::make_pair(begin, s.size()));
	// }
      }
    }

    for (auto it = dict.begin(); it != dict.end(); ++it) {
      std::cout << it->first << ":\n";
      for (auto pr : it->second)
	std::cout << "[" << pr.first << "," << pr.second << ") ";
      std::cout << std::endl;
    }

    return 0;
  }
};

int main() {
  std::string str{"ABAB"};
  int k = 2;

  solution soln;
  int len = soln.characterReplacement(str, k);
  std::cout << "The length of the longest string is:\n"
	    << len << std::endl;
}
