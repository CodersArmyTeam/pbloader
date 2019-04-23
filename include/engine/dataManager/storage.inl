#include "storage.hpp"

#include <utility>

namespace res {

	template<class T>
	template<typename ... Args>
	inline void Storage<T>::Add(const std::string& key, const Args&... args)
	{
		items.emplace(std::make_pair(key, args...));
	}

	template<class T>
	inline void Storage<T>::Remove(const std::string& key)
	{
		items.erase(key);
	}

	template<class T>
	inline void Storage<T>::Clear()
	{
		items.clear();
	}

	template<class T>
	T Storage<T>::Get(const std::string& n) 
	{
		try
		{	
			return items.at(n);
		} 
		catch( const std::exception& e )
		{
			//logError(e.what());
			SDL_Surface* result = items.begin()->second;
			return result;
		}
	}

	template<class T>
	int Storage<T>::Size() {
		return items.size();
	}

	template<class T>
	T Storage<T>::operator[](const std::string& n)
	{
		return *items.at(n);
	}


}; //namespace res