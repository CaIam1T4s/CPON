#ifndef HELPER_H
#define HELPER_H

#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "subjson.h"

namespace cpon::detail {

void JsonWhat(std::wostream& stream, JsonBase* e); 
	
void JsonTagOutPut(std::wostream& stream, const std::wstring& tag);

void JsonEndLine(std::wostream& stream);

void JsonIndent(std::wostream& stream);

void JsonArrOutPut(std::wostream& stream, const JsonArr::arr_type& arr);

void JsonObjOutPut(std::wostream& stream, const JsonObj::obj_type& obj);

template <typename Ty>
void JsonValOutPut(std::wostream& stream, Ty val) {
	stream << val;
}

template <>
inline void JsonValOutPut<bool>(std::wostream& stream, bool val) {
	stream << std::boolalpha << val << std::noboolalpha;
}

template <>
inline void JsonValOutPut<nullptr_t>(std::wostream& stream, nullptr_t) {
	stream << L"null";
}

template <>
inline void JsonValOutPut<const std::wstring&>(std::wostream& stream, const std::wstring& str) {
	stream << "\"" << str << "\"";
}

template <typename Ty>
auto GetJsonType() -> JsonType {
	if constexpr (std::is_same_v<Ty, JsonBase>) { return JsonType::kBase; } else 
	if constexpr (std::is_same_v<Ty, JsonInt>) { return JsonType::kInt; } else 
	if constexpr (std::is_same_v<Ty, JsonDouble>) { return JsonType::kDouble;	} else 
	if constexpr (std::is_same_v<Ty, JsonBool>) { return JsonType::kBool; } else 
	if constexpr (std::is_same_v<Ty, JsonNull>) { return JsonType::kNull; } else 
	if constexpr (std::is_same_v<Ty, JsonString>) { return JsonType::kStr; } else 
	if constexpr (std::is_same_v<Ty, JsonArr>) { return JsonType::kArr; } else 
	if constexpr (std::is_same_v<Ty, JsonObj>) { return JsonType::kObj; } else {
		return JsonType::kUnknown;
	}
}

}	// namespace cpon::detail

#endif	// HELPER_H
