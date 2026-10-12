/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a05b0; label: FUN_005a05b0
 */

int FUN_005a05b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00552670(param_1,param_2,0x10);
  if ((iVar1 != 0) && (DAT_00956618 != 0)) {
    uVar2 = FUN_00552670(param_1,param_2,DAT_00956618 * 4);
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
  }
  return iVar1;
}

