#pragma once
#include <iostream>
#include <regex>

// regex_match�� null-terminated ���ڿ��� ���̸� �˻��ϱ� ������
// NULL ���ڰ� ���Ե� ���۴� �� �˻��� �� ����.
// ���� ������ ���̸� �Է¹޾� ó���ϴ� �Լ��� ���Ӱ� �������.
bool regex_bmatch(_In_z_ const char *_Str,
		int _Len, 
		const std::regex& _Re,
		std::regex_constants::match_flag_type _Flgs =
		std::regex_constants::match_default)
{	// try to match regular expression to target text
	const char *_Last = _Str + _Len;;
	return (std::_Regex_match(_Str, _Last,
		(std::match_results<const char *> *)0, _Re,
		_Flgs | std::regex_constants::match_any, true));
}

// See std::regex_match
bool regex_bmatch(_In_z_ const char *_Str,
	int _Len,
	std::match_results<const char *>& _Matches,
	const std::regex& _Re,
	std::regex_constants::match_flag_type _Flgs =
	std::regex_constants::match_default)
{	// try to match regular expression to target text
	const char *_Last = _Str + _Len;
	return (_Regex_match(_Str, _Last,
		&_Matches, _Re, _Flgs, true));
}

// See std::regex_bsearch
bool regex_bsearch(_In_z_ const char *_Str,
	int _Len,
	std::match_results<const char*>& _Matches,
	const std::regex& _Re,
	std::regex_constants::match_flag_type _Flgs =
	std::regex_constants::match_default)
{	// search for regular expression match in target text
	const char *_Last = _Str + _Len;
	return (_Regex_search(_Str, _Last, &_Matches, _Re, _Flgs, _Str));
}