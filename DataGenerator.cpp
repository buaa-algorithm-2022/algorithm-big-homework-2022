#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ofstream ofs;
    string output = argv[0];
    // 0表示int, 1表示bigint
    string type = argv[1];
    string nums = argv[2];

    ofs.open(output, ios::out);
    if (type == "0")
    {
        
    } else if(type == "1") {
        srand((unsigned)time(NULL));
        int bigintLength = rand();
    }
    
    
    return 0;
}
