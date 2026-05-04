// ColorUtils.h
#pragma once
#include <tuple>
#include <cstdint>

inline std::tuple<uint8_t, uint8_t, uint8_t> getColorFromIndex(int index) {
    switch (index) {
    case 0:  return {0, 255, 0};     // Green
    case 1:  return {255, 0, 0};     // Red
    case 2:  return {0, 0, 255};     // Blue
    case 3:  return {255, 255, 0};   // Yellow
    case 4:  return {0, 255, 255};   // Cyan
    case 5:  return {255, 0, 255};   // Magenta
    case 6:  return {255, 165, 0};   // Orange
    case 7:  return {128, 0, 128};   // Purple
    case 8:  return {165, 42, 42};   // Brown
    case 9:  return {255, 192, 203}; // Pink
    case 10: return {128, 128, 0};   // Olive
    case 11: return {0, 128, 128};   // Teal
    case 12: return {0, 0, 128};     // Navy
    case 13: return {64, 64, 64}; // Gray
    case 14: return {192, 192, 192}; // Silver
    case 15: return {173, 216, 230}; // Light Blue
    case 16: return {255, 215, 0};   // Gold
    case 17: return {144, 238, 144}; // Light Green
    case 18: return {255, 140, 0};   // Dark Orange
    case 19: return {75, 0, 130};    // Indigo
    case 20: return {132, 230, 94};  // Select_Highlight

    default: return {200, 200, 200};
    }
}
