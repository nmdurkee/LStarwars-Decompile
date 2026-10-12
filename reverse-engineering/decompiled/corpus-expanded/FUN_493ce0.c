/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x493ce0; label: FUN_00493ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493ce0(void)

{
  int iVar1;
  
  iVar1 = FUN_00423480(*DAT_009253ac,DAT_009253ac[1],_DAT_00925018);
  if (DAT_007f396d < '\0') {
    if (iVar1 == 0) {
      FUN_00509ab0();
      return;
    }
  }
  else {
    if (iVar1 == 3) {
      DAT_007f396c = DAT_007f396d;
      DAT_007f396d = 0xff;
      FUN_0055c560();
      return;
    }
    if (iVar1 == 2) {
      FUN_004f47f0((int)DAT_007f396d,0xffffffff);
      DAT_007f396d = 0xff;
      FUN_0055c560();
      return;
    }
  }
  return;
}

