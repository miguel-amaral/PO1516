class Filter {
public:
    virtual std::list< std::shared_ptr<Client>>
                  getFilteredList(Store *store) =0;
};
