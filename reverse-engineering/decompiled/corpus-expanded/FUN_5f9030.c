/* Ghidra pseudocode, not original source.
 * ev_eb6388f9e6f0da39ba23c58a55c6a14172e207ae27b9d6b4ddcb98efebe4d9b1
 * Entry: 0x5f9030; label: FUN_005f9030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f9030(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 1:
    return 0x10;
  case 2:
    return 0x18;
  case 3:
    return 0x20;
  case 4:
    return 4;
  case 5:
  case 0x14:
    return 8;
  default:
    return 0;
  }
}

