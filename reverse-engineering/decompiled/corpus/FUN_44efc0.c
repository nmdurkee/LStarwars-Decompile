/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44efc0; label: FUN_0044efc0
 */

undefined4
FUN_0044efc0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = 0;
  uVar5 = 0xffffffff;
  bVar1 = true;
  if (param_6 != 0) {
    if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
      iVar4 = **(int **)(param_3 + 0xd0);
    }
    if ((param_5 != 0) && (iVar6 = 0, 0 < param_5)) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"character=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"keep_out=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"FALSE");
            if (iVar2 == 0) {
              bVar1 = false;
            }
          }
          else {
            iVar2 = FUN_004f8b10(iVar2 + 9,&DAT_00757ebc);
            uVar5 = (uint)(iVar2 == 0);
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 10), piVar3 == (int *)0x0)) {
          iVar4 = 0;
        }
        else {
          iVar4 = *piVar3;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
    }
    if (iVar4 != 0) {
      if (bVar1) {
        *(uint *)(iVar4 + 0xe20) = *(uint *)(iVar4 + 0xe20) | 0x10000;
        *(undefined4 *)(iVar4 + 0xd3c) = 0x3f800000;
        if (uVar5 != 0xffffffff) {
          *(uint *)(iVar4 + 0xeec) =
               *(uint *)(iVar4 + 0xeec) ^ (uVar5 << 4 ^ *(uint *)(iVar4 + 0xeec)) & 0x10;
          return 1;
        }
      }
      else {
        *(uint *)(iVar4 + 0xe20) = *(uint *)(iVar4 + 0xe20) & 0xfffeffff;
        *(uint *)(iVar4 + 0xeec) = *(uint *)(iVar4 + 0xeec) & 0xffffffef;
        *(undefined4 *)(iVar4 + 0xd3c) = 0;
      }
    }
  }
  return 1;
}

