/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x6378f0; label: FUN_006378f0
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

