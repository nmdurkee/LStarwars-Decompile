/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a1b10; label: FUN_005a1b10
 */

undefined4
FUN_005a1b10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c [12];
  
  if (param_1 != 0) {
    iVar1 = FUN_0055acd0(param_2,local_c,param_3,1,param_7,param_8,param_9);
    if (iVar1 != 0) {
      uVar2 = FUN_005a0810(param_1,local_c,param_4,param_5,param_6);
      return uVar2;
    }
  }
  return 0;
}

