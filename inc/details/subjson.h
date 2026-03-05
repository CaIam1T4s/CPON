#ifndef SUBJSON_H
#define SUBJSON_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace cpon::detail {

enum class JsonType : std::int8_t {
	kUnknown = -2,
	kBase = -1,
	kInt = 0,
	kDouble,
	kBool,
	kNull,
	kStr,
	kArr,
	kObj
};	// enum class JsonType

// forward declaration
class JsonBase;
class JsonInt;
class JsonDouble;
class JsonBool;
class JsonNull;
class JsonString;
class JsonArr;
class JsonObj;

// class declaration
class JsonBase {
public:
	using tag_type   = std::wstring;
	using self_type  = JsonBase;
public:
	friend auto operator<<(std::wostream& stream, const JsonBase& val) -> std::wostream&;
	friend auto operator>>(std::wistream& stream, JsonBase& val) -> std::wistream&;
public:
	JsonBase();
	virtual ~JsonBase();
	JsonBase(const JsonBase&)                        = delete;
	JsonBase(JsonBase&&) noexcept                    = delete;
	auto operator=(const JsonBase&) -> JsonBase&     = delete;
	auto operator=(JsonBase&&) noexcept -> JsonBase& = delete;
	[[nodiscard]] auto GetTag() const -> const std::wstring&;
	[[nodiscard]] virtual auto GetJsonType() const -> JsonType = 0;
public:
	JsonBase(const tag_type& str);
private:
	tag_type* m_tag;
};	// class JsonBase

class JsonInt final : public JsonBase {
public:
	using value_type = int;
	using self_type  = JsonInt;
public:
	friend auto operator<<(std::wostream& stream, const JsonInt& val) -> std::wostream&;
	friend auto operator>>(std::wistream& stream, JsonInt& val) -> std::wistream&;
public:
	JsonInt();
	~JsonInt() final;
	JsonInt(const JsonInt&)                        = delete;
	JsonInt(JsonInt&&) noexcept                    = delete;
	auto operator=(const JsonInt&) -> JsonInt&     = delete;
	auto operator=(JsonInt&&) noexcept -> JsonInt& = delete;
public:
	JsonInt(const std::wstring& str, int val);
	[[nodiscard]] auto GetJsonType() const -> JsonType final;
	[[nodiscard]] auto GetData() const -> value_type;
private:
	value_type m_data;
};	// class JsonInt

class JsonDouble final : public JsonBase {
public:
	using value_type = double;
	using self_type  = JsonDouble;
public:
	friend auto operator<<(std::wostream& stream, const JsonDouble& val) -> std::wostream&;
	friend auto operator>>(std::wistream& stream, JsonDouble& val) -> std::wistream&;
public:
	JsonDouble();
	~JsonDouble() final;
	JsonDouble(const JsonDouble&)                        = delete;
	JsonDouble(JsonDouble&&) noexcept                    = delete;
	auto operator=(const JsonDouble&) -> JsonDouble&     = delete;
	auto operator=(JsonDouble&&) noexcept -> JsonDouble& = delete;
public:
	JsonDouble(const std::wstring& str, double val);
	[[nodiscard]] auto GetJsonType() const -> JsonType final;
	[[nodiscard]] auto GetData() const -> value_type;
private:
	value_type m_data;
};	// class JsonDouble

class JsonBool final : public JsonBase {
public:
	using value_type = bool;
	using self_type  = JsonBool;
public:
	friend auto operator<<(std::wostream& stream, const JsonBool& val) -> std::wostream&;
	friend auto operator>>(std::wistream& stream, JsonBool& val) -> std::wistream&;
public:
	JsonBool();
	~JsonBool() final;
	JsonBool(const JsonBool&)                        = delete;
	JsonBool(JsonBool&&) noexcept                    = delete;
	auto operator=(const JsonBool&) -> JsonBool&     = delete;
	auto operator=(JsonBool&&) noexcept -> JsonBool& = delete;
public:
	JsonBool(const std::wstring& str, bool val);
	[[nodiscard]] auto GetJsonType() const -> JsonType final;
	[[nodiscard]] auto GetData() const -> value_type;
private:
	value_type m_data;
};	// class JsonBool

class JsonNull final : public JsonBase {
public:
	using value_type = nullptr_t;
	using self_type  = JsonNull;
public:
	friend auto operator<<(std::wostream& stream, const JsonNull& val) -> std::wostream&;
	friend auto operator>>(std::wistream& stream, JsonNull& val) -> std::wistream&;
public:
	JsonNull();
	~JsonNull() final;
	JsonNull(const JsonNull&)                        = delete;
	JsonNull(JsonNull&&) noexcept                    = delete;
	auto operator=(const JsonNull&) -> JsonNull&     = delete;
	auto operator=(JsonNull&&) noexcept -> JsonNull& = delete;
public:
	JsonNull(const std::wstring& str, nullptr_t val);
	[[nodiscard]] auto GetJsonType() const -> JsonType final;
	[[nodiscard]] auto GetData() const -> value_type;
private:
	value_type m_data;
};	// class JsonNull

class JsonString final : public JsonBase {
public:
	using value_type = std::wstring;
	using pointer    = std::wstring*;
	using self_type  = JsonString;
public:
	friend auto operator<<(std::wostream& stream, const JsonString& val) -> std::wostream&;
	friend auto operator>>(std::wistream& stream, JsonString& val) -> std::wistream&;
public:
	JsonString();
	~JsonString() final;
	JsonString(const JsonString&)                        = delete;
	JsonString(JsonString&&) noexcept                    = delete;
	auto operator=(const JsonString&) -> JsonString&     = delete;
	auto operator=(JsonString&&) noexcept -> JsonString& = delete;
public:
	JsonString(const std::wstring& str, const std::wstring& val);
	[[nodiscard]] auto GetJsonType() const -> JsonType final;
	[[nodiscard]] auto GetData() const -> pointer;
private:
	pointer m_data;
};	// class JsonString

class JsonArr final : public JsonBase {
public:
	using arr_type   = std::vector<JsonBase*>;
	using pointer    = std::vector<JsonBase*>*;
	using self_type  = JsonArr;
public:
	friend auto operator<<(std::wostream& stream, const JsonDouble& val) -> std::wostream&;
	friend auto operator>>(std::wistream& stream, JsonDouble& val) -> std::wistream&;
public:
	JsonArr();
	~JsonArr() final;
	JsonArr(const JsonArr&)                        = delete;
	JsonArr(JsonArr&&) noexcept                    = delete;
	auto operator=(const JsonArr&) -> JsonArr&     = delete;
	auto operator=(JsonArr&&) noexcept -> JsonArr& = delete;
public:
	JsonArr(const std::wstring& str, pointer arr);
	[[nodiscard]] auto GetJsonType() const -> JsonType final;
	[[nodiscard]] auto GetData() const -> pointer;
private:
	pointer m_data;
};	// class JsonArr

class JsonObj final : public JsonBase	{
public:
	using obj_type   = std::vector<JsonBase*>;
	using pointer    = std::vector<JsonBase*>*;
	using self_type  = JsonObj;
public:
	friend auto operator<<(std::wostream& stream, const JsonDouble& val) -> std::wostream&;
	friend auto operator>>(std::wistream& stream, JsonDouble& val) -> std::wistream&;
public:
	JsonObj();
	~JsonObj() final;
	JsonObj(const JsonObj&)                        = delete;
	JsonObj(JsonObj&&) noexcept                    = delete;
	auto operator=(const JsonObj&) -> JsonObj&     = delete;
	auto operator=(JsonObj&&) noexcept -> JsonObj& = delete;
public:
	JsonObj(const std::wstring& str, pointer memList);
	[[nodiscard]] auto GetJsonType() const -> JsonType final;
	[[nodiscard]] auto GetData() const -> pointer;
private:
	pointer m_data;
};	// class JsonObj

}	// namespace cpon::detail

#endif	// SUBJSON_H
