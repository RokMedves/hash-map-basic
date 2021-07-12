#ifndef HASH_MAP_HH_INCLUDED
#define HASH_MAP_HH_INCLUDED

#include <string>
#include <vector>
#include <cassert>

template <class T>
class HashMap{

public:
    HashMap(){
        values_ = new HashEntry [N_max_]();
    }

    virtual ~HashMap(){
        delete values_;
    }

    T& operator[](const std::string & s){
        HashEntry& entry = values_[hash_funtion(s)];
        if(!entry.is_set()){
            entry.init_value();
            keys_.push_back(s);
        }
        return entry.value();
    }

    friend std::ostream& operator<<(std::ostream& out, const HashMap& m){
        out << "key\tvalue" << std::endl;
        m.print_keys_and_values(out);
        return out;
    }

protected:

    virtual unsigned int hash_funtion(const std::string & s) const{
        // A simple has function which works for
        // s = ``1, 2, 3, 4, .. ,9''

        unsigned int output = (int)s[0] - '0';
        assert(output < N_max_ && output >= 0);
        return output;
    }

    virtual std::ostream& print_keys_and_values(std::ostream & out) const{
        for(int i = 0; i < keys_.size(); ++i){
            std::string key = keys_[i];
            unsigned int hashed_key = hash_funtion(key);
            const HashEntry& value = values_[hashed_key];
            out << key << "\t" << value << std::endl;
        }
        return out;
    }
private:

    class HashEntry{

    public:
        HashEntry() : value_ {nullptr}{};
        HashEntry(T* value) : value_ {value}{};
        virtual ~HashEntry() {if(is_set()) delete value_;};

        T& value(){return *value_;}
        bool is_set(){return value_ != nullptr;}
        void init_value(){value_ = new T;}

        friend std::ostream & operator<< (std::ostream & out, const HashEntry & entry){
            if (entry.value_ == nullptr) out << "null pointer!";
            else out << *entry.value_;
            return out;
        }

    private:
        T* value_;
    };

private:

    // place to store the keys
    std::vector<std::string> keys_;
    HashEntry* values_ = nullptr;

    const unsigned int N_max_ = 10;

        void print_all_values(){
        for(int i = 0; i < this->N_max_; ++i){
            std::cout << values_[i] << std::endl;
        }
    }

};

#endif // HASH-MAP_HH_INCLUDED
