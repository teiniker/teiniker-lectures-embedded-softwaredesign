#include <gtest/gtest.h>

#include <logger.h>

using namespace std;

TEST(LoggerTest, testSingleObject)
{
    auto log1 = Logger::getInstance();
    auto log2 = Logger::getInstance();

    // Verify that both references refer to the same instance
    EXPECT_EQ(log1, log2);
}

TEST(LoggerTest, testDebug)
{
    auto log = Logger::getInstance();

    log->debug("This is a debug message");

    SUCCEED();  // Indicates that reaching this point means the test passed.
}

TEST(LoggerTest, testInfo)
{
    auto log = Logger::getInstance();

    log->info("This is an information");

    SUCCEED();  
}
