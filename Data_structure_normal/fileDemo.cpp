
//��ʵ�õ�
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int a,b; 
	freopen("D:\\in.txt","r",stdin); //�����ض����������ݽ���D�̸�Ŀ¼�µ�in.txt�ļ��ж�ȡ 
	freopen("D:\\out.txt","w",stdout); //����ض���������ݽ�������D�̸�Ŀ¼�µ�out.txt�ļ��� 
	while(cin>>a>>b) 
	cout<<a+b<<endl; // ע��ʹ��endl 
	fclose(stdin);//�ر��ض�������
	fclose(stdout);//�ر��ض������ 
	return 0; 
	
	//���ж���
	//��һ 
	string expression;
	getline(cin, expression, '=');
	//����
		string line;
		getline(cin,line);
		istringstream iss(line);
	    string name;
	    if (line == "\n" || line == " ") 
		{
            cin.ignore();
            continue;
//	        queues[i].push(" ");

	    }
        else
        {
            while (iss >> name && name != "LEAVES" && name != "ENTERS") 
            {
	        queues[i].push(name);
	        }
        } 
	
	
 } 


















﻿//与输入输出流操作相关的类:
//istream是用于输入的流类，cin就是该类的对象。
//ostream是用于输出的流类，cout就是该类的对象。
//ifstream是用于从文件读取数据的类。
//ofstream是用于向文件写入数据的类。
//iostream是既能用于输入，又能用于输出的类。
//fstream 是既能从文件读取数据，又能向文件写入数据的类。

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//代码实现了读取一个拥有多行整数，每行各个数字由空格分隔的txt文件
//文件形如：
// 1 2 3 4 5 
// 2 3 4 5 
// 6 6 6
//并将数字输出在命令台，同时存入一个名为out.txt的文件
int main() {
    ifstream inputFile("in.txt");//创建文件输入流对象并打开输入文件
    ofstream outputFile("out.txt", ofstream::out | ofstream::trunc);//创建文件输出流对象，如果out.txt文件存在就覆盖其内容

    //异常处理
    if (!inputFile.is_open()) {
        cerr << "Unable to open input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Unable to open/create output file." << endl;
        return 1;
    }



    string line;
    while (getline(inputFile, line)) {//读取输入文件每一行内容
        stringstream ss(line);//利用文件每行内容构建一个字符串流对象
        int num;
        vector<int> numbers;

        while (ss >> num) {//读取其中的每个整数存进一个vector
            numbers.push_back(num);
        }

        for (int n : numbers) {//命令台输出数字
            cout << n << " ";
        }
        cout << endl;


        for (int n : numbers) {//数字写入out.txt
            outputFile << n << " ";
        }
        outputFile << endl;
    }

    //关闭输入输出流
    inputFile.close();
    outputFile.close();

    return 0;
}

