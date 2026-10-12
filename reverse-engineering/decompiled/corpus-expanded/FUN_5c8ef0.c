/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c8ef0; label: FUN_005c8ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c8ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007642a4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

