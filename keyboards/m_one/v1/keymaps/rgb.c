led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   5, NO_LED, NO_LED,   0 },
  { NO_LED, NO_LED, NO_LED, NO_LED },
  {   4, NO_LED, NO_LED,   1 },
  {   3, NO_LED, NO_LED,   2 }
}, {
  // LED Index to Physical Position
  { 220,  10 }, { 220,  60 }, { 4,  60 }, { 4,  10 },
  { 0, 0 }, { 75, 0 }, { 150, 0 }, { 224, 0 },
  { 0, 21 }, { 75, 21 }, { 150, 21 }, { 224, 21 },
  { 0, 42 }, { 75, 42 }, { 150, 42 }, { 224, 42 },
  { 0, 64 }, { 75, 64 }, { 150, 64 }, { 224, 64 },
}, {
  // LED Index to Flag
  2, 2, 2, 2, 4,4,4,4, 4,4,4,4, 4,4,4,4, 4,4,4,4
} };