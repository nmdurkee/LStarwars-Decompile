/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x6972d0; label: FUN_006972d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006972d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(&DAT_0075eaf8,PTR_DAT_00810d94);
  if (iVar1 == 0) {
    FUN_00696fa0(param_1,param_2);
    return;
  }
  FUN_00696a90(PTR_DAT_00810d94);
  return;
}

