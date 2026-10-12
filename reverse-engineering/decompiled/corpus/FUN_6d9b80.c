/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6d9b80; label: FUN_006d9b80
 */

void FUN_006d9b80(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_006d43e0(param_1,param_2,*(undefined4 *)(in_ECX + 0x6604));
  if ((iVar1 == 0) && (iVar1 = FUN_006d43e0(param_1,param_2,0xffffffff), iVar1 == 0)) {
    return;
  }
  FUN_006d45f0(iVar1,param_2,(int)*(short *)(iVar1 + 0x5e),0,0);
  return;
}

