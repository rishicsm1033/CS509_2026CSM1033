#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

// Utility Functions

bool compileProgram(const string& sourceFiles, const string& driverFile,
                    const string& executable)
{
    string command =
        "g++ " + sourceFiles + " " + driverFile +
        " -o " + executable;

    cout << "\nCompiling...\n";
    cout << command << "\n\n";

    int result = system(command.c_str());

    if (result != 0)
    {
        cout << "Compilation FAILED!\n";
        return false;
    }

    cout << "Compilation successful.\n";
    return true;
}


bool runTest(const string& executable, const string& testFile)
{
    cout << "\n--------------------------------------------\n";
    cout << "Test File : " << testFile << "\n";
    cout << "--------------------------------------------\n";

    string command =
        executable + " < \"" + testFile + "\"";

    int result = system(command.c_str());

    if (result != 0)
    {
        cout << "\nError while running test file.\n";
        return false;
    }

    return true;
}


vector<string> getTestFiles(const string& testDirectory)
{
    vector<string> testFiles;

    if (!fs::exists(testDirectory))
    {
        cout << "\nERROR: Test directory not found:\n";
        cout << testDirectory << "\n";
        return testFiles;
    }

    for (const auto& entry : fs::directory_iterator(testDirectory))
    {
        if (entry.is_regular_file())
        {
            if (entry.path().extension() == ".txt")
            {
                testFiles.push_back(entry.path().string());
            }
        }
    }

    sort(testFiles.begin(), testFiles.end());

    return testFiles;
}


void runOneTest(const string& executable, const string& testDirectory)
{
    vector<string> testFiles = getTestFiles(testDirectory);

    if (testFiles.empty())
    {
        cout << "\nNo .txt test files found!\n";
        return;
    }

    cout << "\nAvailable Test Files:\n\n";

    for (int i = 0; i < (int)testFiles.size(); i++)
    {
        cout << i + 1 << ". "
             << fs::path(testFiles[i]).filename().string()
             << "\n";
    }

    int choice;

    cout << "\nEnter test number: ";
    cin >> choice;

    if (choice < 1 || choice > (int)testFiles.size())
    {
        cout << "\nInvalid test number!\n";
        return;
    }

    runTest(executable, testFiles[choice - 1]);
}


void runAllTests(const string& executable, const string& testDirectory)
{
    vector<string> testFiles = getTestFiles(testDirectory);

    if (testFiles.empty())
    {
        cout << "\nNo .txt test files found!\n";
        return;
    }

    cout << "\n============================================\n";
    cout << "           RUNNING ALL TEST CASES\n";
    cout << "============================================\n";

    cout << "\nNumber of test cases: "
         << testFiles.size() << "\n";

    for (const string& testFile : testFiles)
    {
        runTest(executable, testFile);
    }

    cout << "\n============================================\n";
    cout << "          ALL TESTS COMPLETED\n";
    cout << "============================================\n";
}
// Assignment 01
void assignment01()
{
    int choice;

    while (true)
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "             ASSIGNMENT 01\n";
        cout << "============================================\n";
        cout << "1. Matrix Multiplication\n";
        cout << "2. Tiling\n";
        cout << "3. CSR Graph\n";
        cout << "4. Back\n";
        cout << "============================================\n";
        cout << "Enter choice: ";

        cin >> choice;
        // Matrix Multiplication
        if (choice == 1)
        {
            string executable = "assignment_01_matmul.exe";

            string source =
                "assignment_01/src/matmul.cpp";

            string driver =
                "assignment_01/driver/matmul.cpp";

            string testDirectory =
                "assignment_01/test";

            if (!compileProgram(source, driver, executable))
                continue;

            int testChoice;

            cout << "\n============================================\n";
            cout << "        MATRIX MULTIPLICATION TESTS\n";
            cout << "============================================\n";
            cout << "1. Run one test\n";
            cout << "2. Run all tests\n";
            cout << "3. Back\n";
            cout << "Enter choice: ";

            cin >> testChoice;

            if (testChoice == 1)
            {
                runOneTest(executable, testDirectory);
            }
            else if (testChoice == 2)
            {
                runAllTests(executable, testDirectory);
            }
        }
        // Tiling
        else if (choice == 2)
        {
            string executable = "assignment_01_tiling.exe";

            string source =
                "assignment_01/src/tiling.cpp";

            string driver =
                "assignment_01/driver/tiling.cpp";

            string testDirectory =
                "assignment_01/test";

            if (!compileProgram(source, driver, executable))
                continue;

            int testChoice;

            cout << "\n============================================\n";
            cout << "             TILING TESTS\n";
            cout << "============================================\n";
            cout << "1. Run one test\n";
            cout << "2. Run all tests\n";
            cout << "3. Back\n";
            cout << "Enter choice: ";

            cin >> testChoice;

            if (testChoice == 1)
            {
                runOneTest(executable, testDirectory);
            }
            else if (testChoice == 2)
            {
                runAllTests(executable, testDirectory);
            }
        }
        // CSR Graph
        else if (choice == 3)
        {
            string executable = "assignment_01_csr.exe";

            string source =
                "assignment_01/src/csr_graph.cpp";

            string driver =
                "assignment_01/driver/csr_graph.cpp";

            string testDirectory =
                "assignment_01/test";

            if (!compileProgram(source, driver, executable))
                continue;

            int testChoice;

            cout << "\n============================================\n";
            cout << "             CSR GRAPH TESTS\n";
            cout << "============================================\n";
            cout << "1. Run one test\n";
            cout << "2. Run all tests\n";
            cout << "3. Back\n";
            cout << "Enter choice: ";

            cin >> testChoice;

            if (testChoice == 1)
            {
                runOneTest(executable, testDirectory);
            }
            else if (testChoice == 2)
            {
                runAllTests(executable, testDirectory);
            }
        }

        else if (choice == 4)
        {
            return;
        }

        else
        {
            cout << "\nInvalid choice!\n";
        }
    }
}
// Assignment 02
void assignment02()
{
    int choice;

    while (true)
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "             ASSIGNMENT 02\n";
        cout << "============================================\n";
        cout << "1. Bellman-Ford\n";
        cout << "2. Floyd-Warshall\n";
        cout << "3. Back\n";
        cout << "============================================\n";
        cout << "Enter choice: ";

        cin >> choice;
        // Bellman-Ford
        if (choice == 1)
        {
            string executable = "assignment_02_bellmanford.exe";

            string source =
                "assignment_02/src/bellmanford.cpp";

            string driver =
                "assignment_02/driver/bellmanford.cpp";

            string testDirectory =
                "assignment_02/test";

            if (!compileProgram(source, driver, executable))
                continue;

            int testChoice;

            cout << "\n============================================\n";
            cout << "          BELLMAN-FORD TESTS\n";
            cout << "============================================\n";
            cout << "1. Run one test\n";
            cout << "2. Run all tests\n";
            cout << "3. Back\n";
            cout << "Enter choice: ";

            cin >> testChoice;

            if (testChoice == 1)
            {
                runOneTest(executable, testDirectory);
            }
            else if (testChoice == 2)
            {
                runAllTests(executable, testDirectory);
            }
        }
        // Floyd-Warshall
        else if (choice == 2)
        {
            string executable = "assignment_02_floyd.exe";

            string source =
                "assignment_02/src/floyd.cpp";

            string driver =
                "assignment_02/driver/floyd.cpp";

            string testDirectory =
                "assignment_02/test";

            if (!compileProgram(source, driver, executable))
                continue;

            int testChoice;

            cout << "\n============================================\n";
            cout << "          FLOYD-WARSHALL TESTS\n";
            cout << "============================================\n";
            cout << "1. Run one test\n";
            cout << "2. Run all tests\n";
            cout << "3. Back\n";
            cout << "Enter choice: ";

            cin >> testChoice;

            if (testChoice == 1)
            {
                runOneTest(executable, testDirectory);
            }
            else if (testChoice == 2)
            {
                runAllTests(executable, testDirectory);
            }
        }

        else if (choice == 3)
        {
            return;
        }

        else
        {
            cout << "\nInvalid choice!\n";
        }
    }
}
// Assignment 03
void assignment03()
{
    int choice;

    while (true)
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "             ASSIGNMENT 03\n";
        cout << "============================================\n";
        cout << "1. Prim's Algorithm\n";
        cout << "2. Kruskal's Algorithm\n";
        cout << "3. Back\n";
        cout << "============================================\n";
        cout << "Enter choice: ";

        cin >> choice;
        // Prim's Algorithm
        if (choice == 1)
        {
            string executable = "assignment_03_prims.exe";

            string source =
                "assignment_03/src/csr_graph.cpp "
                "assignment_03/src/prims.cpp";

            string driver =
                "assignment_03/driver/prims.cpp";

            string testDirectory =
                "assignment_03/test";

            if (!compileProgram(source, driver, executable))
                continue;

            int testChoice;

            cout << "\n============================================\n";
            cout << "           PRIM'S ALGORITHM TESTS\n";
            cout << "============================================\n";
            cout << "1. Run one test\n";
            cout << "2. Run all tests\n";
            cout << "3. Back\n";
            cout << "Enter choice: ";

            cin >> testChoice;

            if (testChoice == 1)
            {
                runOneTest(executable, testDirectory);
            }
            else if (testChoice == 2)
            {
                runAllTests(executable, testDirectory);
            }
        }
        // Kruskal's Algorithm
        else if (choice == 2)
        {
            string executable = "assignment_03_kruskal.exe";

            string source =
                "assignment_03/src/csr_graph.cpp "
                "assignment_03/src/kruskal.cpp";

            string driver =
                "assignment_03/driver/kruskal.cpp";

            string testDirectory =
                "assignment_03/test";

            if (!compileProgram(source, driver, executable))
                continue;

            int testChoice;

            cout << "\n============================================\n";
            cout << "          KRUSKAL'S ALGORITHM TESTS\n";
            cout << "============================================\n";
            cout << "1. Run one test\n";
            cout << "2. Run all tests\n";
            cout << "3. Back\n";
            cout << "Enter choice: ";

            cin >> testChoice;

            if (testChoice == 1)
            {
                runOneTest(executable, testDirectory);
            }
            else if (testChoice == 2)
            {
                runAllTests(executable, testDirectory);
            }
        }

        else if (choice == 3)
        {
            return;
        }

        else
        {
            cout << "\nInvalid choice!\n";
        }
    }
}
//main  
int main()
{
    int choice;

    while (true)
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "          CS509 COMMON WRAPPER\n";
        cout << "============================================\n";
        cout << "1. Assignment 01\n";
        cout << "2. Assignment 02\n";
        cout << "3. Assignment 03\n";
        cout << "4. Exit\n";
        cout << "============================================\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1)
        {
            assignment01();
        }
        else if (choice == 2)
        {
            assignment02();
        }
        else if (choice == 3)
        {
            assignment03();
        }
        else if (choice == 4)
        {
            cout << "\nExiting...\n";
            break;
        }
        else
        {
            cout << "\nInvalid choice!\n";
        }
    }

    return 0;
}