/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x63f810; label: FUN_0063f810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063f810(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (((DAT_029139c0 != 0) && (DAT_0291389c != 0)) && (DAT_029139c4 < DAT_029139c8)) {
    DAT_029139c4 = DAT_029139c4 + 1;
    DAT_029139cc = DAT_029139cc + 1 & DAT_029139c0 - 1U;
    FUN_004ef660(DAT_0291389c + 4,DAT_029139cc * 0x4600 + _DAT_029138b0,0x4600);
    FUN_00620f10(DAT_029134bc + DAT_029139cc * 0xc);
    iVar2 = DAT_029139c4;
    puVar1 = (undefined4 *)(DAT_029134bc + DAT_029139cc * 0xc);
    DAT_029134a4 = *puVar1;
    DAT_029134a8 = puVar1[1];
    DAT_029134ac = puVar1[2];
    DAT_02913824 = *(undefined4 *)(DAT_029135e4 + DAT_029139cc * 4);
    DAT_029139bc = *(undefined4 *)(DAT_029134e8 + DAT_029139cc * 4);
    DAT_02913818 = *(undefined4 *)(DAT_029138c0 + DAT_029139cc * 4);
    *(byte *)(DAT_029137c4 + 0x11) = *(byte *)(DAT_029137c4 + 0x11) & 0xfd;
    if (iVar2 == DAT_029139c8) {
      *(byte *)(DAT_02913508 + 0x11) = *(byte *)(DAT_02913508 + 0x11) | 2;
    }
    FUN_006382a0();
    return;
  }
  return;
}

