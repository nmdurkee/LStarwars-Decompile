/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x445fe0; label: FUN_00445fe0
 */

undefined4
FUN_00445fe0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_6 == 0) {
    return 1;
  }
  iVar3 = 0;
  if (param_5 < 1) {
    return 1;
  }
  do {
    iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"name=");
    if (iVar1 != 0) {
      uVar2 = FUN_0051ac70(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar1 + 5);
      *(undefined4 *)(param_2 + 0xa8) = uVar2;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < param_5);
  return 1;
}

