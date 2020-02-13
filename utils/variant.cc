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

#include "utils/variant.h"

namespace libtextclassifier3 {

std::string Variant::ToString() const {
  switch (GetType()) {
    case Variant::TYPE_BOOL_VALUE:
      if (BoolValue()) {
        return "true";
      } else {
        return "false";
      }
      break;
    case Variant::TYPE_INT_VALUE:
      return std::to_string(IntValue());
      break;
    case Variant::TYPE_INT64_VALUE:
      return std::to_string(Int64Value());
      break;
    case Variant::TYPE_FLOAT_VALUE:
      return std::to_string(FloatValue());
      break;
    case Variant::TYPE_DOUBLE_VALUE:
      return std::to_string(DoubleValue());
      break;
    case Variant::TYPE_STRING_VALUE:
      return StringValue();
      break;
    default:
      TC3_LOG(FATAL) << "Unsupported variant type: " << GetType();
      return "";
      break;
  }
}

logging::LoggingStringStream& operator<<(logging::LoggingStringStream& stream,
                                         const Variant& value) {
  return stream << "Variant(" << value.GetType() << ", " << value.ToString()
                << ")";
}

}  // namespace libtextclassifier3
