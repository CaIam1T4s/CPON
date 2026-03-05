#include "details/subjson.h"

namespace cpon::detail {

JsonBase::JsonBase() : m_tag(nullptr) {}

JsonBase::~JsonBase() { delete m_tag; }

JsonBase::JsonBase(const tag_type& str) : m_tag(new std::wstring(str)) {}

auto JsonBase::GetTag() const -> const std::wstring& { return *m_tag; }

JsonInt::JsonInt() : JsonBase(), m_data(0) {}

JsonInt::~JsonInt() {}

JsonInt::JsonInt(const std::wstring& str, int val) : JsonBase(str), m_data(val) {}

auto JsonInt::GetJsonType() const -> JsonType { return JsonType::kInt; }

auto JsonInt::GetData() const -> value_type { return m_data; }

JsonDouble::JsonDouble() : JsonBase(), m_data(0.0) {}

JsonDouble::~JsonDouble() {}

JsonDouble::JsonDouble(const std::wstring& str, double val) : JsonBase(str), m_data(val) {}

auto JsonDouble::GetJsonType() const -> JsonType { return JsonType::kDouble; }

auto JsonDouble::GetData() const -> value_type { return m_data; }

JsonBool::JsonBool() : JsonBase(), m_data(false) {}

JsonBool::~JsonBool() {}

JsonBool::JsonBool(const std::wstring& str, bool val) : JsonBase(str), m_data(val) {}

auto JsonBool::GetJsonType() const -> JsonType { return JsonType::kBool; }

auto JsonBool::GetData() const -> value_type { return m_data; }

JsonNull::JsonNull() : JsonBase(), m_data(nullptr) {}

JsonNull::~JsonNull() {}

JsonNull::JsonNull(const std::wstring& str, nullptr_t val) : JsonBase(str), m_data(val) {}

auto JsonNull::GetJsonType() const -> JsonType { return JsonType::kNull; }

auto JsonNull::GetData() const -> value_type { return m_data; }

JsonString::JsonString() : JsonBase(), m_data(nullptr) {}

JsonString::~JsonString() { delete m_data; }

JsonString::JsonString(const std::wstring& str, const std::wstring& val) 
		: JsonBase(str), m_data(new std::wstring(val)) {}

auto JsonString::GetJsonType() const -> JsonType { return JsonType::kStr; }

auto JsonString::GetData() const -> pointer { return m_data; }

JsonArr::JsonArr() : JsonBase(), m_data(nullptr) {}

JsonArr::~JsonArr() { 
	// m_data->~arr_type();
}

JsonArr::JsonArr(const std::wstring& str, pointer arr) 
		: JsonBase(str), m_data(arr) {}

auto JsonArr::GetJsonType() const -> JsonType { return JsonType::kArr; }

auto JsonArr::GetData() const -> pointer { return m_data; }

JsonObj::JsonObj() : JsonBase(), m_data(nullptr) {}

JsonObj::~JsonObj() { 
	// m_data->~obj_type();
}

JsonObj::JsonObj(const std::wstring& str, pointer memList) 
		: JsonBase(str), m_data(memList) {}

auto JsonObj::GetJsonType() const -> JsonType { return JsonType::kObj; }

auto JsonObj::GetData() const -> pointer { return m_data; }

}	// namespace cpon::detail
