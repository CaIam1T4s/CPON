#include "details/helper.h"

namespace cpon::detail {

void JsonWhat(std::wostream& stream, JsonBase* e) {
	switch (e->GetJsonType()) {
		case JsonType::kInt:
			JsonValOutPut(stream, dynamic_cast<JsonInt*>(e)->GetData());
			break;
		case JsonType::kDouble:
			JsonValOutPut(stream, dynamic_cast<JsonDouble*>(e)->GetData());
			break;
		case JsonType::kBool:
			JsonValOutPut(stream, dynamic_cast<JsonBool*>(e)->GetData());
			break;
		case JsonType::kNull:
			JsonValOutPut(stream, dynamic_cast<JsonNull*>(e)->GetData());
			break;
		case JsonType::kStr:
			JsonValOutPut(stream, *dynamic_cast<JsonString*>(e)->GetData());
			break;
		case JsonType::kArr:
			JsonArrOutPut(stream, *dynamic_cast<JsonArr*>(e)->GetData());
			break;
		case JsonType::kObj:
			JsonObjOutPut(stream, *dynamic_cast<JsonObj*>(e)->GetData());
			break;
		case JsonType::kBase:
		case JsonType::kUnknown:
			throw std::logic_error("invaild json type");
	}
}

void JsonTagOutPut(std::wostream& stream, const std::wstring& tag) {
	stream << "\"" << tag << "\": ";
}

void JsonEndLine(std::wostream& stream) {
	stream << ",\n";
}

void JsonIndent(std::wostream& stream) {
	stream << '\t';
}

void JsonArrOutPut(std::wostream& stream, const JsonArr::arr_type& arr) {
	stream << "\[\n";
	for (auto e : arr) {
		JsonIndent(stream);
		JsonWhat(stream, e);
		JsonEndLine(stream);
	}
	stream << "],\n";
}

void JsonObjOutPut(std::wostream& stream, const JsonObj::obj_type& obj) {
	stream << "\{\n";
	for (auto e: obj) {
		JsonIndent(stream);
		JsonTagOutPut(stream, e->GetTag());
		JsonWhat(stream, e);
		JsonEndLine(stream);
	}
	stream << "},\n";
}
}	// namespace cpon::detail
