#include "Networking.hpp"
#include <iostream>


BasicNetwork::BasicNetwork(const char* IPOfServer) {

	ServerIPAddress = asio::ip::make_address(IPOfServer, errorCode);
	serverEndpoint = asio::ip::tcp::endpoint(ServerIPAddress, DEFAULT_NETWORK_PORT);
	Socket = new asio::ip::tcp::socket(context);

	Socket->connect(serverEndpoint, errorCode);

	if (!errorCode) { // If Error Code says device connected
		std::cout << "Connected to the Server. \n";
	}

	else {
		std::cout << "FAILURE: CONNECTION TO SERVER    REASON: " << errorCode.message();
	}

	
}


BasicNetwork::BasicNetwork(const char* IPOfServer, uint8_t port) {

	ServerIPAddress = asio::ip::make_address(IPOfServer, errorCode);
	serverEndpoint = asio::ip::tcp::endpoint(ServerIPAddress, port);
	Socket = new asio::ip::tcp::socket(context);

	Socket->connect(serverEndpoint, errorCode);

	if (!errorCode) { // If Error Code says device connected
		std::cout << "Connected to the Server. \n";
	}

	else {
		std::cout << "FAILURE: CONNECTION TO SERVER    REASON: " << errorCode.message();
	}

}

BasicNetwork::~BasicNetwork() {

	delete Socket;



}

void BasicNetwork::readNetwork(std::vector<char> rawData) {

	if (Socket->is_open()) { // If connected to the server

		std::string sRequest =
			"GET /index.html HTTP/1.1\r\n"
			"Host: example.com\r\n"
			"Connection: close \r\n\r\n"; // HTTP Request

		Socket->write_some(	// Write To Server the following:
			asio::buffer(sRequest.data(),
				sRequest.size()), errorCode); // A buffer that gets sent to server.

		size_t dataByteSize = Socket->available(); // Makes a size for a vector (soon to be defined)
												   // that is the size of the available memory
												   // from the Socket.

		Socket->wait(Socket->wait_read);

		if (dataByteSize > 0) {	// Basically if there's data to read

			rawData.resize(dataByteSize);

			Socket->read_some(asio::buffer(rawData.data(), rawData.size()), errorCode);

			if (!errorCode) { // If Error Code says device connected

				for (int i = 0; i < dataByteSize; i++) {
					std::cout << "Got Data From Server: \n\n" << rawData[i];
				}

			}

			else {
				std::cout << "FAILURE: READ FROM SERVER AT " << "p" << "    REASON: "
					<< errorCode.message();
			}



		}

	}

}