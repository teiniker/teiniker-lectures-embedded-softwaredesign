
#include <url_builder.h>

using namespace std;

#include <sstream>

UrlBuilder::UrlBuilder()
    : _protocol{"http"}, _port{-1}  // default protocol http, no port
{
}

UrlBuilder::UrlBuilder(const std::string& protocol, const std::string& host)
    : _port{-1} // default no port
{
    if (protocol.empty()) {
        throw std::invalid_argument("Invalid protocol");
    }
    if (host.empty()) {
        throw std::invalid_argument("Invalid host");
    }

    _protocol = protocol;
    _host = host;
}


UrlBuilder& UrlBuilder::http()
{
    _protocol = "http";
    return *this;
}

UrlBuilder& UrlBuilder::https()
{
    _protocol = "https";
    return *this;
}

UrlBuilder& UrlBuilder::ftp()
{
    _protocol = "ftp";
    return *this;
}

UrlBuilder& UrlBuilder::file()
{
    _protocol = "file";
    return *this;
}

UrlBuilder& UrlBuilder::port(int port)
{
    _port = port;
    return *this;
}

UrlBuilder& UrlBuilder::host(const std::string& host)
{
    if (host.empty()) {
        throw std::invalid_argument("Invalid host!");
    }
    _host = host;
    return *this;
}

UrlBuilder& UrlBuilder::application(const std::string& application)
{
    if (application.empty()) {
        throw std::invalid_argument("Invalid application name!");
    }
    _application = application;
    return *this;
}

UrlBuilder& UrlBuilder::parameter(const std::string& paramName, const std::string& paramValue)
{
    if (paramName.empty()) {
        throw std::invalid_argument("Invalid parameter name!");
    }
    if (paramValue.empty()) {
        throw std::invalid_argument("Invalid parameter value!");
    }

    // Replace all spaces with '+'
    std::string replacedValue = paramValue;
    for (char &ch : replacedValue) 
	{
        if (ch == ' ') 
		{
            ch = '+';
        }
    }

    // e.g. paramName=paramValue
    std::string formattedParam = paramName + "=" + replacedValue;
    _parameters.push_back(formattedParam);
    return *this;
}

std::string UrlBuilder::build() const
{
    // Example: protocol://host[:port]/application?param=val&param2=val2
    std::ostringstream oss;
    oss << _protocol << "://" << _host;

    if (_port != -1) 
	{
        oss << ":" << _port;
    }

    oss << "/" << _application;

    // If no parameters, just end with a slash. Otherwise generate ?...&...
    if (!_parameters.empty()) 
	{
        oss << generateQuery(_parameters);
    } 
	else 
	{
        oss << "/";
    }

    return oss.str();
}

std::string UrlBuilder::generateQuery(const std::vector<std::string>& params) const
{
    std::ostringstream oss;
    oss << "?";
    for (size_t i = 0; i < params.size(); ++i) 
	{
        oss << params[i];
        if (i < params.size() - 1) 
		{
            oss << "&";
        }
    }
    return oss.str();
}
