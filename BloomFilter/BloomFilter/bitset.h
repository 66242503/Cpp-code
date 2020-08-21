#pragma once
#include <iostream>
#include <vector>

namespace my_bitset
{
	class bitset
	{
	public:
		bitset(size_t N)
		{
			_bits.resize(N / 32 + 1, 0);
			_num = 0;
		}

		void set(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置
			size_t pos = x % 32; // 算出x在整形的第几个位
			_bits[index] |= (1 << pos); // 第pos个位置置为1

			++_num;
		}

		void reset(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置
			size_t pos = x % 32; // 算出x在整形的第几个位
			_bits[index] &= ~(1 << pos); // 第pos个位置置为0
			--_num;
		}

		bool test(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置
			size_t pos = x % 32; // 算出x在整形的第几个位
			return _bits[index] & (1 << pos);
		}
		size_t size()const { return _num; }

	private:
		std::vector<int> _bits;
		size_t _num; // 映射存储多少个数据
	};

	void test_bitset()
	{
		bitset bs(100);
		bs.set(99);
		bs.set(98);
		bs.set(59);
		bs.reset(98);
		for (size_t i = 0; i < 100; i++)
		{
			printf("[%d]:%d\n", i, bs.test(i));
		}
	}
}