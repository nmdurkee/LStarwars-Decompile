/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54b540; label: FUN_0054b540
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

