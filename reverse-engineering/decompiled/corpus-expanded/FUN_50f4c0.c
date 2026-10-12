/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50f4c0; label: FUN_0050f4c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050f4c0(undefined4 param_1,float param_2,float param_3,undefined4 param_4,float param_5,
                 float param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,uint param_12)

{
  if (DAT_00921d78 != 0) {
    FUN_0050d1c0(param_1,param_5 * 0.015 + param_2,param_3 - param_6 * 0.015,param_4,param_5,param_6
                 ,param_7,param_8,0,0,0,param_12 >> 2 & 0x3f);
  }
  FUN_0050c780(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12);
  return;
}

