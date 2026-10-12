/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x592680; label: FUN_00592680
 */

int FUN_00592680(void)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 5;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 6;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 3;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 4;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 2;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 7;
  }
  iVar1 = FUN_004f8b10();
  return (-(uint)(iVar1 != 0) & 0xfffffff7) + 8;
}

