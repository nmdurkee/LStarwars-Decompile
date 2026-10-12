/* Ghidra pseudocode, not original source.
 * ev_d4822431da3638fa8d20ce7973e149332a7479471103665647c7faa9758e6d9d
 * Entry: 0x60ec70; label: FUN_0060ec70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ec70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_LAB_0076a94c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

