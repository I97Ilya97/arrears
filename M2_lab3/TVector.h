#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__

#include <iostream>

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
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr;
	}

	iterator end() const throw()
	{
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr + Count;
	}

	void reserve(size_type size)
	{
		if (size < InternalCapacity)
		{
			return;
		}
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
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
		
		if (index < 0 || index >= Count) throw std::exception("Incorrect index\n");
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr[index];
	}

	value_type at(size_type index) const
	{
		if (index < 0 || index >= Count) throw std::exception("Incorrect index\n");
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr[index];
	}

	reference operator[](size_type index)
	{
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr[index];
	}

	reference front()
	{
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr[0];
	}

	const_reference front() const
	{
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr[0];
	}

	reference back()
	{
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr[Count - 1];
	}

	const_reference back() const
	{
		if(!Ptr)throw new std::out_of_range("Out of range in TVector\n");
		return Ptr[Count - 1];
	}

	void clear()
	{
		
		delete[] Ptr;
	}

	void pop_back()
	{
		if(!Ptr)throw new std::out_of_range("Nullptr TVector\n");
		if (!Count) throw std::exception("Empty!!");
		Ptr[Count - 1] = NULL;
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
		if (count > INT_MAX) throw std::exception("More INT_MAX!!");
		if (count > Count)
		{
			reserve(count);
			for (size_type i = Count; i < count; i++) Ptr[i] = value;
		}
		Count = count;
	}

	iterator insert(iterator pos, const value_type& value)
	{
		if (*pos > Count) throw std::exception("Not find pos!!");
		if (Count == InternalCapacity) this->reserve(InternalCapacity * 2);
		Count++;
		for (size_type i = Count - 1; i > pos - Ptr; i--) {
			Ptr[i] = Ptr[i - 1];
		}
		Ptr[pos - Ptr] = value;
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		if (*pos > Count) throw std::exception("Not find pos!!");
		Count += count;
		reserve(Count);
		for (size_type i = Count - 1; i >= *pos + count; i--) Ptr[i] = Ptr[i - count];
		for (size_type i = 0; i < count; i++) Ptr[*pos + i] = value;
	}

	iterator erase(iterator pos)
	{
		if (*pos > Count) throw std::exception("Not found pos!!");
		for (size_type i = pos - Ptr; i < Count - 1; i++)	Ptr[i] = Ptr[i + 1];
		Count--;
		return pos;
	}

	iterator erase(iterator first, iterator last)
	{
		if (first > Ptr + Count || last > Ptr + Count)
			throw std::out_of_range("This pos is more than size of vector!");

		int las = last - Ptr;
		int fir = first - Ptr;
		for (fir; fir < Count - las; fir++)	Ptr[fir] = Ptr[las + fir];
		Count -= las;
		return first;
	}
};


#endif // __TVECTOR_INCLUDED__
