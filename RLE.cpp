
#include <iostream>
#include <cstdio>
#include <string>

//Run-length encoding

class RLE {
public:

    //RLE();

    std::string encode(std::string str) {
        std::string eC = "";


        int n = str.length();

        int count;

        for (int i = 0; i < n; i++) {

            count = 1;
            while (i < n - 1 && str[i] == str[i + 1]) {
                count++;
                i++;
            }

            if (count > 1) {
                eC += std::to_string(count);
                //if (std::isdigit(str[i])eC += "/";

                eC += str[i];

            }
            else  eC += str[i];
        }



        return eC;
    }
    std::string decode(std::string str) {
        std::string dC = "";
        std::string buf = "";


        int n = str.length();
        for (int i = 0; i < n; i++) {

            if (!std::isdigit(str[i])) dC += str[i];
            else {
                buf = "";
                while (std::isdigit(str[i])) {
                    buf += str[i];
                    i++;
                }

                for(int j =0; j< std::stoi(buf);j++){
                dC += str[i];
                }

            }



        }

        return dC;
    }


};
int main() {
    std::string str = "Heeeeeellooo Worlddddddddd AAAAAAAAAAAA";
    RLE myRLE;
    std::string eC = myRLE.encode(str);
    std::cout << str << std::endl;
    std::cout << eC << std::endl;
    std::cout << myRLE.decode(eC) << std::endl;


}
