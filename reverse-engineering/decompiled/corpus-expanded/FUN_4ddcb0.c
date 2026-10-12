/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4ddcb0; label: FUN_004ddcb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004ddcb0(void)

{
  int in_EAX;
  int in_ECX;
  
  if (in_ECX == 0) {
    if (in_EAX == 1) {
      return 3;
    }
    if (in_EAX == 2) {
      return 5;
    }
  }
  else if (in_ECX == 1) {
    if (in_EAX == 0) {
      return 3;
    }
    if (in_EAX == 2) {
      return 4;
    }
  }
  else if (in_ECX == 2) {
    if (in_EAX == 1) {
      return 4;
    }
    if (in_EAX == 0) {
      return 5;
    }
  }
  return 0xffffffff;
}

