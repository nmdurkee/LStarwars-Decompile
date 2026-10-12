/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf270; label: FUN_006cf270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cf270(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f690;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

