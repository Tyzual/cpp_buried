#include <chrono>
#include <cstdint>
#include <iostream>
#include <thread>

int main() {
  constexpr uint32_t MAX = 1000000;
  constexpr uint32_t THREAD_CNT = 4;

  auto res = 0u;
  auto begin = std::chrono::system_clock::now();
  for (auto i = 0u; i < MAX; ++i) {
    res += i;
  }
  auto dur = std::chrono::system_clock::now() - begin;
  std::cout
      << "dur1:"
      << std::chrono::duration_cast<std::chrono::microseconds>(dur).count()
      << std::endl;

  std::thread ts[THREAD_CNT];
  uint32_t rss[THREAD_CNT] = {0};
  constexpr auto MAX_PER_THREAD = MAX / THREAD_CNT;
  begin = std::chrono::system_clock::now();
  for (auto i = 0u; i < THREAD_CNT; ++i) {
    ts[i] = std::thread([idx = i, &rss] {
      auto start = idx * MAX_PER_THREAD;
      auto end = start + MAX_PER_THREAD;
      for (auto i = start; i < end; ++i) {
        rss[idx] += i;
      }
    });
  }

  for (auto& t : ts) {
    t.join();
  }
  dur = std::chrono::system_clock::now() - begin;
  std::cout
      << "dur2:"
      << std::chrono::duration_cast<std::chrono::microseconds>(dur).count()
      << std::endl;

#if 1
  begin = std::chrono::system_clock::now();
  for (auto i = 0u; i < THREAD_CNT; ++i) {
    ts[i] = std::thread([idx = i, &rss] {
      auto start = idx * MAX_PER_THREAD;
      auto end = start + MAX_PER_THREAD;
      auto res = 0u;
      for (auto i = start; i < end; ++i) {
        res += i;
      }
      rss[idx] = res;
    });
  }

  for (auto& t : ts) {
    t.join();
  }

  dur = std::chrono::system_clock::now() - begin;
  std::cout
      << "dur3:"
      << std::chrono::duration_cast<std::chrono::microseconds>(dur).count()
      << std::endl;
#endif

  return 0;
}