#include "stdafx.h"

#include <iostream>
#include "Classes/Files.h"
#include "Classes/Encrypt.h"

/**
 * ���ܷ�����
 * ���������������Ҫ���ܵ��ļ��и�Ŀ¼�����в�������Կ������չ����
 */

int main()
{
	std::cout << "===============================================" << std::endl;
	std::cout << ">> �뽫�������������Ҫ���ܵ��ļ��и�Ŀ¼��  <<" << std::endl;
	std::cout << ">> ������Կ����չ���󣬽���PNGͼƬ���м��ܣ� <<" << std::endl;
	std::cout << ">> ����ļ���ԴĿ¼�£���չ��Ϊ�������չ����<<" << std::endl;
	std::cout << "===============================================" << std::endl;

	// ������Կ
	aes_key key = { 0 };
	std::cout << std::endl << ">> ������16λ��Կ��AES����" << std::endl;
	std::cin.get((char *)&key[0], key.size());

	// ������չ��
	std::string exten = "";
	std::cout << std::endl << ">> ����������չ����.fox����" << std::endl;
	std::cin >> exten;
	
	// Ѱ������pngͼƬ
	std::vector<std::string> pngfiles;
	auto all_files = path::walk(path::curdir());
	for (auto filename : all_files)
	{
		if (path::splitext(filename)[1] == ".png")
		{
			pngfiles.push_back(filename);
		}
	}

	// ȡ���·��
	auto absolute_path = path::curdir() + "\\";
	for (auto &filename : pngfiles)
	{
		filename = filename.substr(absolute_path.size(), filename.size());
	}

	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << ">> ���ܿ�ʼ..." << std::endl << std::endl;

	// ͼƬ���ܲ���
	EncryptPNG(pngfiles, key, exten);

	std::cout << std::endl;
	std::cout << ">> ���������" << std::endl;
	std::cout << "===============================================" << std::endl << std::endl;
	
	system("pause");

	return 0;
}