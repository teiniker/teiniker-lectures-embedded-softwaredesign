#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Directory.h>
#include <File.h>

using namespace std;

Directory* pi = NULL;

TEST_GROUP(DirectoryTestGroup)
{
    void setup()
    {
        pi = new Directory("/home/pi");
        File* todo = new File("TODO.txt", 1024);
        todo->directory(pi);
        pi->addFile(todo);
        
        File* readme = new File("README.MD", 4096);
        readme->directory(pi);
        pi->addFile(readme);
    }

    void teardown()
    {
        delete pi->file(0); // todo
        delete pi->file(1); // readme
        delete pi;
    }
};


TEST(DirectoryTestGroup, ConstructorTest)
{
    // Verify
    CHECK_EQUAL("/home/pi", pi->name());
    CHECK_EQUAL(2, pi->numberOfFiles());

    CHECK_EQUAL("TODO.txt", pi->file(0)->name());
    CHECK_EQUAL(1024, pi->file(0)->size());
    CHECK_EQUAL("/home/pi", pi->file(0)->directory()->name());

    CHECK_EQUAL("README.MD", pi->file(1)->name());
    CHECK_EQUAL(4096, pi->file(1)->size());
    CHECK_EQUAL("/home/pi", pi->file(1)->directory()->name());
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
