#ifndef ALGORITHM_BIG_HOMEWORK_2022_DATA_GENERATOR_H
#define ALGORITHM_BIG_HOMEWORK_2022_DATA_GENERATOR_H

#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<random>
#include<iostream>
#include "BigInteger.h"

using namespace std;

// 从input目录下读取文件fileName
vector<int> loadData(vector<int> &data, string filePath)
{
    ifstream fin;
    fin.open(filePath, ios::in);
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

vector<BigInteger> loadData(vector<BigInteger> &data, string filePath)
{
    ifstream fin;
    fin.open(filePath, ios::in);
    if (!fin.is_open())
	{
		cout << "无法找到这个文件！" << endl;
	}
    string s = "";
    while (getline(fin, s))
    {
        // 过滤最后一行的空白
        if (s.compare("") != 0) data.push_back(BigInteger(s));
    }
    fin.close();
    return data;
}


// 写出结果到output目录下的文件fileName
void writeResult(vector<int> &data, string filePath)
{
    ofstream fout;
    // 覆盖为ios::app
    fout.open(filePath, ios::out);
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

void writeResult(vector<BigInteger> &data, string filePath)
{
    ofstream fout;
    // 覆盖为ios::app
    fout.open(filePath, ios::out);
    if (!fout.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    for (int i = 0; i < data.size(); i++)
    {
        fout << data[i].getContent() << endl;
    }
    fout.close();
}


void generateFile(string type, string filePath, int lines) {
    ofstream fout;
    // 覆盖为ios::app
    fout.open(filePath, ios::out);
    if (!fout.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    srand((unsigned)time(NULL));
    if (type == "int")
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
    } else if(type == "bigint") {
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