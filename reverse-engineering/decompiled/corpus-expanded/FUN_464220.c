/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464220; label: FUN_00464220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00464220(int param_1,int param_2,float param_3)

{
  float fVar1;
  float10 fVar2;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x3f19999a;
  }
  else if (*(int *)(param_1 + 0x14) == 1) {
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      FUN_00486940(*(undefined1 *)(param_2 + 0xba));
    }
    fVar1 = 0.0;
    if ((*(float *)(param_1 + 0x18) != 0.0) && (*(float *)(param_1 + 0x1c) != 0.0)) {
      fVar1 = *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
    }
    fVar2 = (float10)FUN_004850e0(fVar1);
    _DAT_0087a188 = (float)-fVar2;
    return;
  }
  return;
}

