/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f2740; label: FUN_005f2740
 */

uint FUN_005f2740(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  uint uVar1;
  char *in_ECX;
  
  if ((*in_ECX == '\0') || (in_ECX[1] == '\0')) {
    uVar1 = in_EAX & 0xffffff00;
  }
  else {
    if (*(char *)(*(int *)(in_ECX + 0x154) + 0x10) == '\0') {
      FUN_005e8190(&DAT_0080b708,&DAT_0080b808);
    }
    *(int *)(in_ECX + 0x164) = *(int *)(in_ECX + 0x164) + 1;
    uVar1 = FUN_005c5470(param_1,param_2);
    if ((char)uVar1 != '\0') {
      *(int *)(in_ECX + 0x160) = *(int *)(in_ECX + 0x160) + 1;
      return uVar1;
    }
  }
  return uVar1;
}

