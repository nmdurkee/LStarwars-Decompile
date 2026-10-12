/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dddf0; label: FUN_004dddf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

