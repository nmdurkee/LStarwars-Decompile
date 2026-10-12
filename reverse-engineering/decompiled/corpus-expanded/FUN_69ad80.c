/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69ad80; label: FUN_0069ad80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069ad80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076eff8;
  if (*(char *)(in_ECX + 0x10) == '\0') {
    FUN_0069a250();
    FUN_0069a330();
    return;
  }
  if (DAT_02973a00 != 0) {
    FUN_004ffa90(DAT_02973a00);
    DAT_02973a00 = 0;
  }
  FUN_0069aac0();
  FUN_0069a330();
  return;
}

