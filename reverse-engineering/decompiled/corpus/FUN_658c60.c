/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x658c60; label: FUN_00658c60
 */

undefined4 FUN_00658c60(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_02920aac) {
    iVar2 = DAT_02961fe4;
    do {
      if (((*(uint *)(iVar2 + 4 + iVar3 * 8) & param_4 & 0xff) != 0) &&
         (iVar1 = FUN_006588e0(*(undefined4 *)(iVar2 + iVar3 * 8),param_1,param_2,param_3,param_4),
         iVar2 = DAT_02961fe4, iVar1 != 0)) {
        return *(undefined4 *)(DAT_02961fe4 + iVar3 * 8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_02920aac);
  }
  return 0xffffffff;
}

