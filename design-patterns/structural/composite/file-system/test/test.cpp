#include <gtest/gtest.h>
#include <memory>
#include <node.h>
#include <file.h>
#include <directory.h>
 
using namespace std;

TEST(CompositeTestGroup, FileTest)
{
    auto file = make_shared<File>("README.txt", 1024);

    // Verify
    EXPECT_EQ("README.txt", file->name());
    EXPECT_EQ(1024, file->numberOfBytes());
    EXPECT_EQ(1, file->numberOfFiles());
}

TEST(CompositeTestGroup, DirectoryTest)
{
    auto dir = make_shared<Directory>("home");
    
    auto readme = make_shared<File>("README.txt", 1024);
    dir->addNode(readme);
    
    auto bashrc = make_shared<File>(".bashrc", 512);
    dir->addNode(bashrc);
    
    // Verify
    EXPECT_EQ("home", dir->name());
    EXPECT_EQ(1024 + 512, dir->numberOfBytes());
    EXPECT_EQ(2, dir->numberOfFiles());
}

TEST(CompositeTestGroup, FileSystemTest)
{
    auto root = make_shared<Directory>("/");
    auto home = make_shared<Directory>("home");
    root->addNode(home);    
    
    auto teini = make_shared<Directory>("teini");
    root->addNode(teini);
    auto bashrc = make_shared<File>(".bashrc", 1024);
    teini->addNode(bashrc);
    auto todo = make_shared<File>("TODO.txt", 2048);
    teini->addNode(todo);
    
    auto server = make_shared<Directory>("www");
    root->addNode(server);
    auto bashrc2 = make_shared<File>(".bashrc", 512);
    server->addNode(bashrc2);
    
    // Verify
    EXPECT_EQ(1024 + 2048 + 512, root->numberOfBytes());
    EXPECT_EQ(3, root->numberOfFiles());
}
