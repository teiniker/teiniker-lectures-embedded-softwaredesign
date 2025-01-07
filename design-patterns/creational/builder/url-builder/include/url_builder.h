#ifndef _URL_BUILDER_H_
#define _URL_BUILDER_H_

#include <string>
#include <vector>

class UrlBuilder
{
public:
    // Constructors
    UrlBuilder();
    UrlBuilder(const std::string& protocol, const std::string& host);

    // Builder methods (these return a reference to *this)
    UrlBuilder& http();
    UrlBuilder& https();
    UrlBuilder& ftp();
    UrlBuilder& file();

    UrlBuilder& port(int port);
    UrlBuilder& host(const std::string& host);
    UrlBuilder& application(const std::string& application);
    UrlBuilder& parameter(const std::string& paramName, const std::string& paramValue);

    // Build method
    std::string build() const;

private:
    // Fields
    std::string _protocol;          
    int _port;                      
    std::string _host;
    std::string _application;
    std::vector<std::string> _parameters;

    // Helper method to generate the query string (e.g., ?param1=val1&param2=val2)
    std::string generateQuery(const std::vector<std::string>& params) const;
};

#endif /*_URL_BUILDER_H_ */
