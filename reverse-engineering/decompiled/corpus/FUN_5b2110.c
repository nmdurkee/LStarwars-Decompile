/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b2110; label: FUN_005b2110
 */

int FUN_005b2110(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_0095e41c != 0) && (iVar2 = 0, 0 < DAT_0095e420)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(iVar3 + 4 + DAT_0095e41c),param_2);
      if (iVar1 == 0) {
        return DAT_0095e41c + iVar2 * 0xc;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar2 < DAT_0095e420);
  }
  iVar2 = FUN_005d0690(param_1,param_2);
  return iVar2;
}

