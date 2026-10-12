/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64fd40; label: FUN_0064fd40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0064fd40(undefined4 param_1,int param_2)

{
  _DAT_02920a68 = _DAT_02920a68 + 5;
  if (DAT_029209a0 != 0) {
    FUN_0062a400(DAT_029209a0,param_1,param_2);
    return 0;
  }
  FUN_0064f7e0(param_2);
  FUN_00644000(0x3f800000);
  return *(uint *)(param_2 + 0x78) >> 0xb & 1;
}

