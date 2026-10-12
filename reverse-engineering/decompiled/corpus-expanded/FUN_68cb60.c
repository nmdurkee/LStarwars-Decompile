/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68cb60; label: FUN_0068cb60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0068cb60(undefined4 param_1,int param_2)

{
  _DAT_02962ad8 = _DAT_02962ad8 + 5;
  if (DAT_02947c18 != 0) {
    FUN_0062a400(DAT_02947c18,param_1,param_2);
    return 0;
  }
  FUN_0068c5f0(param_2);
  FUN_00661f60(0x3f800000);
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    *(undefined1 *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x2f4 + DAT_029620a4) = 1;
  }
  return *(uint *)(param_2 + 0x78) >> 0xb & 1;
}

