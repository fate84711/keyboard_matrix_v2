const byte rowPins[] = {7, 8, 9};
const byte colPins[] = {14, 16};
const byte analogpin[] = {A2};
const int debounce_time = 10;

const char keyMap[sizeof(rowPins)][sizeof(colPins)] = {
  {'q', 'a'},
  {'w', 's'},
  {'e', 'd'}
};
