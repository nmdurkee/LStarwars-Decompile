/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b1460; label: FUN_006b1460
 */

undefined4 FUN_006b1460(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = **(int **)(param_1 + 0x68);
  piVar4 = *(int **)(*(int *)(param_1 + 4) + 0x1c);
  iVar2 = (int)(piVar4[*(int *)(param_1 + 0x28)] + (piVar4[*(int *)(param_1 + 0x28)] >> 0x1f & 3U))
          >> 2;
  if (*(int *)(param_1 + 0x28) == 0) {
    iVar3 = (int)(*piVar4 + (*piVar4 >> 0x1f & 3U)) >> 2;
    iVar5 = iVar3;
  }
  else {
    iVar3 = (int)(piVar4[*(int *)(param_1 + 0x2c)] + (piVar4[*(int *)(param_1 + 0x2c)] >> 0x1f & 3U)
                 ) >> 2;
    iVar5 = (int)(piVar4[*(int *)(param_1 + 0x24)] + (piVar4[*(int *)(param_1 + 0x24)] >> 0x1f & 3U)
                 ) >> 2;
  }
  iVar5 = (*(int *)(param_1 + 0x30) - iVar2) - iVar5;
  iVar3 = *(int *)(param_1 + 0x30) + iVar2 + iVar3;
  if ((iVar5 <= *(int *)(iVar1 + 0xac)) && (*(int *)(iVar1 + 0xac) < iVar3)) {
    return 1;
  }
  iVar3 = iVar3 / *(int *)(iVar1 + 8);
  iVar5 = iVar5 / *(int *)(iVar1 + 8);
  if (iVar5 < iVar3) {
    piVar4 = (int *)(*(int *)(iVar1 + 0xa0) + iVar5 * 4);
    do {
      if (*piVar4 != 0) {
        return 1;
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 < iVar3);
  }
  return 0;
}

