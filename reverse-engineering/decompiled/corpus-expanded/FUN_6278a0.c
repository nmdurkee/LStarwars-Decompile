/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x6278a0; label: FUN_006278a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006278a0(void)

{
  if (DAT_02912e6c != 0) {
    FUN_005d0880(2);
    FUN_005d0a40(1);
    FUN_005d0fb0(DAT_009738b8);
    FUN_005d0fe0(DAT_009738b8,_DAT_0080f510,_DAT_0080f510);
    FUN_00626b50(DAT_02912e6c);
    FUN_005d0a70();
    FUN_005d08c0();
    return;
  }
  return;
}

