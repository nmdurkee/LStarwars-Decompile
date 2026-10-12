/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505b40; label: FUN_00505b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00505b40(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_1 != (int *)0x0) {
    if (1 < *param_1) {
      param_1[0x11] = param_2;
      param_1[0x12] = param_3;
    }
    if (param_1[5] != 0) {
      FUN_00501f60(param_2);
    }
    if ((param_1[6] != 0) && (DAT_00921398 != (code *)0x0)) {
      (*DAT_00921398)(param_1);
    }
    if (param_1[7] != 0) {
      FUN_00501640(param_1,param_4);
    }
    if ((param_1[9] != 0) && (param_3 != 0)) {
      FUN_005036a0(param_3);
    }
  }
  return;
}

