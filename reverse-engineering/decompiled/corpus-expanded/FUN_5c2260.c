/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2260; label: FUN_005c2260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2260(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007642a4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

