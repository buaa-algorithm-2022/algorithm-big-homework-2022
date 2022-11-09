#ifndef ALGORITHM_BIG_HOMEWORK_2022_DATA_GENERATOR_H
#define ALGORITHM_BIG_HOMEWORK_2022_DATA_GENERATOR_H

#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<random>
#include<iostream>

using namespace std;

// 从input目录下读取文件fileName
vector<int> loadNormData(vector<int> &data, string fileName)
{
    string input = "../input/";
    input.append(fileName);
    ifstream fin;
    fin.open(input, ios::in);
    if (!fin.is_open())
	{
		cout << "无法找到这个文件！" << endl;
	}
    string s = "";
    while (getline(fin, s))
    {
        // 过滤最后一行的空白
        if (s.compare("") != 0) data.push_back(atoi(s.c_str()));
    }
    fin.close();
    return data;
}

// 写出结果到output目录下的文件fileName
void writeNormResult(vector<int> &data, string fileName)
{
    string output = "../output/";
    output.append(fileName);
    ofstream fout;
    // 覆盖为ios::app
    fout.open(output, ios::out);
    if (!fout.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    for (int i = 0; i < data.size(); i++)
    {
        fout << data[i] << endl;
    }
    fout.close();
}

void generate(string type, string output, int lines) {
    ofstream fout;
    // 覆盖为ios::app
    fout.open(output, ios::out);
    if (!fout.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
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
            fout << num << endl;
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
            fout << num << endl;
        }
    }
    fout.close();
}

#endif //ALGORITHM_BIG_HOMEWORK_2022_DATA_GENERATOR_H