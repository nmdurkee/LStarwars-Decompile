/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69b1c0; label: FUN_0069b1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069b1c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076eff8;
  if (*(char *)(in_ECX + 0x10) == '\0') {
    FUN_0069a250();
  }
  else {
    if (DAT_02973a00 != 0) {
      FUN_004ffa90(DAT_02973a00);
      DAT_02973a00 = 0;
    }
    FUN_0069aac0();
  }
  FUN_0069a330();
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

