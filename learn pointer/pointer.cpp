#include <iostream>
#include <string>
using namespace std;

struct Human
{
    Human(string fn, int a, float b, float h)
    {
        fullName = fn;
        age = a;
        bust = b;
        height = h;
        isVirgin = true;
    }

    virtual string puzzleShape() // allow overriding by inheritance classes
    {
        return "traditional";
    }

    string fullName;
    int age;
    float bust;
    float height;
    bool isVirgin;
};

struct GoodGirl : public Human
{
    GoodGirl(string fn, int a, float b, float h) : Human(fn, a, b, h) {}

    string puzzleShape()
    {
        return "doggy";
    }
};

struct BadGirl : public Human
{
    BadGirl(string fn, int a, float b, float h) : Human(fn, a, b, h) {}

    string puzzleShape()
    {
        return "69";
    }
};

struct CrazyGirl : public Human
{
    CrazyGirl(string fn, int a, float b, float h) : Human(fn, a, b, h) {}

    string puzzleShape()
    {
        return "ride a horse";
    }
};

void breakVirgin(Human *woman) // *woman = &women_union[0]
{
    cout << "Breaking virgin is in progress with " << (*woman).fullName << " in type " << woman->puzzleShape() << endl;
    (*woman).isVirgin = false;
}

string printBreakVirginIsSuccessOrNot(bool isVirgin)
{
    return isVirgin ? "virgin" : "loose virgin";
}

int main(int argc, char const *argv[])
{
    Human *women_union[5] =
        {
            new Human("Mia", 22, 80, 1.65), 
            new GoodGirl("Charlene", 18, 85, 1.7),
            new BadGirl("Chloe", 21, 90, 1.75),
            new CrazyGirl("Sophia", 19, 92, 1.6),
            new BadGirl("Phoebe", 16, 85, 1.63),
        };

    Human *mistresses = nullptr;

    /*cout << women_union << " = " << &women_union[0] << endl; // tên mảng cũng là một pointer trỏ đến phần tử đầu tiên của mảng
    cout << "-------------------------------" << endl;

    for (mistresses = women_union; mistresses < women_union + 5; mistresses++) // địa chỉ của mảng có thể dùng để so sánh lớn nhỏ
    {
        cout << (*mistresses).fullName << endl;
    }
    cout << "-------------------------------" << endl;

    cout << "Before breaking virginity, " << women_union[2].fullName << " is " << printBreakVirginIsSuccessOrNot(women_union[2].isVirgin) << endl;
    breakVirgin(&women_union[2]);
    cout << "After virginity was broken, " << women_union[2].fullName << " is " << printBreakVirginIsSuccessOrNot(women_union[2].isVirgin) << endl;
    cout << "-------------------------------" << endl;*/

    for (int i = 0; i < 5; i++)
    {
        mistresses = women_union[i];
        breakVirgin(mistresses);
    }

    return 0;
}