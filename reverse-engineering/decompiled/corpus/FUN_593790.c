/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x593790; label: FUN_00593790
 */

void FUN_00593790(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x174) != 0)) {
    iVar4 = 0;
    piVar2 = (int *)(param_1 + 0x48);
    do {
      if ((0 < *piVar2) && (iVar1 = 0, 0 < *piVar2)) {
        iVar3 = 0;
        do {
          if ((*(byte *)(piVar2[-9] + 0x12 + iVar3) & 0x80) != 0) {
            *(short *)(iVar4 + *(int *)(param_1 + 0x174)) = (short)iVar1;
          }
          if ((*(ushort *)(piVar2[-9] + 0x12 + iVar3) & 0x100) != 0) {
            *(short *)(*(int *)(param_1 + 0x174) + 0x38 + iVar4) = (short)iVar1;
          }
          iVar1 = iVar1 + 1;
          iVar3 = iVar3 + 0x28;
        } while (iVar1 < *piVar2);
      }
      iVar4 = iVar4 + 2;
      piVar2 = piVar2 + 1;
    } while (iVar4 < 0x12);
  }
  return;
}

