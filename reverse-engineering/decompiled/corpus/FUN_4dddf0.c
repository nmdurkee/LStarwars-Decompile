/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4dddf0; label: FUN_004dddf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dddf0(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00882aa8;
  do {
    FUN_00558970(*(undefined4 *)*puVar1);
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x882ac0);
  _DAT_00882ba8 = 0;
  DAT_008894a8 = 1;
  FUN_004ddcf0();
  return;
}

