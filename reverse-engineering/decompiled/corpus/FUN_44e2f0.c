/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44e2f0; label: FUN_0044e2f0
 */

undefined4
FUN_0044e2f0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  float10 fVar2;
  undefined1 local_c [12];
  
  if ((param_3 == 0) || (*(int *)(param_3 + 0xd0) == 0)) {
    return 1;
  }
  if (param_6 == 0) {
    iVar1 = *(int *)(param_2 + 0x6c);
    if (iVar1 != 0) {
      fVar2 = (float10)FUN_005b3cf0(*(int *)(param_3 + 0xd0) + 0x5c,iVar1 + 4,local_c);
      if ((float)fVar2 < *(float *)(iVar1 + 0x14)) {
        *(undefined4 *)(param_3 + 0x158) = 0;
        *(undefined4 *)(param_3 + 0x15c) = 0;
        *(undefined4 *)(param_3 + 0x160) = 0;
        *(undefined4 *)(param_3 + 0x164) = 0;
        *(undefined4 *)(param_3 + 0x168) = 0;
        *(undefined4 *)(param_3 + 0x16c) = 0;
        FUN_0051a7c0(param_3,*(undefined4 *)(*(int *)(param_1 + 0x10) + 8));
        if ((*(byte *)(iVar1 + 0x2b) & 1) == 0) {
          return 1;
        }
        FUN_0051b890(param_3,*(int *)(param_3 + 0xd0) + 0x5c,
                     *(int *)(*(int *)(param_3 + 0x158) + 0x80) +
                     (uint)*(ushort *)(iVar1 + 0x2c) * 0x24,0);
        return 1;
      }
      FUN_0052fcb0(param_3,iVar1 + 4,0,param_2 + 0x84,1,*(undefined4 *)(param_3 + 0x180));
    }
  }
  else if (((param_1 != 0) && (*(int *)(param_3 + 0x158) != 0)) && (*(int *)(param_3 + 0x15c) != 0))
  {
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 8);
    if (*(int *)(param_3 + 0x158) != iVar1) {
      FUN_0051a7c0(param_3,iVar1);
      FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),*(undefined4 *)(param_3 + 0xd0),
                   param_3,0xff,1);
    }
    return 1;
  }
  return 0;
}

