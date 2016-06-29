#pragma once

//#include <iostream>
//#include <tchar.h>

//template<typename T>
//std::ostream& operator<<(std::ostream& os, T& obj) {
//	os << typeid(obj).name() << std::endl << "Size: "\
//			<< obj.size() << "  Cap: " \
//			<< obj.capacity() << "   Max_size: "\
//			<< obj.max_size() << std::endl;
//		return os;
//}

template<typename T>
void RandPoiAssigner(T& cont) {
	for_each(cont.begin(), cont.end(), [](Point& val) {
		val = Point((87.0 / (rand() % 10 + 1)), (87.0 / (rand() % 10 + 1)));
	});
	
};
template<typename T>
T PoiFinder(T&obj, Point& poi) {
	T tmp;
	auto it = obj.begin();
	auto ite = obj.end();
	while (it != ite) {
		tmp.insert(tmp.end(), *(it = find(it, obj.end(), poi)));
		++it;
	}
	return tmp;
}

template<typename T>
void PrintStat(const T& obj) {
	std::cout << typeid(obj).name() << std::endl << 
		"Size: " << obj.size() << \
		//"  Cap: " << obj.capacity() << 
		"   Max_size: "<< obj.max_size() << std::endl;		
}
template<typename  T>
void PrintVector(const std::vector<T>& obj) {
	int size = obj.size();
	for (int i = 0; i < size; i++){
		std::cout << obj[i] << std::endl;
	}
}
template<typename T1, typename  T2>
std::ostream& operator<<(std::ostream& os,const std::pair<const T1, T2>& P) {
	return os << P.first << "  " << P.second ;
}
template<typename T1, typename  T2 >
std::ostream& operator<<(std::ostream& os, const std::map<const T2, std::pair<const T2,T1>>& P) {
	return os << P.first << "  " << P.second;
}

template<typename T>
void Print(const T& obj) {

	auto it = obj.begin();
	int size = obj.size();
	for (int i = 0; i < size; i++)	{
		std::cout << *it << std::endl;
		++it;
	}
}
template<typename T>
void PrintIT(const T& obj) {
	std::cout << obj << std::endl;
}
template<typename T>
void Print(std::pair<T,T> ITs) {
	while (ITs.first != ITs.second) {
		std::cout << *ITs.first << std::endl;
		++ITs.first;
	}
}

template<typename T>
void PrintCont(const T& obj) {
	for_each(obj.begin(), obj.end(), PrintIT<typename T::value_type>);
}


template<typename T >
void PrintTop(std::stack<T>& obj) {
	std::cout << obj.top() << std::endl;
}
template<typename T >
const T& GetTop(std::stack<T>& obj) {
	return obj.top();
}
template<typename T>
void PrintTop(std::queue<T>& obj) {
	std::cout << obj.front() << std::endl;
}
template<typename T>
const T& GetTop(std::queue<T>& obj) {
	return obj.front();
}
template<typename T>
void PrintTop(std::priority_queue<T>& obj) {
	std::cout << obj.top() << std::endl;
}
template<typename T>
const T& GetTop(std::priority_queue<T>& obj) {
	return (obj.top());
}
template<typename T>
void PrintStdC(T obj) {
	while (!obj.empty()){
		std::cout << GetTop(obj) << std::endl;
		obj.pop();
	}

}

template<typename T, typename P= typename T::value_type>
void PrintVoid(const T& obj ) {
	
	auto it = obj.begin();
	int size = obj.size();
	for (int i = 0; i < size; i++) {
		std::cout << static_cast<P*>(*it)<<std::endl;
		++it;
	}
	
	//std::cout << typeid(obj).name() << std::endl << "Size: "\
	//	<< obj.size() << "  Cap: " \
	//	<< obj.capacity() << "   Max_size: "\
	//	<< obj.max_size() << std::endl;

}


template<typename C, typename T>
	bool FindVal(C& container, T& val) {
		if (typeid(val) == typeid(C::value_type)) {   ////////?????
			auto it_b = container.begin();
			auto it_e = container.end();
				while (it_b != it_e) {
					if (*it_b == val) {
						return true;
					}
					else { ++it_b; }
				}
		}
	return false;
}

	template<typename C, typename T>
	bool Insert_if_absent(C& container,const T& val) {   //// && - ?
		if (FindVal(container, val)) {
			return false;
		}
		container.insert(container.begin(), val);
		return true;
	}

	template<typename T>
	bool DefineSeq(T& it) { /// как записать именно(исключительно) итератор?!... - никак... =(((
		auto tmp = it;
		
		do {
			++tmp;
		} while (*it == *tmp);

		if (it == --tmp) {			
			return  false;
		}
		it = ++tmp;			//////?????
		return true;
	}

	template<typename K>
	void DeleteSeqs(K& container) {
		auto it_b = container.begin();
		auto it_e = container.end();

		while (it_b != it_e) {
			auto itTmp = std::next(it_b);
			
			while ((itTmp != it_e)&&(*it_b == *itTmp)){
				++itTmp;
			}
			if (it_b != --itTmp) {
				it_b = container.erase(it_b, ++itTmp);
				it_e = container.end();
			}
			else {
				++it_b;
			}
		}
	}
	


	

	template<typename K>
	void DeleteTwicy(K& container) {
		auto it_val = container.begin();
		auto it_e = container.end();
		

		while (it_val != it_e) {
			auto it_runner = std::next(it_val);
			
			while (it_runner != it_e) {
				if (*it_val == *it_runner) {
					it_runner = container.erase(it_runner);
					it_e = container.end();
					}
				else{
					++it_runner;
				}
			}
			
		 ++it_val;
		}
	}

	template<typename K>
	void DelExcesSpaces(K& container) {
		auto it_val = container.begin();
		auto it_e_1 = --container.end() ;
		while (it_val != it_e_1) {
			if (*it_val == ' ') {
				auto tmp = it_val;
				if (DefineSeq(tmp)) {
					it_val = container.erase(++it_val, tmp);
					it_e_1 = --container.end();
				}
			}
			++it_val;
		}
	}

	template<typename K>
	void CleanPoinerContainer(K& container) {
		auto it_runner = container.begin();
		auto it_e = container.end();
		while (it_runner != it_e){
			delete *it_runner;
			++it_runner;
		}
	}

	template<typename K>
	void CleanPoinerAdapter(K& obj) {
		while (!obj.empty()) {
			delete GetTop(obj);
			obj.pop();
		}
	}