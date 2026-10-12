/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x7458a0; label: FUN_007458a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007458a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007e9300;
  in_ECX[0x82] = 0;
  FUN_00740e90();
  FUN_00748490();
  FUN_007466e0();
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

