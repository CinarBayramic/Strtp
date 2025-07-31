 #include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include "parse.hpp"
int main() {
    int port = 8080;
    int server_fd = socket(AF_INET, SOCK_STREAM,0);
    if(server_fd < 0) {perror("socket");return 1;}

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    int opt = 1;
setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));


    bind(server_fd, (sockaddr*)&server, sizeof(server));
    listen(server_fd,1);
    int client_fd;
    int total = 0;
    while(true) {
    int client_fd = accept(server_fd,nullptr, nullptr);
    total++;
    char buffer[1024] = {};
    recv(client_fd,buffer,sizeof(buffer),0);

    auto tok = tokenise(std::string(buffer), " :");
    ////for(std::string s: tok) {
    //    std::cout << s << "\n";
    //}
    try {std::cout << "FILE:" <<tok[searchfor(tok,"GET")+1] << "\n";} catch (const char*e) {
        std::cout << "error:" << e << "\n";

    }
    std::cout << "Received:" << buffer << "\n";
    //std::string msg = buffer;

    std::string msg = "<html><body><h1>siteye giriş yapılma sayısı:"+ std::to_string(total) + "</h1></body></html>";
std::string header = "HTTP/1.1 200 OK\r\n"
                  "Access-Control-Allow-Origin: *\r\n"
                  "Connection: Keep-Alive\r\n"
                  "Content-Type: text/html; charset=utf-8\r\n"
                  "Content-Length: " + std::to_string(msg.size()) + "\r\n"
                  "\r\n" + msg;
    //recv(client_fd,buffer,sizeof(buffer),0);
    
    send(client_fd,header.c_str(),header.size(),0);
    close(client_fd);
}
    close(server_fd);
}