/* Ghidra pseudocode, not original source.
 * ev_573fcacabc8e68ea03635b0f8aa232ed45a87b6cc51fa6af4ed20e3c9ee5dc27
 * Entry: 0x5d1860; label: FUN_005d1860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d1860(void)

{
  undefined4 *puVar1;
  
  DAT_009738d4 = 0;
  puVar1 = &DAT_0096d9e4;
  do {
    *puVar1 = puVar1 + 2;
    puVar1 = puVar1 + 3;
  } while ((int)puVar1 < 0x96dcd8);
  _DAT_0096dcd8 = 0;
  DAT_009738dc = &DAT_0096d9e0;
  DAT_009738d8 = 0;
  DAT_00963e04 = 0;
  DAT_0095fbbc = 0;
  DAT_0096e534 = 0;
  DAT_0096d8f4 = 0;
  DAT_0096e56c = 0;
  return;
}

