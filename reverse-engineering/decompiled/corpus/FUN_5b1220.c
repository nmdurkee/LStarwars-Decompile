/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b1220; label: FUN_005b1220
 */

undefined4 FUN_005b1220(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *in_ECX;
  
  iVar1 = *param_1;
  if ((iVar1 != -1) && (in_ECX[iVar1 + 5] != 0)) {
    in_ECX[9] = iVar1;
    *in_ECX = param_2;
    return 1;
  }
  in_ECX[9] = 0xffffffff;
  return 0;
}

