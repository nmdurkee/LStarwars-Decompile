/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e4670; label: FUN_006e4670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e4670(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  _DAT_0297bea0 =
       (**(code **)(*DAT_029765cc + 100))
                 (DAT_029765cc,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

