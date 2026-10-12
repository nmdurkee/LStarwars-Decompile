/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bc860; label: FUN_006bc860
 */

void FUN_006bc860(int param_1)

{
  if ((*(byte *)(param_1 + 0x38) & 4) == 0) {
    FUN_006279f0(param_1);
    FUN_00624220(param_1);
    FUN_0061e5d0(1);
    if (param_1 == DAT_02973a7c) {
      DAT_02973a7c = 0;
    }
    if (param_1 == DAT_02973a80) {
      DAT_02973a80 = 0;
      return;
    }
    if ((DAT_02973a80 != 0) && (DAT_02973a7c == 0)) {
      DAT_02973a7c = DAT_02973a80;
    }
  }
  return;
}

