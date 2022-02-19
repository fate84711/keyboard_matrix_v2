const byte rowPins[] = {7, 8, 9};
const byte colPins[] = {14, 16};
const byte analogpin[] = {A2};
const int debounce_time = 10;

// 要輸出的文字要使用' '包含 使用" " 會造成錯誤 
//      col1 col2 ...
//  row1
//  row2
//  row3
//  ...

const char keyMap[sizeof(rowPins)][sizeof(colPins)] = {
  {'q', 'a'},
  {'w', 's'},
  {'e', 'd'}
};
