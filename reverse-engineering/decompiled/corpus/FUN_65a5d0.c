/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x65a5d0; label: FUN_0065a5d0
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

