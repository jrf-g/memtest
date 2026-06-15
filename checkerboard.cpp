#include <cstddef>
#include <cstdlib>
#include <cstdint>
int main() {
    std::byte* b = static_cast<std::byte*>(malloc(sizeof(std::byte)));
    if (b == NULL) {
      return 1;   // exit code 1 = allocation failed
    }
    *b = std::byte{0x55};
    uint8_t raw = std::to_integer<uint8_t>(*b);
    uint8_t flipped_raw = static_cast<uint8_t>(~raw);
    *b = std::byte{flipped_raw};
    free(b);
    return 0;
}
