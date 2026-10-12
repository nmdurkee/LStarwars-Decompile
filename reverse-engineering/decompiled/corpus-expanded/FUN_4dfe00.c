/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dfe00; label: FUN_004dfe00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dfe00(int param_1)

{
  _DAT_00882b30 = 0;
  DAT_00882b34 = 0;
  _DAT_00882b38 = 0;
  _DAT_00882b3c = 0;
  _DAT_00882b40 = 0;
  if (DAT_00951b50 == 0) {
    _DAT_00882b30 = FUN_005ab050(DAT_0095df4c,"DookuFight",0,0);
    DAT_00882b34 = FUN_005aac00(DAT_0095df4c,"ShowHearts",0);
  }
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_00882b38,"dooku_force",1);
  return;
}

