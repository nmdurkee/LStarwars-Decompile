/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58dfa0; label: FUN_0058dfa0
 */

undefined4 FUN_0058dfa0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int local_c [3];
  
  iVar2 = *(int *)(DAT_029130e4 + 8);
  iVar3 = 0;
  iVar1 = 0;
  pbVar4 = PTR_PTR_007fbec8 + 4;
  do {
    if (iVar2 <= iVar1) break;
    if (((*pbVar4 & 8) != 0) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar1 * 4) != 0)) {
      local_c[iVar3] = iVar1;
      iVar3 = iVar3 + 1;
    }
    iVar1 = iVar1 + 1;
    pbVar4 = pbVar4 + 8;
  } while (iVar3 < 3);
  if (iVar3 != 0) {
    if (1 < iVar3) {
      do {
        iVar2 = FUN_0054fa60();
        local_c[0] = local_c[iVar2 / ((int)(0xffff / (longlong)iVar3) + 1)];
      } while (local_c[0] == *(short *)(param_1 + 0xe10));
    }
    *(short *)(param_1 + 0xe10) = (short)local_c[0];
    *(short *)(param_1 + 0x7aa) = (short)local_c[0];
    return 1;
  }
  return 0;
}

