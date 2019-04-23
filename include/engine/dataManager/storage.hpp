#pragma once

#include <map>

namespace res {

	template<typename T>
	class Storage {
	private:

		std::map<std::string, T> items;

	public:

		Storage() {}
		Storage(const Storage& other)
		 : items(other.items) {}

		~Storage() {}


		//enter the arguments to the constructor after the key (if none, leave only the key)
		template<typename ... Args>
		inline void Add(const std::string& key, const Args&...);

		inline void Remove(const std::string& key);

		inline void Clear();

		inline int Size();

		// returns the last item if the key does not match to anything
		T Get(const std::string& n);

		// will create a new item if the key does not match to anything
		T operator[](const std::string& n);

	};

}; //namespace res

#include "storage.inl"