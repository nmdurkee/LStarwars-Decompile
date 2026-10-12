/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x697360; label: FUN_00697360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00697360(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xd0c);
  if (iVar1 != 0) {
    return CONCAT31((int3)((uint)iVar1 >> 8),*(undefined1 *)(param_1 * 0x40c + 0x404 + iVar1));
  }
  return 0;
}

