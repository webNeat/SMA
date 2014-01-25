#ifndef SOCKETS_HPP
#define SOCKETS_HPP value

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
using namespace std;

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class Socket {
private:
	int m_sock;
	sockaddr_in m_addr;
public:
	Socket();
	virtual ~Socket();
	// Server initialization
	bool create();
	bool bind ( const int port );
	bool listen() const;
	bool accept ( Socket& ) const;
	// Client initialization
	bool connect ( const std::string host, const int port );
	// Data Transimission
	bool send ( const std::string ) const;
	int recv ( std::string& ) const;

	void set_non_blocking ( const bool );
	bool is_valid() const { return m_sock != -1; }
};

class ServerSocket : private Socket {
public:
  ServerSocket ( int port );
  ServerSocket (){};
  virtual ~ServerSocket();
  const ServerSocket& operator << ( const std::string& ) const;
  const ServerSocket& operator >> ( std::string& ) const;
  void accept ( ServerSocket& );
};

class SocketException {
private:
  std::string m_s;
public:
	SocketException ( std::string s ) : m_s ( s ) {};
	~SocketException (){};
	std::string description() { return m_s; }
};
#endif