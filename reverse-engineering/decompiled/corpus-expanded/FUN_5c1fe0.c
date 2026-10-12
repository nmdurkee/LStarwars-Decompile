/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c1fe0; label: FUN_005c1fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1fe0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  return;
}

