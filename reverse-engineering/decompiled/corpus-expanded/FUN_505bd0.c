/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505bd0; label: FUN_00505bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00505bd0(int param_1,int param_2,undefined4 param_3,int param_4,uint *param_5)

{
  int iVar1;
  float fVar2;
  char *in_EAX;
  undefined4 uVar3;
  uint *in_ECX;
  
  if (param_2 != 0) {
    *(int *)(param_1 + 0x58) = param_2;
    *(int *)(param_1 + 0x5c) = param_2;
    if (in_EAX != (char *)0x0) {
      _sprintf((char *)(param_1 + 8),in_EAX);
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      uVar3 = FUN_00500bf0();
      *(undefined4 *)(param_1 + 0x9c) = uVar3;
    }
    if (*(int *)(param_2 + 0x14) != 0) {
      uVar3 = FUN_005020e0(param_3);
      *(undefined4 *)(param_1 + 0xa0) = uVar3;
    }
    if (*(int *)(param_2 + 0x18) != 0) {
      uVar3 = FUN_00502a60();
      *(undefined4 *)(param_1 + 0xa4) = uVar3;
    }
    if (*(int *)(param_2 + 0x1c) != 0) {
      uVar3 = FUN_00501400(*(int *)(param_2 + 0x1c));
      *(undefined4 *)(param_1 + 0xa8) = uVar3;
    }
    if ((*(int *)(param_2 + 0x24) != 0) && (param_4 != 0)) {
      uVar3 = FUN_00503730(param_4);
      *(undefined4 *)(param_1 + 0xac) = uVar3;
    }
    iVar1 = *(int *)(param_1 + 0x58);
    if (*(int *)(iVar1 + 0x20) == 0) {
      fVar2 = 0.0;
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(undefined4 *)(param_1 + 100) = 0;
    }
    else {
      *(float *)(param_1 + 0x60) =
           ((*(float **)(iVar1 + 0x20))[3] + **(float **)(iVar1 + 0x20)) * 0.5;
      *(float *)(param_1 + 100) =
           (*(float *)(*(int *)(iVar1 + 0x20) + 0x10) + *(float *)(*(int *)(iVar1 + 0x20) + 4)) *
           0.5;
      fVar2 = (*(float *)(*(int *)(iVar1 + 0x20) + 0x14) + *(float *)(*(int *)(iVar1 + 0x20) + 8)) *
              0.5;
    }
    *(float *)(param_1 + 0x68) = fVar2;
    *(undefined4 *)(param_1 + 0x98) = 0x3f800000;
    if ((param_5 != (uint *)0x0) && (*param_5 < *in_ECX)) {
      FUN_004fff00();
      return;
    }
  }
  return;
}

