/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x686750; label: FUN_00686750
 */

int FUN_00686750(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  DAT_0292fd0c = 0;
  DAT_02920aac = 0;
  iVar3 = DAT_029620a8;
  if (DAT_029620a8 == 0) {
    return 0;
  }
  do {
    iVar4 = (int)*(short *)(iVar3 + 0x182);
    local_4 = (int)*(short *)(iVar3 + 0x32a);
    iVar1 = *(int *)(iVar3 + 0x1c8);
    if (*(int *)(DAT_0296209c + iVar4 * 4) == 0) {
      FUN_00684400(&local_4);
      *(undefined2 *)(iVar3 + 0x32a) = 0xffff;
    }
    iVar2 = local_4;
    if (*(char *)(iVar3 + 0x184) != '\0') {
      iVar3 = FUN_00658d50(local_4,param_1,param_2,0x3f800000,3);
      if (iVar3 != 0) {
        *(int *)(DAT_0292fdc4 + DAT_0292fd0c * 8) = iVar2;
        *(uint *)(DAT_0292fdc4 + 4 + DAT_0292fd0c * 8) =
             (uint)*(byte *)(*(int *)(DAT_0296209c + iVar4 * 4) + 0x2f2);
        DAT_0292fd0c = DAT_0292fd0c + 1;
      }
      iVar3 = FUN_006588e0(iVar2,param_1,param_2,0x3f800000,3);
      if (iVar3 != 0) {
        *(int *)(DAT_02961fe4 + DAT_02920aac * 8) = iVar2;
        *(uint *)(DAT_02961fe4 + 4 + DAT_02920aac * 8) =
             (uint)*(byte *)(*(int *)(DAT_0296209c + iVar4 * 4) + 0x2f2);
        DAT_02920aac = DAT_02920aac + 1;
      }
    }
    iVar3 = iVar1;
  } while (iVar1 != 0);
  return DAT_02920aac + DAT_0292fd0c;
}

