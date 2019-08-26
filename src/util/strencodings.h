// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BLOCKCHAIN_SRC_UTIL_STRENCODINGS_H_
#define BLOCKCHAIN_SRC_UTIL_STRENCODINGS_H_

/**
 * Utilities for converting data from/to strings.
 */

#include "../attributes.h"

#include <cstdint>
#include <iterator>
#include <string>
#include <vector>

#define ARRAYLEN(array) (sizeof(array))/sizeof((array[0]))

/**
 * Used by SanitizeString
 */
enum SafeChar {
  SAFE_CHARS_DEFAULT, //!< The full set of allowed chars
  SAFE_CHARS_UA_COMMENT, //!< BIP-0014 subset
  SAFE_CHARS_FILENAME, //!< Chars allowed in filenames
  SAFE_CHARS_URI, //!< Chars allowed in URIs (RFC 3986)
};

/**
* Remove unsafe chars. Safe chars chosen to allow simple messages/URLs/email
* addresses, but avoid anything even possibly remotely dangerous like & or >
* @param[in] str    The string to sanitize
* @param[in] rule   The set of safe chars to choose (default: least restrictive)
* @return           A new string without unsafe chars
*/
std::string SanitizeString(const std::string &str, int rule = SAFE_CHARS_DEFAULT);
std::vector<unsigned char> ParseHex(const char *psz);
std::vector<unsigned char> ParseHex(const std::string &str);
signed char HexDigit(char c);
/* Returns true if each character in str is a hex character, and has an even
 * number of hex digits.*/
bool IsHex(const std::string &str);
/**
* Return true if the string is a hex number, optionally prefixed with "0x"
*/
bool IsHexNumber(const std::string &str);
std::vector<unsigned char> DecodeBase64(const char *p, bool *pf_invalid = nullptr);
std::string DecodeBase64(const std::string &str, bool *pf_invalid = nullptr);
std::string EncodeBase64(const unsigned char *pch, size_t len);
std::string EncodeBase64(const std::string &str);
std::vector<unsigned char> DecodeBase32(const char *p, bool *pf_invalid = nullptr);
std::string DecodeBase32(const std::string &str, bool *pf_invalid = nullptr);
std::string EncodeBase32(const unsigned char *pch, size_t len);
std::string EncodeBase32(const std::string &str);

void SplitHostPort(std::string in, int &portOut, std::string &hostOut);
std::string i64tostr(int64_t n);
std::string itostr(int n);
int64_t atoi64(const char *psz);
int64_t atoi64(const std::string &str);
int atoi(const std::string &str);

/**
 * Tests if the given character is a decimal digit.
 * @param[in] c     character to test
 * @return          true if the argument is a decimal digit; otherwise false.
 */
 constexpr bool IsDigit(char c) {
   return c >= '0' && c <= '9';
 }

/**
* Tests if the given character is a whitespace character. The whitespace characters
* are: space, form-feed ('\f'), newline ('\n'), carriage return ('\r'), horizontal
* tab ('\t'), and vertical tab ('\v').
*
* This function is locale independent. Under the C locale this function gives the
* same result as std::isspace.
*
* @param[in] c     character to test
* @return          true if the argument is a whitespace character; otherwise false
*/
constexpr inline bool IsSpace(char c) noexcept {
  return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v';
}

/**
 * Convert string to signed 32-bit integer with strict parse error feedback.
 * @returns true if the entire string could be parsed as valid integer,
 *   false if not the entire string could be parsed or when overflow or underflow occurred.
 */
 NODISCARD bool ParseInt32(const std::string &str, int32_t *out);

/**
* Convert string to signed 64-bit integer with strict parse error feedback.
* @returns true if the entire string could be parsed as valid integer,
*   false if not the entire string could be parsed or when overflow or underflow occurred.
*/






#endif //BLOCKCHAIN_SRC_UTIL_STRENCODINGS_H_
