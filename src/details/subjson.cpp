#include "details/subjson.h"

namespace cpon::detail {

JsonBase::JsonBase() : m_tag(nullptr) {}

JsonBase::~JsonBase() { delete m_tag; }

JsonBase::JsonBase(const tag_type& str) : m_tag(new std::wstring(str)) {}

JsonInt::JsonInt() : JsonBase(), m_data(0) {}

JsonInt::~JsonInt() {}

JsonInt::JsonInt(const std::wstring& str, int val) : JsonBase(str), m_data(val) {}

JsonDouble::JsonDouble() : JsonBase(), m_data(0.0) {}

JsonDouble::~JsonDouble() {}

JsonDouble::JsonDouble(const std::wstring& str, double val) : JsonBase(str), m_data(val) {}

JsonBool::JsonBool() : JsonBase(), m_data(false) {}

JsonBool::~JsonBool() {}

JsonBool::JsonBool(const std::wstring& str, bool val) : JsonBase(str), m_data(val) {}

JsonNull::JsonNull() : JsonBase(), m_data(nullptr) {}

JsonNull::~JsonNull() {}

JsonNull::JsonNull(const std::wstring& str, nullptr_t val) : JsonBase(str), m_data(val) {}

JsonString::JsonString() : JsonBase(), m_data(nullptr) {}

JsonString::~JsonString() { delete m_data; }

JsonString::JsonString(const std::wstring& str, const std::wstring& val) 
		: JsonBase(str), m_data(new std::wstring(val)) {}

JsonArr::JsonArr() : JsonBase(), m_data(nullptr) {}

JsonArr::~JsonArr() { 
	m_data->~arr_type();
	delete m_data;
}

JsonArr::JsonArr(const std::wstring& str, pointer arr) 
		: JsonBase(str), m_data(arr) {}

JsonObj::JsonObj() : JsonBase(), m_data(nullptr) {}

JsonObj::~JsonObj() { 
	m_data->~obj_type();
	delete m_data;
}

JsonObj::JsonObj(const std::wstring& str, pointer memList) 
		: JsonBase(str), m_data(memList) {}

}	// namespace cpon::detail
