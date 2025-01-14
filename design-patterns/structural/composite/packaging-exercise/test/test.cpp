#include <gtest/gtest.h>

#include <article.h>
#include <box.h>

using namespace std;

TEST(CompositeTestGroup, ArticleTest)
{
    shared_ptr<Article> book(new Article("Design Patterns", 5, 350));

    // Verify
    EXPECT_EQ("Design Patterns", book->name());
    EXPECT_EQ(5 * 350, book->totalWeight());
}

TEST(CompositeTestGroup, DirectoryTest)
{
    shared_ptr<Node> box(new Box(100));
    
    shared_ptr<Node> book(new Article("Effective c++", 2, 250));
    box->addNode(book);
    
    shared_ptr<Node> tee(new Article("Tee", 3, 80));
    box->addNode(tee);
        
    // Verify
    EXPECT_EQ(100 + 2 * 250 + 3 * 80, box->totalWeight());
}

TEST(CompositeTestGroup, OrderTest)
{
    shared_ptr<Node> package(new Box(200));
    shared_ptr<Node> box1(new Box(50));
    package->addNode(box1);    
    
    shared_ptr<Node> box2(new Box(100));
    package->addNode(box2);    

    shared_ptr<Node> pi(new Article("Raspberry Pi", 5, 80));
    shared_ptr<Node> card(new Article("Memory Card", 5, 10));    
    box1->addNode(pi);
    box1->addNode(card);
    
    shared_ptr<Node> book(new Article("Embedded C++", 1, 250));
    box2->addNode(book);
    
    // Verify
    EXPECT_EQ(200 + 50 + 100 + 5 * 80 + 5 * 10 + 1 * 250, package->totalWeight());
}
