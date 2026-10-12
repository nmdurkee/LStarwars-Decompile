/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cd080; label: FUN_004cd080
 */

void FUN_004cd080(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (((param_1 != 0) && (iVar3 = *(int *)(param_1 + 0x5078), iVar3 != 0)) &&
     (iVar4 = 0, 0 < *(int *)(param_1 + 0x507c))) {
    do {
      FUN_004ccf90();
      if ((param_3 != 0) && (iVar4 < 0x20)) {
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        *(byte *)(iVar3 + 0x3c) =
             *(byte *)(iVar3 + 0x3c) ^
             (((*(uint *)(param_3 + 4 + iVar1 * 4) & uVar2) != 0) * '\x02' ^ *(byte *)(iVar3 + 0x3c)
             ) & 2;
        *(byte *)(iVar3 + 0x3c) =
             ((*(uint *)(param_3 + iVar1 * 4) & uVar2) != 0 ^ *(byte *)(iVar3 + 0x3c)) & 1 ^
             *(byte *)(iVar3 + 0x3c);
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x70;
    } while (iVar4 < *(int *)(param_1 + 0x507c));
  }
  return;
}

