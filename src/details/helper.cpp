#include "details/helper.h"

namespace cpon::detail {

void JsonTagOutPut(std::wostream& stream, const std::wstring& tag) {
	stream << "\"" << tag << "\": ";
}

void JsonArrOutPut(std::wostream& stream, const JsonArr::arr_type& arr) {
	stream << "\{\n";
	for (auto& e : arr) {

	}
	stream << "},\n";
}
}	// namespace cpon::detail
