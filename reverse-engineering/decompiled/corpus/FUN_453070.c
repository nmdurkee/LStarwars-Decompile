/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x453070; label: FUN_00453070
 */

undefined4
FUN_00453070(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && ((param_1 != 0 && (*(int *)(param_1 + 0x138c) != 0)))) {
    iVar2 = *piVar1;
    if ((param_6 != 0) && ((*(int *)(PTR_DAT_00802c54 + 0x4678) != 0 && (iVar4 = 0, 0 < param_5))))
    {
      do {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757700);
        if (iVar3 != 0) {
          FUN_005147c0(param_2,iVar3 + 4);
          iVar3 = FUN_006e6b90();
          if (iVar3 - 1U < 0x20) {
            *(int *)(param_2 + 0x6c) = *(int *)(PTR_DAT_00802c54 + 0x4678) + -0x214 + iVar3 * 0x214;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    iVar4 = *(int *)(param_2 + 0x6c);
    if (iVar4 != 0) {
      *(int *)(iVar2 + 0x10d4) = iVar4;
      *(ushort *)(iVar4 + 0x210) = *(ushort *)(iVar4 + 0x210) | 2;
      FUN_00452a60(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    return 0;
  }
  return 1;
}

