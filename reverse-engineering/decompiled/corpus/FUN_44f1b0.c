/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44f1b0; label: FUN_0044f1b0
 */

undefined4 FUN_0044f1b0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    iVar3 = *piVar2;
    puVar1 = (uint *)(iVar3 + 0xeec);
    *puVar1 = *puVar1 | 0x40000000;
    if ((param_5 != 0) && (iVar5 = 0, 0 < param_5)) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
        if (iVar4 == 0) {
          puVar1 = (uint *)(iVar3 + 0xeec);
          *puVar1 = *puVar1 & 0xbfffffff;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
  }
  return 1;
}

