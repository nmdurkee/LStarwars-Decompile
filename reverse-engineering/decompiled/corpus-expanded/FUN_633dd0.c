/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x633dd0; label: FUN_00633dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00633dd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076b234;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

