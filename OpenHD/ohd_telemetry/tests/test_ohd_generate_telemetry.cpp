//
// Test the OHD fire and forget telemetry generator - this just prints the generated data to stdout.
//
#include <iostream>
#include <thread>

#include "../src/internal/LogCustomOHDMessages.hpp"
#include "../src/internal/OHDMainComponent.h"

int main() {
  std::cout << "OHDTelemetryGeneratorTest::start" << std::endl;

  OHDMainComponent ohdTelemetryGenerator(false);
  const auto start = std::chrono::steady_clock::now();
  while ((std::chrono::steady_clock::now() - start) < std::chrono::minutes(5)) {
	const auto msges = ohdTelemetryGenerator.generate_mavlink_messages();
	LogCustomOHDMessages::logOpenHDMessages(msges);
	std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  std::cout << "OHDTelemetryGeneratorTest::end" << std::endl;
  return 0;
}
