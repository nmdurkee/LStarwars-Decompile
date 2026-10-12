/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4ddcf0; label: FUN_004ddcf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ddcf0(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    while( true ) {
      while( true ) {
        iVar1 = FUN_0054fa60();
        (&DAT_00889490)[uVar2] = iVar1 / 0x5556;
        if (uVar2 != 0) break;
        uVar2 = 1;
      }
      if (uVar2 == 1) break;
      if (1 < uVar2) {
        _DAT_00889498 = (3 - DAT_00889494) - DAT_00889490;
        return;
      }
    }
  } while (iVar1 / 0x5556 == DAT_00889490);
  _DAT_00889498 = (3 - DAT_00889494) - DAT_00889490;
  return;
}

