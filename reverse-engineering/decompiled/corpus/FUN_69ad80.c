/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69ad80; label: FUN_0069ad80
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

