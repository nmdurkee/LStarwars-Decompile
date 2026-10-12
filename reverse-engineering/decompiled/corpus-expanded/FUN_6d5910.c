/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d5910; label: FUN_006d5910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d5910(byte param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x67e4) = 0;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

