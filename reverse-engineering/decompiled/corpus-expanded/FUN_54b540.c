/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54b540; label: FUN_0054b540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054b540(undefined *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined *)0x0) {
    PTR_DAT_00802360 = param_1;
  }
  DAT_00802364 = 0;
  iVar1 = *(int *)PTR_DAT_00802360;
  while (iVar1 != -1) {
    DAT_00802364 = DAT_00802364 + 1;
    iVar1 = *(int *)(PTR_DAT_00802360 + DAT_00802364 * 8);
  }
  return;
}

