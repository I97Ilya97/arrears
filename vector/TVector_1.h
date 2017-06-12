#pragma once

#include <limits.h>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstring>

#define std_disclaimer() {throw new std::out_of_range("Out of range\n");}

template <typename T>
class TVector
{
public:
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }

	TVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	~TVector()
	{
		delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		if(!Ptr)std_disclaimer();
		return Ptr;
	}

	iterator end() const throw()
	{
		if(!Ptr)std_disclaimer();
		return Ptr + Count;
	}

	void reserve(size_type size)
	{
		if (size < InternalCapacity)
		{
			return;
		}
		if(!Ptr)std_disclaimer();
		value_type * New = new value_type[size];
		memcpy(New, Ptr, Count * sizeof(int));
		delete[]Ptr;
		InternalCapacity = size;
		Ptr = New;
		New = nullptr;
	}

	TVector(const TVector& rhs)
	{
		InternalCapacity = rhs.InternalCapacity;
		Count = rhs.size();
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
	}

	TVector& operator=(const TVector& rhs)
	{
		delete Ptr;
		Count = rhs.size();
		InternalCapacity = rhs.InternalCapacity;
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
		return *this;
	}

	void push_back(const value_type& value)
	{
		if (!InternalCapacity) reserve(1);
		if (Count == InternalCapacity)	reserve(InternalCapacity * 2);
		Ptr[Count] = value;
		Count++;
	}

	reference at(size_type index)
	{
		
		if (index < 0 || index >= Count) std_disclaimer();
		if(!Ptr)std_disclaimer();
		return Ptr[index];
	}

	value_type at(size_type index) const
	{
		if (index < 0 || index >= Count) std_disclaimer();
		if(!Ptr)std_disclaimer();
		return Ptr[index];
	}

	reference operator[](size_type index)
	{
		if(!Ptr)std_disclaimer();
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		if(!Ptr)std_disclaimer();
		return Ptr[index];
	}

	reference front()
	{
		if(!Ptr)std_disclaimer();
		return Ptr[0];
	}

	const_reference front() const
	{
		if(!Ptr)std_disclaimer();
		return Ptr[0];
	}

	reference back()
	{
		if(!Ptr)std_disclaimer();
		return Ptr[Count - 1];
	}

	const_reference back() const
	{
		if(!Ptr)std_disclaimer();
		return Ptr[Count - 1];
	}

	void clear()
	{
		
		delete[] Ptr;
	}

	void pop_back()
	{
		if(!Ptr)std_disclaimer();
		if (!Count)std_disclaimer();
		Ptr[Count - 1] = 0;
		Count--;
	}

	void swap(TVector& other) throw()
	{
		std::swap(InternalCapacity, other.InternalCapacity);
		std::swap(Ptr, other.Ptr);
		std::swap(Count, other.Count);
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (count > INT_MAX)std_disclaimer();
		if (count > Count)
		{
			reserve(count);
			for (size_type i = Count; i < count; i++) Ptr[i] = value;
		}
		Count = count;
	}

	iterator insert(iterator pos, const value_type& value)
	{
		if ((size_type)*pos > Count)std_disclaimer();
		if (Count == InternalCapacity) this->reserve(InternalCapacity * 2);
		Count++;
		for (size_type i = Count - 1; i > (size_type)(pos - Ptr);i--) {
			Ptr[i] = Ptr[i - 1];
		}
		Ptr[pos - Ptr] = value;
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		if (*pos > Count)std_disclaimer();
		Count += count;
		reserve(Count);
		for (size_type i = Count - 1; i >= *pos + count; i--) Ptr[i] = Ptr[i - count];
		for (size_type i = 0; i < count; i++) Ptr[*pos + i] = value;
	}

	iterator erase(iterator pos)
	{
		if ((size_type)*pos > Count)std_disclaimer();
		for (size_type i = pos - Ptr; i < Count - 1; i++)	Ptr[i] = Ptr[i + 1];
		Count--;
		return pos;
	}

	iterator erase(iterator first, iterator last)
	{
		if (first > Ptr + Count || last > Ptr + Count)
			std_disclaimer();

		size_type last_ptr = last - Ptr;
		size_type first_ptr = first - Ptr;
		while ( first_ptr < Count - last_ptr ){	
			Ptr[first_ptr] = Ptr[last_ptr + first_ptr];
			first_ptr++;
		}
		Count -= last_ptr;
		return first;
	}
};


