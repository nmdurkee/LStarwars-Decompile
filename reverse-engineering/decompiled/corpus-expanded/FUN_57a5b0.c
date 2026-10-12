/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57a5b0; label: FUN_0057a5b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057a5b0(int param_1)

{
  DAT_00950770 = 1;
  if ((DAT_00951b80 == 0) || (((*(byte *)(DAT_00951b80 + 100) & 0xe0) != 0 && (DAT_0093b2a4 != 0))))
  {
    DAT_00951b80 = FUN_00573520(*(undefined4 *)(param_1 + 300),0);
  }
  if (DAT_00951b80 == 0) {
    DAT_00951b80 = DAT_00951b94;
  }
  if (DAT_0093d84c != -1) {
    DAT_0093d850 = 1;
  }
  return;
}

