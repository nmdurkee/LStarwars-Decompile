/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50ee70; label: FUN_0050ee70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050ee70(void)

{
  char cVar1;
  
  cVar1 = FUN_006e2b40();
  if (cVar1 != '\0') {
    DAT_00800940 = DAT_00800954;
    FUN_00509230();
    FUN_006e3940(1);
    FUN_00509ab0();
    FUN_00509830(0x403,0,0xffffffff);
    return;
  }
  cVar1 = FUN_00509180();
  if (cVar1 == '\0') {
    DAT_00800940 = DAT_00800958;
  }
  else {
    DAT_00800940 = DAT_00800954;
    FUN_00509230();
    if (DAT_008264c8 != DAT_008264c7) {
      FUN_00509ab0();
      FUN_00509830(0x404,0,0xffffffff);
      return;
    }
  }
  FUN_00509ab0();
  return;
}

