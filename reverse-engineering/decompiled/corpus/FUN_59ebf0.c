/* Ghidra analysis pseudocode, not original source.
 * ev_619d50b6392102a54c9e38c540a3f8930ee6fdfe94aeb342acdefb90820d232e
 * Entry: 0x59ebf0; label: FUN_0059ebf0
 */

void FUN_0059ebf0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004f9e70(param_1);
  uVar2 = FUN_004f9e70(param_1);
  *(undefined4 *)(&DAT_00956300 + iVar1 * 4) = uVar2;
  return;
}

