#include <string>
#include "Client.cpp"
#include "Filter.hpp"

class Store {
private:
	std::string _name;
	std::list< std::shared_ptr<Client> > _clients;
public:
	Store(std::string name) : _name(name){}
	void addClient(std::shared_ptr<Client> c){
		_clients.push_back(std::move(c));
	}

	std::list< std::shared_ptr<Client> > getList(std::shared_ptr<Filter> filter){
		return filter->getFilteredList(this);
	}

	std::shared_ptr<Client> getClient(int index) {
		std::list<std::shared_ptr<Client>>::iterator i = _clients.begin();
		std::advance(i, index);
		return *i;
}

int getSize() {
		return _clients.size();
}
};
