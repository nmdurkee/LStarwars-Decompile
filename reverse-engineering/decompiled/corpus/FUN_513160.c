/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x513160; label: FUN_00513160
 */

undefined4 FUN_00513160(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != 0) {
    for (iVar1 = FUN_004f1440(param_1 + 0x1c); iVar1 != 0;
        iVar1 = FUN_004f1460(param_1 + 0x1c,iVar1)) {
      if (iVar4 == param_2) {
        return *(undefined4 *)(iVar1 + 8);
      }
      iVar4 = iVar4 + 1;
    }
  }
  iVar1 = FUN_004f1440(&DAT_00921ee8);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 != 0) {
      for (iVar2 = FUN_004f1440(param_1 + 0x1c); iVar2 != 0;
          iVar2 = FUN_004f1460(param_1 + 0x1c,iVar2)) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar2 + 8));
        if (iVar3 == 0) goto LAB_00513204;
      }
    }
    if (iVar4 == param_2) {
      return *(undefined4 *)(iVar1 + 8);
    }
    iVar4 = iVar4 + 1;
LAB_00513204:
    iVar1 = FUN_004f1460(&DAT_00921ee8,iVar1);
  } while( true );
}

