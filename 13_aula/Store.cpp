#include <string>
#include "Client.cpp"
#include "Filter.cpp"

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
		return filter->getFilteredList(_clients);
	}
};
