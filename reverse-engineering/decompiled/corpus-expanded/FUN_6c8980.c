/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c8980; label: FUN_006c8980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c8980(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076b5b4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

