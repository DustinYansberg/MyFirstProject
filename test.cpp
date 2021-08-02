#include <algorithm>
#include <vector>
#include <string>
    std::string duplicate_encoder(const std::string & word) {
        std::vector<int> characterLocations;
        std::string out = word;
        std::transform(out.begin(), out.end(), out.begin(),
            [](unsigned char c) { return std::tolower(c); });
        std::vector<bool> swapped(out.size(), false);
        for (unsigned long j = 0; j < out.size(); j++) {
            char tmp = out.at(j);
            if (swapped.at(j) == false) {
                for (unsigned long i = j; i < out.size(); i++) {
                    if (out[i] == tmp) {
                        characterLocations.push_back(i);
                        swapped.at(i) = true;
                    }
                }
                if (characterLocations.size() > 1) {
                    for (unsigned long i = 0; i < characterLocations.size(); i++) {
                        out.at(characterLocations.at(i)) = ')';
                    }
                    characterLocations.clear();
                }
                else {
                    out.at(characterLocations.at(0)) = '(';
                    characterLocations.clear();
                }
            }
        }
        return out;
    }

    int main() {

        return 0;
    }