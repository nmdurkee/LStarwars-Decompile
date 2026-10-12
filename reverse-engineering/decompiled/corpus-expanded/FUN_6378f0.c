/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x6378f0; label: FUN_006378f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006378f0(void)

{
  if ((DAT_029139c0 != 0) && (DAT_0291389c != 0)) {
    FUN_004ef660(DAT_029139cc * 0x4600 + _DAT_029138b0,DAT_0291389c + 4,0x4600);
    FUN_00620fa0(DAT_029134bc + DAT_029139cc * 0xc,0,0);
    *(undefined4 *)(DAT_029135e4 + DAT_029139cc * 4) = DAT_02913824;
    *(undefined4 *)(DAT_029134e8 + DAT_029139cc * 4) = DAT_029139bc;
    *(undefined4 *)(DAT_029138c0 + DAT_029139cc * 4) = DAT_02913818;
    DAT_029139cc = DAT_029139cc + 1 & DAT_029139c0 - 1U;
    DAT_029139c4 = DAT_029139c4 + 1;
    if (DAT_029139c0 + -1 <= DAT_029139c4) {
      DAT_029139c4 = DAT_029139c0 + -1;
    }
    DAT_029139c8 = DAT_029139c4;
    *(byte *)(DAT_029137c4 + 0x11) = *(byte *)(DAT_029137c4 + 0x11) & 0xfd;
    *(byte *)(DAT_02913508 + 0x11) = *(byte *)(DAT_02913508 + 0x11) | 2;
  }
  return;
}

