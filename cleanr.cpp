#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
int main()
{
    std::filesystem::path temp{ std::filesystem::temp_directory_path() };
    for (const auto & entry : std::filesystem::directory_iterator(temp)) {
        try {
            std::filesystem::remove_all(entry.path());
            cout << entry.path() << " deleted" << endl;
        }
        catch (std::filesystem::filesystem_error& e) {
            cerr << e.what() << endl;
        }
    } 
    std::filesystem::path prefetch{ "C:\\Windows\\prefetch" };
    for (const auto& entry : std::filesystem::directory_iterator(prefetch)) {
        try {
            std::filesystem::remove_all(entry.path());
            cout << entry.path() << " deleted" << endl;
        }
        catch (std::filesystem::filesystem_error& e) {
            cerr << e.what() << endl;
        }
    }
    std::filesystem::path usrtemp{ "C:\\Windows\\Temp" };
    for (const auto& entry : std::filesystem::directory_iterator(usrtemp)) {
        try {
            std::filesystem::remove_all(entry.path());
            cout << entry.path() << " deleted" << endl;
        }
        catch (std::filesystem::filesystem_error& e) {
            cerr << e.what() << endl;
        }
    }
}
