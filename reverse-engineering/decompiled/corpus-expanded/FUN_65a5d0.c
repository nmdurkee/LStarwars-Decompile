/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x65a5d0; label: FUN_0065a5d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065a5d0(int param_1)

{
  undefined4 *puVar1;
  
  if ((&DAT_0292fd80)[param_1] != 0) {
    (&DAT_0292fd80)[param_1] = 0;
  }
  puVar1 = &DAT_0292fe18;
  do {
    if (*(char *)(puVar1 + 0xb4) == param_1) {
      *puVar1 = 0xffffffff;
      DAT_02962108 = DAT_02962108 + -1;
    }
    puVar1 = puVar1 + 0xb5;
  } while ((int)puVar1 < 0x293b318);
  (&DAT_02961f80)[param_1] = 0;
  (&DAT_02947c7c)[param_1] = 0;
  return;
}

