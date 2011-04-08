/*
 * Copyright 2011 Marshmallow Engine. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *      conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *      of conditions and the following disclaimer in the documentation and/or other materials
 *      provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY MARSHMALLOW ENGINE ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MARSHMALLOW ENGINE OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Marshmallow Engine.
 */

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#pragma once

#ifndef CORE_SHARED_H
#define CORE_SHARED_H 1

#include "core/global.h"

MARSHMALLOW_NAMESPACE_BEGIN

namespace Core
{

	/*! @brief Shared Data Struct */
	struct CORE_EXPORT SharedData {
	    void * ptr;
	    INT16 refs;
	};

	/*! @brief Shared class */
	template <class T>
	class Shared
	{
	public:
		Shared(T *ptr = 0);
		Shared(const Shared &copy);
		~Shared(void)
		    { clear(); }

		void clear(void);

	public: /* operator */

		operator bool(void) const
		    { return(m_data != 0); }

		T & operator *(void) const
		    { return(*reinterpret_cast<T *>(m_data->ptr)); }

		T * operator ->(void) const
		    { return(reinterpret_cast<T *>(m_data->ptr)); }

		Shared & operator =(const Shared &rhs);

		bool operator ==(const Shared &rhs) const
		    { return(m_data && m_data == rhs.m_data); }

	private:
		SharedData *m_data;
	};

	template <class T>
	Shared<T>::Shared(T *ptr)
	    : m_data(0)
	{
		if (ptr) {
			m_data = new SharedData;
			m_data->ptr  = ptr;
			m_data->refs = 1;
		}
	}

	template <class T>
	Shared<T>::Shared(const Shared &copy)
	    : m_data(copy.m_data)
	{
		if (m_data) ++m_data->refs;
	}

	template <class T>
	Shared<T> &
	Shared<T>::operator =(const Shared<T> &rhs)
	{
		clear();

		if (rhs) {
			m_data = rhs.m_data;
			++m_data->refs;
		}

		return(*this);
	}

	template <class T>
	void
	Shared<T>::clear(void)
	{
		if (m_data && --m_data->refs <= 0) {
			T *ptr = reinterpret_cast<T *>(m_data->ptr);
			delete ptr;
			delete m_data;
		}
		m_data = 0;
	}

}

MARSHMALLOW_NAMESPACE_END

#endif
