#include <iostream>
#include <filesystem>
#include <vector>
using namespace std;

int main() {

    char* path = nullptr;
    size_t sz = 0;
    int size = 0;
    std::vector < string > arr;
    if (_dupenv_s(&path, &sz, "appdata") == 0 && path != nullptr)
    {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {

            if (entry.path().filename().string() == "cache" || entry.path().filename().string() == "Cache") {
                size += 1;
                cout << entry.path() << " " << size << endl;
                arr.push_back(entry.path().string());
            }

        }
        free(path);
    }
    cout << "\nCaches: " << size << endl;
    string* art = &arr[0];

    int num;
    string ee;
    printf("\nWould you like to delete ONE or ALL caches (ONE or ALL) PAY ATTENTION >> ");
    cin >> ee;
    std::vector <string> t;
    if (ee == "ALL") {
        for (int i = 0; i < arr.size(); i++) {
            for (const auto& entry : std::filesystem::directory_iterator(art[i])) {
                try {
                    std::filesystem::remove_all(entry.path());
                    cout << entry.path().filename().string() << " deleted" << endl;
                }
                catch (std::filesystem::filesystem_error& e) {
                    cerr << e.what() << endl;
                }
            }
            
        }
        cout << "Finished\n";
        cout << "Type anything to exit >> ";
    }
    else if(ee == "ONE") {
        cout << "\nEnter the number of the cache you would like to delete >> ";
        cin >> num;
        while (!num) {
            exit(1);
        }


        for (const auto& entry : std::filesystem::directory_iterator(art[num - 1])) {

            try {
                std::filesystem::remove_all(entry.path());
                cout << entry.path().filename().string() << " deleted" << endl;
            }
            catch (std::filesystem::filesystem_error& e) {
                cerr << e.what() << endl;
            }
        }
        string yaorno = "";
        cout << "\nDone";
        cout << "\n\nType anything to exit\n";
        cin >> yaorno;

    }
    else {
        exit(1);
    }

}
