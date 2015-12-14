#include <string>
#include "Client.cpp"

class Store {
private:
	std::string _name;
    std::list< std::shared_ptr<Client> > _client;
public:
	Store(std::string name) : _name(name){}
	void addClient(std::shared_ptr<Client> c){
		_client.push_back(std::move(c));
	}

	std::list< std::shared_ptr<Client> > 
};
