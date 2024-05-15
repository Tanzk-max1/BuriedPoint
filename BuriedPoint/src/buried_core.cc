#include "buried_core.h"

#include "third_party/spdlog/include/spdlog/sinks/basic_file_sink.h"
#include "third_party/spdlog/include/spdlog/sinks/stdout_color_sinks.h"
#include "third_party/spdlog/include/spdlog/spdlog.h"

// third_party\spdlog\include\spdlog\sinks\basic_file_sink.h

void Buried::InitWorkPath_(const std::string& work_dir) {
  std::filesystem::path _work_dir(work_dir);
  if (!std::filesystem::exists(_work_dir)) {
    std::filesystem::create_directories(_work_dir);
  }

  work_path_ = _work_dir / "buried";
  if (!std::filesystem::exists(work_path_)) {
    std::filesystem::create_directories(work_path_);
  }
}