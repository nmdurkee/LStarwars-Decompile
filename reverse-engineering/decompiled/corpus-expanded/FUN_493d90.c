/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x493d90; label: FUN_00493d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493d90(void)

{
  int iVar1;
  
  iVar1 = FUN_00423480(*DAT_009253ac,DAT_009253ac[1],_DAT_00925018);
  if (iVar1 == 2) {
    FUN_00509ab0();
    return;
  }
  if (iVar1 == 3) {
    FUN_00509ab0();
    FUN_00509830(1,DAT_00924810 != 0,0xffffffff);
  }
  return;
}

