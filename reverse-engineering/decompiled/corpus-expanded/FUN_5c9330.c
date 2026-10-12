/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9330; label: FUN_005c9330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c9330(byte *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*param_1 & 1) == 0) {
    FUN_005b44e0(param_3);
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(iVar1 + 0xc) == 0) {
      fVar3 = (float10)*(float *)(*(int *)(param_1 + 4) + 0xc);
    }
    else {
      fVar3 = (float10)FUN_005c91c0(*(undefined4 *)(iVar1 + 0xc),param_2);
    }
    local_24 = (float)fVar3;
    if (*(int *)(iVar1 + 0x10) == 0) {
      fVar3 = (float10)*(float *)(*(int *)(param_1 + 4) + 0x10);
    }
    else {
      fVar3 = (float10)FUN_005c91c0(*(undefined4 *)(iVar1 + 0x10),param_2);
    }
    local_20 = (float)fVar3;
    if (*(int *)(iVar1 + 0x14) == 0) {
      fVar3 = (float10)*(float *)(*(int *)(param_1 + 4) + 0x14);
    }
    else {
      fVar3 = (float10)FUN_005c91c0(*(undefined4 *)(iVar1 + 0x14),param_2);
    }
    local_1c = (float)fVar3;
    local_c = FUN_006e6b90();
    local_8 = FUN_006e6b90();
    local_4 = FUN_006e6b90();
    thunk_FUN_005b5300(param_3,&local_c);
  }
  if ((*param_1 & 8) != 0) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(iVar1 + 0x18) == 0) {
      fVar3 = (float10)*(float *)(*(int *)(param_1 + 4) + 0x18);
    }
    else {
      fVar3 = (float10)FUN_005c91c0(*(undefined4 *)(iVar1 + 0x18),param_2);
    }
    local_24 = (float)fVar3;
    if (*(int *)(iVar1 + 0x1c) == 0) {
      fVar3 = (float10)*(float *)(*(int *)(param_1 + 4) + 0x1c);
    }
    else {
      fVar3 = (float10)FUN_005c91c0(*(undefined4 *)(iVar1 + 0x1c),param_2);
    }
    local_20 = (float)fVar3;
    if (*(int *)(iVar1 + 0x20) == 0) {
      fVar3 = (float10)*(float *)(*(int *)(param_1 + 4) + 0x20);
    }
    else {
      fVar3 = (float10)FUN_005c91c0(*(undefined4 *)(iVar1 + 0x20),param_2);
    }
    local_1c = (float)fVar3;
    thunk_FUN_005b4c30(param_3,&local_24);
  }
  piVar2 = *(int **)(param_1 + 8);
  if (*piVar2 == 0) {
    fVar3 = (float10)**(float **)(param_1 + 4);
  }
  else {
    fVar3 = (float10)FUN_005c91c0(*piVar2,param_2);
  }
  local_18 = (float)fVar3;
  if (piVar2[1] == 0) {
    fVar3 = (float10)*(float *)(*(int *)(param_1 + 4) + 4);
  }
  else {
    fVar3 = (float10)FUN_005c91c0(piVar2[1],param_2);
  }
  local_14 = (float)fVar3;
  if (piVar2[2] == 0) {
    fVar3 = (float10)*(float *)(*(int *)(param_1 + 4) + 8);
  }
  else {
    fVar3 = (float10)FUN_005c91c0(piVar2[2],param_2);
  }
  local_10 = (float)fVar3;
  FUN_005b4900(param_3,&local_18);
  *(float *)(param_3 + 8) = -*(float *)(param_3 + 8);
  *(float *)(param_3 + 0x18) = -*(float *)(param_3 + 0x18);
  *(float *)(param_3 + 0x20) = -*(float *)(param_3 + 0x20);
  *(float *)(param_3 + 0x24) = -*(float *)(param_3 + 0x24);
  *(float *)(param_3 + 0x2c) = -*(float *)(param_3 + 0x2c);
  *(float *)(param_3 + 0x38) = -*(float *)(param_3 + 0x38);
  return;
}

