#pragma once
#include <iostream>
#include <mutex>

// RAII
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		: _ptr(ptr)
	{}
	
	~SmartPtr()
	{
		if (_ptr)
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

// C++98 auto_ptr
// 管理权转移, 早期的设计缺陷
namespace my_smartptr
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	// C++11 unique_ptr
	// 防拷贝
	// 缺陷：如果有需要拷贝的场景，就无法使用
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& up) = delete;

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	// C++11 共享拷贝
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			add_ref_count();
		}
		// sp1 = sp4
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// 减引用计数，如果是最后一个管理资源的对象，则释放资源
				release();

				// 一起管理资源
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;
				add_ref_count();
			}
			return *this;
		}

		void add_ref_count()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void release()
		{
			bool flag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)
			{
				if (_ptr)
				{
					cout << "delete:" << _ptr << endl;
					delete _ptr;
					_ptr = nullptr;
				}

				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmtx->unlock();

			if (flag == true)
			{
				delete _pmtx;
				_pmtx = nullptr;
			}
		}

		~shared_ptr()
		{
			release();
		}

		int use_count()
		{
			return *_pcount;
		}

		T* get_ptr() const
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
		// 记录有多少个对象一起管理，最后一个对象释放资源
		int* _pcount;
		std::mutex* _pmtx;
	};

	// weak_ptr不是智能指针，没有RAII
	// 专门解决循环引用
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr() = default;

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get_ptr())
		{}

		weak_ptr<T>operator = (const shared_ptr<T>& sp)
		{
			_ptr = sp.get_ptr();
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}