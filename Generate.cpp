#include<string>

#include "DataGenerator.cpp"

using namespace std;


int main(int argc, char const *argv[])
{
   
    // 0表示int, 1表示bigint
    string type = argv[1];
    // 输出文件名
    string output = "./input/";
    output.append(argv[2]);
    int lines = atoi(argv[3]);

    generate(type, output, lines);

    
    return 0;
}