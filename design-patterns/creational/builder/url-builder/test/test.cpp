#include <gtest/gtest.h>

#include <url_builder.h>

using namespace std;

TEST(BuilderTest, HttpUrlTest) 
{
    // Setup
    string url = UrlBuilder()
        .http()
        .host("www.google.com")
        .port(80)
        .application("search")
        .parameter("q", "httpclient")
        .parameter("btnG", "Google Search")
        .parameter("aq", "f")
        .parameter("oq", "x")
        .build();
    
    // Verify
    ASSERT_EQ("http://www.google.com:80/search?q=httpclient&btnG=Google+Search&aq=f&oq=x", url);
}

