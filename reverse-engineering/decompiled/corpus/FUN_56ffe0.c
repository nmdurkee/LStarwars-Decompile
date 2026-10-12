/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56ffe0; label: FUN_0056ffe0
 */

int FUN_0056ffe0(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar1 = **(int **)(param_1 + 0x50b8);
  iVar2 = 0;
  if ((iVar1 != 0) && (iVar4 = (*(int **)(param_1 + 0x50b8))[2], 0 < iVar4)) {
    pbVar3 = (byte *)(iVar1 + 0x25);
    do {
      iVar2 = iVar2 + (uint)*(ushort *)(*(int *)PTR_PTR_008033b0 + 0x12 + (uint)*pbVar3 * 0x38);
      pbVar3 = pbVar3 + 0x2c;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return iVar2;
}

