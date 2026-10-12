/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x6132a0; label: FUN_006132a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006132a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076ab7c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

