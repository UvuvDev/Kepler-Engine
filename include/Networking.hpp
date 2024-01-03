#pragma once

class AbstractNetwork {
public:

    AbstractNetwork(const char* IPOfServer);

    AbstractNetwork(const char* IPOfServer, uint8_t port);

	~AbstractNetwork();

	virtual void readNetwork(std::vector<char> rawData) = 0;

};




