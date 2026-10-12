/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44c1d0; label: FUN_0044c1d0
 */

undefined4
FUN_0044c1d0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) &&
     (iVar3 = *piVar2, *(char *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x116) == '\x02')) {
    if (param_6 != 0) {
      iVar5 = 0;
      *(undefined1 *)(param_2 + 0x68) = 1;
      if (0 < param_5) {
        do {
          iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
          if (iVar4 == 0) {
            *(undefined1 *)(param_2 + 0x68) = 0;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_5);
      }
    }
    if (*(char *)(param_2 + 0x68) == '\0') {
      if (*(char *)(iVar3 + 0xe32) == '\x01') {
        puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_00802278;
        return 0;
      }
    }
    else if (*(char *)(iVar3 + 0xe32) != '\x01') {
      puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802278;
      return 0;
    }
  }
  return 1;
}

