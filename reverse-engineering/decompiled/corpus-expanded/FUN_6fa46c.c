/* Ghidra pseudocode, not original source.
 * ev_626d54f17f079edfd1ff8b6caea4a3c32539f18361fa5c980ebe5ce2dfd8aaf4
 * Entry: 0x6fa46c; label: FUN_006fa46c
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006fa46c(void)

{
  int in_EAX;
  
  if (in_EAX == 0x3a4) {
    return 0x411;
  }
  if (in_EAX == 0x3a8) {
    return 0x804;
  }
  if (in_EAX == 0x3b5) {
    return 0x412;
  }
  if (in_EAX != 0x3b6) {
    return 0;
  }
  return 0x404;
}

