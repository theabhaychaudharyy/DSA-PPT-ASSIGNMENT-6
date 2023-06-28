#include <vector>
#include <iostream>

std::vector<int> reconstructPermutation(const std::string& s) {
    int n = s.length();
    std::vector<int> perm(n + 1);

    int inc = 0;
    int dec = n;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'I') {
            perm[i] = inc;
            inc++;
        } else {
            perm[i] = dec;
            dec--;
        }
    }

    perm[n] = inc; // Last element can be either inc or dec

    return perm;
}

int main() {
    std::string s = "IDID";
    std::vector<int> perm = reconstructPermutation(s);

    // Print the reconstructed permutation
    for (int i = 0; i < perm.size(); ++i) {
        std::cout << perm[i] << " ";
    }

    return 0;
}
