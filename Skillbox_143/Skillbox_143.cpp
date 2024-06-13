#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <filesystem>
using namespace std;
namespace fs = filesystem;



template <typename T>
void printVector(const vector<T>& vector)
{
    for (const auto& i: vector)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
        //Задание 1:
    cout << "--- Задание 1 ---\n";
    for (auto i : {1, 2, 3, 4, 5})
    {
        cout << i << " ";
    }
    cout << "\n";


    //Задание 2:
    cout << "--- Задание 2 ---\n";
    vector<int> numberVector {1, 2, 3, 4, 2, 4, 5, 7, 6, 8, 6};
    cout << "Входной вектор:\n";
    printVector(numberVector);

    //Lambda:
    auto getUnique = [](vector<int>& v)->unique_ptr<vector<int>>
    {
        auto valuesSet = new unordered_set<int>();
        auto result = make_unique<vector<int>>();
        for (auto &i : v) {
            if (valuesSet->insert(i).second)
                result->push_back(i);
            else
                cout << "Номер " << i << " повторяется.\n";
        }
        return result;
    };

    auto uniqueVector = getUnique(numberVector);
    cout << "Вектор уникальных элементов:\n";
    printVector(*uniqueVector);

    //Задание 3:
    cout << "--- Задание 3 ---\n";
    auto getFilesWithExtension = [](const filesystem::path& path, const string& extension)->unique_ptr<vector<filesystem::path>>
    {
        cout << "Получение имен файлов с расширением " << extension << " in path " << path << "...\n";
        auto result = make_unique<vector<filesystem::path>>();
        auto* paths = new filesystem::recursive_directory_iterator(path);
        for(const auto& p: *paths)
        {
            if (p.is_regular_file())
            {
                if (p.path().extension().compare(extension) == 0)
                {
                    result->push_back(p.path().filename());
                }
            }
        }
        return result;
    };
    filesystem::path path = "..//TestDir";
    string extension = ".jpg";
    try
    {
        auto fileNames = getFilesWithExtension(path, extension);
        cout << "Имена файлов в "<< path  << " с расширением "<< extension << ":\n";
        printVector(*fileNames);
    }
    catch (const exception& e)
    {
        cerr << e.what();
    }

    return 0;
}