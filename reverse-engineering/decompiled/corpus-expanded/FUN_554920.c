/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554920; label: FUN_00554920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_00554920(int *param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (-1 < param_2) {
    bVar1 = *(byte *)(*param_1 + 0xa4);
    if (param_2 <= (int)(uint)bVar1) {
      if (1 < bVar1) {
        uVar2 = FUN_006e6b90(s_100__Complete_008025c4,10);
        FUN_004f2860(uVar2);
        FUN_004f1e80(s_100__Complete_008025c4,"%% Complete");
        return s_100__Complete_008025c4;
      }
      if (bVar1 != 0) {
        FUN_004f1f10(s_100__Complete_008025c4,"100%% Complete");
        return s_100__Complete_008025c4;
      }
      FUN_004f1f10(s_100__Complete_008025c4,&DAT_007516c0);
      return s_100__Complete_008025c4;
    }
  }
  return (char *)0x0;
}

