/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x41f8f0; label: FUN_0041f8f0
 */

int FUN_0041f8f0(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1 < 0x154) && (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_1 * 2) != -1)) {
    iVar1 = FUN_0055c9f0();
    if (iVar1 == 0) {
      return 0;
    }
    FUN_0041c7c0(iVar1,param_1,param_2);
    return iVar1;
  }
  return 0;
}

