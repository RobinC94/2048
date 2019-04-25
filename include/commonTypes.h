#pragma once
#include <vector>

using BoardRow = std::vector<int>;
using Matrix = std::vector<BoardRow>;

using Board = std::vector<int>;

enum class Direction : int { UP, DOWN, LEFT, RIGHT };

const int ROW_COUNT = 4;
const int COL_COUNT = 4;


