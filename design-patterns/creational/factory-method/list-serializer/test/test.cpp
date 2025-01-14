#include <gtest/gtest.h>
#include <memory>
#include <list_serializer_json.h>
#include <list_serializer_xml.h>
#include <factory_impl.h>

using namespace std;

TEST(SerializerTest, JsonSerializer)
{
    // Setup
    shared_ptr<ListSerializerJson> serializer = make_shared<ListSerializerJson>();
    vector<int> list = {11, 13, 17, 19};
    
    // Exercise
    string json = serializer->serialize(list);

    // Verify
    cout << json << endl;
    ASSERT_EQ("{\"list\":[11,13,17,19]}", json);
}


TEST(SerializerTest, XmlSerializer)
{
    // Setup
    shared_ptr<ListSerializerXml> serializer = make_shared<ListSerializerXml>();
    
    // Exercise
    string xml = serializer->serialize({11, 13, 17, 19});

    // Verify
    cout << xml << endl;
    ASSERT_EQ("<list><item>11</item><item>13</item><item>17</item><item>19</item></list>", xml);
}


class SerializerFactoryTest : public ::testing::Test 
{
    protected:
        shared_ptr<Factory> factory;

        void SetUp() override 
        {
            factory = make_shared<FactoryImpl>();
        }
    };


TEST_F(SerializerFactoryTest, FactoryJSonSerializer)
{
    // Setup
    shared_ptr<ListSerializer> serializer = factory->createSerializer(SerializerType::JSON);
    
    // Exercise
    string json = serializer->serialize({11, 13, 17, 19});

    // Verify
    cout << json << endl;
    ASSERT_EQ("{\"list\":[11,13,17,19]}", json);
}

TEST_F(SerializerFactoryTest, FactoryXmlSerializer)
{
    // Setup
    shared_ptr<ListSerializer> serializer = factory->createSerializer(SerializerType::XML);
    
    // Exercise
    string xml = serializer->serialize({11, 13, 17, 19});

    // Verify
    cout << xml << endl;
    ASSERT_EQ("<list><item>11</item><item>13</item><item>17</item><item>19</item></list>", xml);
}
