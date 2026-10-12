/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627820; label: FUN_00627820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00627820(void)

{
  if (DAT_02912e5c != 0) {
    FUN_005d53a0(DAT_02912e74);
    for (; DAT_02912e60 != (undefined4 *)0x0; DAT_02912e60 = (undefined4 *)*DAT_02912e60) {
      if ((code *)DAT_02912e60[4] != (code *)0x0) {
        (*(code *)DAT_02912e60[4])();
      }
    }
    if (DAT_02912e6c != 0) {
      FUN_00624220(DAT_02912e6c);
      DAT_02912e6c = 0;
    }
    if (DAT_02912e70 != 0) {
      FUN_00624220(DAT_02912e70);
      DAT_02912e70 = 0;
    }
    DAT_02912e60 = (undefined4 *)0x0;
    DAT_02912e64 = 0;
    DAT_02912e5c = 0;
  }
  return;
}

