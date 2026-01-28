# Web Application: Translator

## Setup
Start the given the following Java web application in a terminal:
```
$ java -jar translator.jar
```

## Manual Tests Using a Browser
We can open a web browser and execute the following test cases manually:

URL: http://localhost:8080/index.html

```
    word = 'cat', language = 'Deutsch' => 'Translate: cat into Katze'
    word = 'horse', language = 'Francais' => 'Translate: horse into Cheval' 
    word = 'dog', language = 'Deutsch' => 'Translate: dog into unknown'
    word = 'dog', language = 'Francais' => 'Translate: dog into unknown'
```

## Manual Tests Using cURL 

**cURL** is a command line tool to execute HTTP(S) requests. We use this tool 
to send a POST request to the web application:

_Example_: GET request 
```
$ curl -i http://localhost:8080

HTTP/1.1 200 
Vary: Origin
Vary: Access-Control-Request-Method
Vary: Access-Control-Request-Headers
Last-Modified: Thu, 21 Oct 2021 18:42:44 GMT
Accept-Ranges: bytes
Content-Type: text/html;charset=UTF-8
Content-Language: en-US
Content-Length: 1160
Date: Wed, 29 Jun 2022 13:42:53 GMT

<html>
<head>
    <title>Servlet Translator</title>
</head>

<body>
<h2>Translator </h2>
    ...
</body>
</html>
```

_Example_: POST request  
```
$ curl -i -X POST -d 'word=cat&language=Deutsch&action=Translate' http://localhost:8080/translator

HTTP/1.1 200 
Content-Type: text/html;charset=UTF-8
Content-Language: en-US
Transfer-Encoding: chunked
Date: Tue, 21 Jun 2022 19:14:25 GMT

<!DOCTYPE HTML>
<html>
<head>
    <title>Translation Application</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
</head>
<body>
    <h2>
        <p >Translate: cat into Katze</p>
    </h2>
    <p/>
    <a href="index.html"> back</a>
</body>
</html>
```

By changing the values of the given `cURL` statement we can runn all the tests 
shown above.

## References

* [cURL](https://curl.se/)
* [cURL Tutorial](https://curl.se/docs/manual.html)

* [Spring Boot](https://spring.io/projects/spring-boot)

*Egon Teiniker, 2020-2026, GPL v3.0*