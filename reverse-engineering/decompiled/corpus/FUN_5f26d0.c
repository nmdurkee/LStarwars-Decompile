/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f26d0; label: FUN_005f26d0
 */

void FUN_005f26d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *in_ECX;
  
  if (param_1 != 0) {
    FUN_005e7f40(param_1,param_2,param_3);
    FUN_005e7f40(param_1,param_2,param_3);
    *(undefined4 *)(in_ECX + 0x158) = 0x3e99999a;
    *(undefined1 **)(in_ECX + 0x150) = in_ECX + 0x10;
    *(undefined1 **)(in_ECX + 0x154) = in_ECX + 0xb0;
    *(undefined4 *)(in_ECX + 0x15c) = 0xbf800000;
    *in_ECX = 1;
    in_ECX[1] = 1;
  }
  return;
}

