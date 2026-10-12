/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x65a510; label: FUN_0065a510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065a510(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0292fe18;
  do {
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + 0xb5;
  } while ((int)puVar1 < 0x293b318);
  DAT_02947c10 = 0;
  DAT_02962108 = 0;
  DAT_02961f80 = 0;
  DAT_0292fd80 = 0;
  DAT_02961f84 = 0;
  DAT_0292fd84 = 0;
  _DAT_02961f88 = 0;
  _DAT_0292fd88 = 0;
  _DAT_02961f8c = 0;
  _DAT_0292fd8c = 0;
  _DAT_02961f90 = 0;
  _DAT_0292fd90 = 0;
  _DAT_02961f94 = 0;
  _DAT_0292fd94 = 0;
  _DAT_02961f98 = 0;
  _DAT_0292fd98 = 0;
  _DAT_02961f9c = 0;
  _DAT_0292fd9c = 0;
  return;
}

