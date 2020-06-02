#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <File.h>
#include <Directory.h>
#include <memory>

using namespace std;

TEST_GROUP(CompositeTestGroup)
{
};

TEST(CompositeTestGroup, FileTest)
{
    shared_ptr<Node> file(new File("README.txt", 1024));

    
    // Verify
    CHECK_EQUAL("README.txt", file->name());
    CHECK_EQUAL(1024, file->numberOfBytes());
    CHECK_EQUAL(1, file->numberOfFiles());
}


TEST(CompositeTestGroup, DirectoryTest)
{
    shared_ptr<Node> dir(new Directory("home"));
    
    shared_ptr<Node> readme(new File("README.txt", 1024));
    dir->addNode(readme);
    
    shared_ptr<Node> bashrc(new File(".bashrc", 512));
    dir->addNode(bashrc);
    
    
    // Verify
    CHECK_EQUAL("home", dir->name());
    CHECK_EQUAL(1024 + 512, dir->numberOfBytes());
    CHECK_EQUAL(1+1, dir->numberOfFiles());
}


TEST(CompositeTestGroup, FileSystemTest)
{
    shared_ptr<Node> root(new Directory("/"));
    shared_ptr<Node> home(new Directory("home"));
    root->addNode(home);    
    
    shared_ptr<Node> teini(new Directory("teini"));
    root->addNode(teini);
    shared_ptr<Node> bashrc(new File(".bashrc", 1024));
    teini->addNode(bashrc);
    shared_ptr<Node> todo(new File("TODO.txt", 2048));
    teini->addNode(todo);
    
    shared_ptr<Node> server(new Directory("www"));
    root->addNode(server);
    shared_ptr<Node> bashrc2(new File(".bashrc", 512));
    server->addNode(bashrc2);
    
    // Verify
    CHECK_EQUAL(1024 + 2048 + 512, root->numberOfBytes());
    CHECK_EQUAL(1+1+1, root->numberOfFiles());
}



int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
