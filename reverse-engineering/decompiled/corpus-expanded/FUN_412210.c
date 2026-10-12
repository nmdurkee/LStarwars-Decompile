/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x412210; label: FUN_00412210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00412210(int param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x511c);
  fVar2 = *param_2;
  while (fVar2 != 0.0) {
    if ((*(float *)(iVar3 + 0x63724) < *param_2) &&
       (*param_2 < *(float *)(iVar3 + 0x63720) != (*param_2 == *(float *)(iVar3 + 0x63720)))) {
      *(float *)(iVar3 + 0x6372c) = param_2[1];
    }
    pfVar1 = param_2 + 2;
    param_2 = param_2 + 2;
    fVar2 = *pfVar1;
  }
  if (*(float *)(iVar3 + 0x6372c) <= *(float *)(iVar3 + 0x63730)) {
    if ((*(float *)(iVar3 + 0x63730) <= *(float *)(iVar3 + 0x6372c)) ||
       (fVar2 = *(float *)(iVar3 + 0x63730) - _DAT_007f1644 * _DAT_00925018,
       *(float *)(iVar3 + 0x63730) = fVar2, *(float *)(iVar3 + 0x6372c) <= fVar2))
    goto LAB_004122fc;
  }
  else {
    fVar2 = _DAT_007f1644 * _DAT_00925018 + *(float *)(iVar3 + 0x63730);
    *(float *)(iVar3 + 0x63730) = fVar2;
    if (fVar2 <= *(float *)(iVar3 + 0x6372c)) goto LAB_004122fc;
  }
  *(undefined4 *)(iVar3 + 0x63730) = *(undefined4 *)(iVar3 + 0x6372c);
LAB_004122fc:
  *(float *)(**(int **)(param_1 + 0x2988) + 0x70) = *(float *)(iVar3 + 0x63730) * 20.0;
  if ((*(int *)(param_1 + 0x128) == DAT_0087b0f8) &&
     (*(float *)(**(int **)(param_1 + 0x2988) + 0x70) != 0.0)) {
    *(float *)(iVar3 + 0x63728) = *(float *)(**(int **)(param_1 + 0x2988) + 0x70) / 11.0;
    return;
  }
  return;
}

