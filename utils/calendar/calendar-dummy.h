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

#ifndef LIBTEXTCLASSIFIER_UTILS_CALENDAR_CALENDAR_DUMMY_H_
#define LIBTEXTCLASSIFIER_UTILS_CALENDAR_CALENDAR_DUMMY_H_

#include <string>

#include "annotator/types.h"
#include "utils/base/integral_types.h"

namespace libtextclassifier3 {

class Calendar {
 public:
  bool Initialize(const std::string& time_zone, const std::string& locale,
                  int64 time_ms_utc) {
    return false;
  }
  bool AddSecond(int value) const { return false; }
  bool AddMinute(int value) const { return false; }
  bool AddHourOfDay(int value) const { return false; }
  bool AddDayOfMonth(int value) const { return false; }
  bool AddYear(int value) const { return false; }
  bool AddMonth(int value) const { return false; }
  bool GetDayOfWeek(int* value) const { return false; }
  bool GetFirstDayOfWeek(int* value) const { return false; }
  bool GetTimeInMillis(int64* value) const { return false; }
  bool SetZoneOffset(int value) const { return false; }
  bool SetDstOffset(int value) const { return false; }
  bool SetYear(int value) const { return false; }
  bool SetMonth(int value) const { return false; }
  bool SetDayOfYear(int value) const { return false; }
  bool SetDayOfMonth(int value) const { return false; }
  bool SetDayOfWeek(int value) const { return false; }
  bool SetHourOfDay(int value) const { return false; }
  bool SetMinute(int value) const { return false; }
  bool SetSecond(int value) const { return false; }
  bool SetMillisecond(int value) const { return false; }
};

class CalendarLib {
 public:
  // Returns false (dummy version).
  bool InterpretParseData(const DatetimeParsedData& parse_data,
                          int64 reference_time_ms_utc,
                          const std::string& reference_timezone,
                          const std::string& reference_locale,
                          bool prefer_future_for_unspecified_date,
                          int64* interpreted_time_ms_utc,
                          DatetimeGranularity* granularity) const {
    return false;
  }

  DatetimeGranularity GetGranularity(const DatetimeParsedData& data) const {
    return GRANULARITY_UNKNOWN;
  }
};

}  // namespace libtextclassifier3
#endif  // LIBTEXTCLASSIFIER_UTILS_CALENDAR_CALENDAR_DUMMY_H_
