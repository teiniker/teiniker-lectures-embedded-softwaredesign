#include <gtest/gtest.h>

#include <list_builder_json.h>
#include <list_builder_xml.h>

using namespace std;

TEST(BuilderTest, ListBuilderJson)
{
    // Setup
    ListBuilderJson builder;
    builder.item("one").item("two").item("three");
    
    // Exercise
    // The result of concrete builders are usually different types, 
    // so we have to ask the concrete builder for its result.
    string json = builder.toJson();

    // Verify
    cout << json << endl;
    ASSERT_EQ("{\"list\":[\"one\",\"two\",\"three\"]}", json);
}


TEST(BuilderTest, ListBuilderXml)
{
    // Setup
    ListBuilderXml builder;
    builder.item("one").item("two").item("three");
    
    // Exercise
    string xml = builder.toXml();

    // Verify
    cout << xml << endl;
    ASSERT_EQ("<list><item>one</item><item>two</item><item>three</item></list>", xml);
}

TEST(BuilderTest, BaseType)
{
    // Setup
    unique_ptr<ListBuilder> builder = make_unique<ListBuilderJson>();
    
    // Exercise
    builder->item("alpha").item("beta").item("gamma");

    // Verify
    // Downcast to the concrete type to get the result
    ListBuilderJson* jsonBuilder = dynamic_cast<ListBuilderJson*>(builder.get());
    ASSERT_NE(nullptr, jsonBuilder); // Verify the downcast worked
    string json = jsonBuilder->toJson();
    ASSERT_EQ("{\"list\":[\"alpha\",\"beta\",\"gamma\"]}", json);
}