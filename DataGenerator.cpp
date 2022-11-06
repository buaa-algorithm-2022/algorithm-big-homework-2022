#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<random>

using namespace std;

int main(int argc, char const *argv[])
{
    ofstream ofs;
    // 输出文件（包括路径）
    string output = argv[1];
    // 0表示int, 1表示bigint
    string type = argv[2];
    int lines = atoi(argv[3]);

    // 覆盖为ios::app
    ofs.open(output, ios::out);
    srand((unsigned)time(NULL));
    if (type == "0")
    {
        for(int i = 0; i < lines; i++)
        {
            // 生成符号位，0表示正数，1表示负数
            int symbol = rand() % 2;
            if(symbol == 1) {
                symbol = -1;
            } else {
                symbol = 1;
            }
            int num = symbol * rand();
            ofs << num << endl;
        }
    } else if(type == "1") {
        for(int i = 0; i < lines; i++)
        {
            string num = "";
            // 生成符号位，0表示正数，1表示负数
            int symbol = rand() % 2;
            if(symbol == 1) num.append("-");
            // 生成数字部分，每次4位，共25次生成所有100位
            for(int times = 0; times < 25; times ++)
            {
                string part = to_string(rand() % 10000);
                // 解决part为0的情况
                if(part == "0") part = "";
                num.append(part);
            }
            // 解决数字部分为空的情况
            if(num.size() == symbol) num = "0";
            ofs << num << endl;
        }
    }
    ofs.close();
    return 0;
}
