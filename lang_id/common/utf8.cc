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

#include "lang_id/common/utf8.h"

namespace libtextclassifier3 {
namespace mobile {
namespace utils {

const char *GetSafeEndOfUtf8String(const char *data, size_t size) {
  const char *const hard_end = data + size;
  const char *curr = data;
  while (curr < hard_end && *curr) {
    int num_bytes = utils::OneCharLen(curr);
    const char *new_curr = curr + num_bytes;
    if (new_curr > hard_end) {
      return curr;
    }
    curr = new_curr;
  }
  return curr;
}

}  // namespace utils
}  // namespace mobile
}  // namespace nlp_saft
