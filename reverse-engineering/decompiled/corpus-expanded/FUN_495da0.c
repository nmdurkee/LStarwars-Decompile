/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x495da0; label: FUN_00495da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00495da0(int param_1)

{
  if (DAT_00921d24 == 0) {
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880820 * 4),_DAT_0095137c,
                 *(float *)(param_1 + 0x98) - _DAT_00800994 * 1.5,0x3f800000,_DAT_0080098c,
                 _DAT_0080098c,_DAT_0080098c,DAT_00951378,DAT_007facbc,DAT_007facbd,DAT_0087b728,
                 0x3fd9999a,1,0,0,_DAT_00921d60);
  }
  FUN_00574de0(param_1,*(undefined4 *)(DAT_00926c20 + DAT_00880844 * 4));
  FUN_00574de0(param_1,*(undefined4 *)(DAT_00926c20 + DAT_00880854 * 4));
  return;
}

