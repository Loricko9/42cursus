/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:33:50 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/21 11:37:32 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class	Array
{
public:
	Array<T>() : _array(new T()), _size (0) {};
	Array<T>(unsigned int n) : _array(new T[n]), _size(n) {};
	Array<T>(const Array &src) : _array(new T[src._size]), _size(src._size) {
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	};
	Array&	operator=(const Array &rhs) {
		if (this != &rhs)
		{
			delete [] _array;
			_array = new T[rhs._size];
			_size = rhs._size;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
		}
		return (*this);
	};
	~Array<T>() {delete [] _array;};
	
	class	InvalidIndexException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Invalid out of bounds !");
		}
	};
	
	T&	operator[](unsigned int i) {
		if (i >= size())
			throw InvalidIndexException();
		return (_array[i]);
	};
	
	unsigned int size() {return(_size);};
private:
	T* 				_array;
	unsigned int	_size;
};

#endif
