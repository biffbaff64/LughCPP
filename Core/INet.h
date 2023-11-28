#ifndef INET_H
#define INET_H

class INet
{
public:
    class IHttpResponse
    {
    public:
        virtual byte[] GetResult() = 0;

        virtual char* GetResultAsString() = 0;

        virtual StreamReader GetResultAsStream() = 0;

        HttpStatus GetStatus();

        char* GetHeader(char* name);

        Dictionary< char*, List< char* > > GetHeaders();
    };

private:
    INet() = default;
    virtual ~INet() = default;
};

#endif //INET_H
