#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <iostream>
#include <locale.h>
#include <cstdlib>

std::vector<int> read(std::ifstream& in)
{
    std::string tmpDATA;
    getline(in, tmpDATA);
    std::vector<int> data;
    if (in.is_open())
    {
        while (getline(in, tmpDATA))
        {
            int num1 = std::stoi(tmpDATA);
            int num2 = std::stoi(std::string(tmpDATA.begin() + tmpDATA.find(' ') + 1, tmpDATA.end()));
            data.push_back(num1);
            data.push_back(num2);
            //std::cout << num1 << "; ";
            //std::cout << num2 << '\n';
        }
    }
    return data;
}
struct numbers
{
    int number;
    int delta;
    bool parity;
    int second_num;
};
int main()
{
    std::ifstream numbers_1IN("numbers_2.txt"); // окрываем файл для чтения
    auto numbers_1 = read(numbers_1IN);
    numbers_1IN.close();

    std::vector<numbers> delta_1;
    for (int i = 0; i < numbers_1.size(); i+=2)
    {
        numbers tmp;
        tmp.number = numbers_1[i] > numbers_1[i + 1] ? numbers_1[i + 1] : numbers_1[i];
        tmp.second_num = numbers_1[i] < numbers_1[i + 1] ? numbers_1[i + 1] : numbers_1[i];
        tmp.delta = tmp.second_num - tmp.number;
        tmp.parity = (tmp.delta % 2) == 1;
        //std::cout << tmp.number << "; ";
        //std::cout << tmp.second_num << "; ";
        //std::cout << tmp.delta << "; ";
        //std::cout << tmp.parity << "; " << '\n';

        delta_1.push_back(tmp);
    }
    int summ = 0;
    int parity = 0;
    int min_delta = 10000;
    for (auto inter : delta_1)
    {
        summ += inter.number;
        if (inter.number % 2 == 0)
            parity++;
        else
            parity--;
        if ((min_delta > inter.delta) && (inter.parity))
            min_delta = inter.delta;
    }
    if ((summ % 2 == 0) == (parity > 0))
    {
        summ += min_delta;
    }
    std::cout << summ;
}