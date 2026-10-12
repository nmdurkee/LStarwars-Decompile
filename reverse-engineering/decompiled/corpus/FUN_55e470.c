/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55e470; label: FUN_0055e470
 */

bool FUN_0055e470(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 * 0x4c + 4 + DAT_0093b274);
  if ((undefined *)(uVar1 & 0x1000010) == &DAT_01000010) {
    return false;
  }
  return (uVar1 & 0x40088) != 0;
}

