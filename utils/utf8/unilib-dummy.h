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

// UniLib implementation that does not support much. Basic functionality is
// provided with the help of the std library, but there's no real regex support,
// no regex matches.

#ifndef LIBTEXTCLASSIFIER_UTILS_UTF8_UNILIB_DUMMY_H_
#define LIBTEXTCLASSIFIER_UTILS_UTF8_UNILIB_DUMMY_H_

#include <memory>

#include "utils/base/integral_types.h"
#include "utils/utf8/unicodetext.h"

namespace libtextclassifier3 {

class UniLibBase {
 public:
  bool ParseInt32(const UnicodeText& text, int* result) const;
  bool ParseInt64(const UnicodeText& text, int64* result) const;
  bool ParseDouble(const UnicodeText& text, double* result) const;

  bool IsOpeningBracket(char32 codepoint) const;
  bool IsClosingBracket(char32 codepoint) const;
  bool IsWhitespace(char32 codepoint) const;
  bool IsDigit(char32 codepoint) const;
  bool IsLower(char32 codepoint) const;
  bool IsUpper(char32 codepoint) const;
  bool IsPunctuation(char32 codepoint) const;

  char32 ToLower(char32 codepoint) const;
  char32 ToUpper(char32 codepoint) const;
  char32 GetPairedBracket(char32 codepoint) const;

  // Forward declaration for friend.
  class RegexPattern;

  class RegexMatcher {
   public:
    static constexpr int kError = -1;
    static constexpr int kNoError = 0;

    bool ApproximatelyMatches(int* status) const;
    bool Matches(int* status) const;
    bool Find(int* status);
    int Start(int* status) const;
    int Start(int group_idx, int* status) const;
    int End(int* status) const;
    int End(int group_idx, int* status) const;
    UnicodeText Group(int* status) const;
    UnicodeText Group(int group_idx, int* status) const;
    std::string Text() const;

   protected:
    friend class RegexPattern;
    explicit RegexMatcher() {}
  };

  class RegexPattern {
   public:
    std::unique_ptr<RegexMatcher> Matcher(const UnicodeText& input) const;

   protected:
    friend class UniLibBase;
    explicit RegexPattern() {}
  };

  class BreakIterator {
   public:
    int Next();

    static constexpr int kDone = -1;

   protected:
    friend class UniLibBase;
    explicit BreakIterator(const UnicodeText& text);
  };

  std::unique_ptr<RegexPattern> CreateRegexPattern(
      const UnicodeText& regex) const;
  std::unique_ptr<RegexPattern> CreateLazyRegexPattern(
      const UnicodeText& regex) const;
  std::unique_ptr<BreakIterator> CreateBreakIterator(
      const UnicodeText& text) const;
};

}  // namespace libtextclassifier3

#endif  // LIBTEXTCLASSIFIER_UTILS_UTF8_UNILIB_DUMMY_H_
