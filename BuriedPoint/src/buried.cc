// #include "include/buried.h"

// #include <iostream>

// #include "buried_core.h"

// extern "C" {
// int BuriedTest() {
//   std::cout << "Test";
//   return 1;
// }

// Buried* Buried_Create(const char* work_dir) {
//   if (!work_dir) {
//     return nullptr;
//   }
//   return new Buried(work_dir);
// }

// void Buried_Destroy(Buried* buried) {
//   if (buried) {
//     delete buried;
//   }
// }

// int32_t Buried_Start(Buried* buried, BuriedConfig* config) {
//   // 检查输入参数是否有效
//   if (!buried || !config) {
//     return BuriedResult::kBuriedInvalidParam;
//   }
//   // 创建Buried::Config对象

//   // Buried::Config buried_config;
//   Buried::Config buried_config;

//   // 将传入的配置参数赋值给Buried::Config对象
//   if (config->host) {
//     buried_config.host = config->host;
//   }
//   if (config->topic) {
//     buried_config.topic = config->topic;
//   }
//   if (config->user_id) {
//     buried_config.user_id = config->user_id;
//   }
//   if (config->version) {
//     buried_config.version = config->version;
//   }
//   if (config->custom_data) {
//     buried_config.custom_data = config->custom_data;
//   }
//   // 调用Buried对象的Start方法，并传入配置参数
//   return buried->Start(buried_config);
// }

// int32_t Buried_Report(Buried* buried, const char* report_data,
//                       uint32_t priority) {
//   if (!buried || !report_data) {
//     return BuriedResult::kBuriedInvalidParam;
//   }
//   return buried->Report(report_data, priority);
// }
// }


#include "include/buried.h"

#include <iostream>

#include "buried_core.h"

int BuriedTest() {
  std::cout << "Test";
  return 1;
}

Buried* Buried_Create(const char* work_dir) {
  if (!work_dir) {
    return nullptr;
  }
  return new Buried(work_dir);
}

void Buried_Destroy(Buried* buried) {
  if (buried) {
    delete buried;
  }
}

int32_t Buried_Start(Buried* buried, BuriedConfig* config) {
  if (!buried || !config) {
    return BuriedResult::kBuriedInvalidParam;
  }
  Buried::Config buried_config;
  if (config->host) {
    buried_config.host = config->host;
  }
  if (config->topic) {
    buried_config.topic = config->topic;
  }
  if (config->user_id) {
    buried_config.user_id = config->user_id;
  }
  if (config->version) {
    buried_config.version = config->version;
  }
  if (config->custom_data) {
    buried_config.custom_data = config->custom_data;
  }
  return buried->Start(buried_config);
}

int32_t Buried_Report(Buried* buried, const char* report_data,
                      uint32_t priority) {
  if (!buried || !report_data) {
    return BuriedResult::kBuriedInvalidParam;
  }
  return buried->Report(report_data, priority);
}
