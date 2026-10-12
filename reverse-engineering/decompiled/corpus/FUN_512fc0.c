/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x512fc0; label: FUN_00512fc0
 */

int FUN_00512fc0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f1440(param_2 + 0x10);
  if (param_1 != 0) {
    for (; iVar1 != 0; iVar1 = FUN_004f1460(param_2 + 0x10,iVar1)) {
      iVar2 = FUN_004f8b10(param_1,*(undefined4 *)(iVar1 + 0x18));
      if (iVar2 == 0) {
        return iVar1;
      }
    }
  }
  return 0;
}

