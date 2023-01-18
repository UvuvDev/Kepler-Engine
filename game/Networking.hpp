#pragma once

#define ASIO_STANDALONE // IMPORTANT: NEEDED TO SAY TO NOT TRY TO USE BOOST

#include "Networking/asio.hpp"

#include "Networking/asio/ts/buffer.hpp"
#include "Networking/asio/ts/internet.hpp"

#define DEFAULT_NETWORK_PORT 80



class BasicNetwork {
protected:

	asio::error_code errorCode;

	asio::io_context context; // Basically, an object that all ASIO things run in.

	asio::ip::address ServerIPAddress; // IP Address of the Server

	asio::ip::tcp::endpoint serverEndpoint;

	asio::ip::tcp::socket* Socket; // Basically is the door to the server.

public:

	BasicNetwork(const char* IPOfServer);

	BasicNetwork(const char* IPOfServer, uint8_t port);

	~BasicNetwork();

	void readNetwork(std::vector<char> rawData);

};




