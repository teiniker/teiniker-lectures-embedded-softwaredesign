#include <gtest/gtest.h>

#include "directory.h"
#include "file.h"

using namespace std;

class DirectoryTest : public ::testing::Test 
{
protected:
    Directory* student;

    void SetUp() override 
    {
        student = new Directory("/home/student");
        File* todo = new File("TODO.txt", 1024);
        todo->directory(student);
        student->addFile(todo);

        File* readme = new File("README.MD", 4096);
        readme->directory(student);
        student->addFile(readme);
    }

    void TearDown() override 
    {
        delete student->file(0); // todo
        delete student->file(1); // readme
        delete student;
    }
};

TEST_F(DirectoryTest, ConstructorTest) 
{
    // Verify
    EXPECT_EQ("/home/student", student->name());
    EXPECT_EQ(2, student->numberOfFiles());

    EXPECT_EQ("TODO.txt", student->file(0)->name());
    EXPECT_EQ(1024, student->file(0)->size());
    EXPECT_EQ("/home/student", student->file(0)->directory()->name());

    EXPECT_EQ("README.MD", student->file(1)->name());
    EXPECT_EQ(4096, student->file(1)->size());
    EXPECT_EQ("/home/student", student->file(1)->directory()->name());
}
