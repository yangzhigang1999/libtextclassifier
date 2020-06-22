// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "utils/utf8/unilib-dummy.h"

#include <cctype>
#include <map>

#include "utils/base/logging.h"
#include "utils/strings/numbers.h"
#include "utils/utf8/unilib-common.h"

namespace libtextclassifier3 {

bool UniLibBase::ParseInt32(const UnicodeText& text, int* result) const {
  return libtextclassifier3::ParseInt32(text.data(), result);
}

bool UniLibBase::ParseInt64(const UnicodeText& text, int64* result) const {
  return libtextclassifier3::ParseInt64(text.data(), result);
}

bool UniLibBase::ParseDouble(const UnicodeText& text, double* result) const {
  return libtextclassifier3::ParseDouble(text.data(), result);
}

bool UniLibBase::IsOpeningBracket(char32 codepoint) const {
  return codepoint == '(' || codepoint == '[' || codepoint == '{';
}

bool UniLibBase::IsClosingBracket(char32 codepoint) const {
  return codepoint == ')' || codepoint == ']' || codepoint == '}';
}

bool UniLibBase::IsWhitespace(char32 codepoint) const {
  return codepoint == ' ' || codepoint == '\t';
}

bool UniLibBase::IsDigit(char32 codepoint) const {
  return std::isdigit(codepoint);
}

bool UniLibBase::IsLower(char32 codepoint) const {
  return std::islower(codepoint);
}

bool UniLibBase::IsUpper(char32 codepoint) const {
  return std::isupper(codepoint);
}

bool UniLibBase::IsPunctuation(char32 codepoint) const {
  return std::ispunct(codepoint);
}

char32 UniLibBase::ToLower(char32 codepoint) const {
  return std::tolower(codepoint);
}

char32 UniLibBase::ToUpper(char32 codepoint) const {
  return std::toupper(codepoint);
}

char32 UniLibBase::GetPairedBracket(char32 codepoint) const {
  static std::map<char32, char32>& table = *[]() {
    return new std::map<char32, char32>{
        {'(', ')'}, {')', '('}, {'[', ']'}, {']', '['}, {'{', '}'}, {'}', '{'},
    };
  }();

  auto it = table.find(codepoint);
  if (it != table.end()) {
    return it->second;
  } else {
    return codepoint;
  }
}

std::unique_ptr<UniLibBase::RegexMatcher> UniLibBase::RegexPattern::Matcher(
    const UnicodeText& input) const {
  return std::unique_ptr<UniLibBase::RegexMatcher>(
      new UniLibBase::RegexMatcher());
}

constexpr int UniLibBase::RegexMatcher::kError;
constexpr int UniLibBase::RegexMatcher::kNoError;

bool UniLibBase::RegexMatcher::ApproximatelyMatches(int* status) const {
  *status = kNoError;
  return false;
}

bool UniLibBase::RegexMatcher::Matches(int* status) const {
  *status = kNoError;
  return false;
}

bool UniLibBase::RegexMatcher::Find(int* status) {
  *status = kNoError;
  return false;
}

int UniLibBase::RegexMatcher::Start(int* status) const {
  *status = kError;
  return kError;
}

int UniLibBase::RegexMatcher::Start(int group_idx, int* status) const {
  *status = kError;
  return kError;
}

int UniLibBase::RegexMatcher::End(int* status) const {
  *status = kError;
  return kError;
}

int UniLibBase::RegexMatcher::End(int group_idx, int* status) const {
  *status = kError;
  return kError;
}

UnicodeText UniLibBase::RegexMatcher::Group(int* status) const {
  *status = kError;
  return UTF8ToUnicodeText("", /*do_copy=*/true);
}

UnicodeText UniLibBase::RegexMatcher::Group(int group_idx, int* status) const {
  *status = kError;
  return UTF8ToUnicodeText("", /*do_copy=*/true);
}

std::string UniLibBase::RegexMatcher::Text() const { return "<DUMMY TEXT>"; }

constexpr int UniLibBase::BreakIterator::kDone;

UniLibBase::BreakIterator::BreakIterator(const UnicodeText& text) {}

int UniLibBase::BreakIterator::Next() { return BreakIterator::kDone; }

std::unique_ptr<UniLibBase::RegexPattern> UniLibBase::CreateRegexPattern(
    const UnicodeText& regex) const {
  return std::unique_ptr<UniLibBase::RegexPattern>(
      new UniLibBase::RegexPattern());
}

std::unique_ptr<UniLibBase::RegexPattern> UniLibBase::CreateLazyRegexPattern(
    const UnicodeText& regex) const {
  return std::unique_ptr<UniLibBase::RegexPattern>(
      new UniLibBase::RegexPattern());
}

std::unique_ptr<UniLibBase::BreakIterator> UniLibBase::CreateBreakIterator(
    const UnicodeText& text) const {
  return std::unique_ptr<UniLibBase::BreakIterator>(
      new UniLibBase::BreakIterator(text));
}

}  // namespace libtextclassifier3
