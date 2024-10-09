#include <gtest/gtest.h>

#include "can-msg.h"

TEST(CanMsgTest, Constructor) 
{
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    CanMsg msg(0x123, 8, data);                         
    
    EXPECT_EQ(0x123, msg.id());
    EXPECT_EQ(8, msg.dlc());
    
    for (int i = 0; i < 8; ++i) 
    {
        EXPECT_EQ(data[i], msg.data(i));
    }
}

TEST(CanMsgTest, ConstructorWithNew) 
{
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    CanMsg* msg = new CanMsg(0x123, 8, data); 
    
    ASSERT_NE(msg, nullptr);
    EXPECT_EQ(0x123, msg->id());
    EXPECT_EQ(8, msg->dlc());
    
    for (int i = 0; i < 8; ++i) {
        EXPECT_EQ(data[i], msg->data(i));
    }

    delete msg;
}

TEST(CanMsgTest, AsString) 
{
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    CanMsg msg(0x123, 8, data);                         
    
    std::string msgStr = msg.asString();
     printf("%s\n", msgStr.c_str());
    
    std::string expected = "CAN:123|8| 01 02 03 04 05 06 07 08";
    EXPECT_EQ(expected, msgStr);
}

// Use gtest_main library
