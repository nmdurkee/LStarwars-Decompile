/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a8e30; label: FUN_004a8e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8e30(int param_1,undefined4 *param_2,float param_3)

{
  float10 fVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    if (*(char *)(param_1 + 0x7b5) != '@') {
      *(undefined4 *)(param_1 + 0x77c) = 0;
    }
    *(undefined1 *)(param_1 + 0x7b5) = 0x40;
    *(undefined4 *)(param_1 + 0x748) = *param_2;
    *(undefined4 *)(param_1 + 0x74c) = param_2[1];
    *(undefined4 *)(param_1 + 0x750) = param_2[2];
  }
  if (*(char *)(param_1 + 0x7b5) == '@') {
    FUN_004a8b60(param_1,param_1 + 0x748);
    *(float *)(param_1 + 0x77c) = *(float *)(param_1 + 0x77c) + _DAT_00925018;
    fVar1 = (float10)FUN_005b3c50(param_1 + 0x80,param_1 + 0x748,0);
    if (((float10)param_3 * (float10)1.5 < fVar1) && (3.0 < *(float *)(param_1 + 0x77c))) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      FUN_0049ad40(param_1);
    }
  }
  return;
}

