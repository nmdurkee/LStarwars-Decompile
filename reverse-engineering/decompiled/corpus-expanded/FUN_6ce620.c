/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6ce620; label: FUN_006ce620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ce620(int param_1,undefined4 param_2,float *param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  float10 fVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  
  FUN_006c5f80(param_2);
  switch(*(int *)(in_ECX + 0x14)) {
  case -0x7fffffff:
  case -0x7ffffffe:
    break;
  case -0x7ffffffd:
    fVar3 = *param_3 - *(float *)(param_1 + 0x10);
    fVar1 = param_3[1];
    fVar2 = param_3[2];
    fVar7 = (float10)fVar3;
    *(float *)(param_1 + 0x10) = (float)(fVar7 + (float10)*(float *)(param_1 + 0x10));
    *(float *)(param_1 + 0x14) = (fVar1 - *(float *)(param_1 + 0x14)) + *(float *)(param_1 + 0x14);
    *(float *)(param_1 + 0x18) = (fVar2 - *(float *)(param_1 + 0x18)) + *(float *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
    iVar4 = FUN_006c9e40(param_1,DAT_0081fe14);
    if (iVar4 == 0) {
      *(float *)(param_1 + 0x20) = (float)((float10)*(float *)(param_1 + 0x20) + fVar7);
      *(float *)(param_1 + 0x24) = (float)(extraout_ST1 + (float10)*(float *)(param_1 + 0x24));
      *(float *)(param_1 + 0x28) = (float)(extraout_ST0 + (float10)*(float *)(param_1 + 0x28));
      FUN_006c25c0((float *)(param_1 + 0x20));
      fVar7 = (float10)fVar3;
    }
    iVar4 = FUN_006c9e40(param_1,DAT_0081fe18);
    if (iVar4 == 0) {
      *(float *)(param_1 + 0x30) = (float)((float10)*(float *)(param_1 + 0x30) + fVar7);
      *(float *)(param_1 + 0x34) = (float)(extraout_ST1_00 + (float10)*(float *)(param_1 + 0x34));
      *(float *)(param_1 + 0x38) = (float)(extraout_ST0_00 + (float10)*(float *)(param_1 + 0x38));
      FUN_006c25c0((float *)(param_1 + 0x30));
    }
    if ((DAT_0081fe04 != 0) && (*(int *)(param_1 + 0x40) != 0)) {
      FUN_006c7480();
      return;
    }
    break;
  case -0x7ffffffc:
    *(float *)(param_1 + 0x20) = *param_3;
    *(float *)(param_1 + 0x24) = param_3[1];
    *(float *)(param_1 + 0x28) = param_3[2];
    *(float *)(param_1 + 0x2c) = param_3[3];
    goto LAB_006ce771;
  case -0x7ffffffb:
    *(float *)(param_1 + 0x30) = *param_3;
    *(float *)(param_1 + 0x34) = param_3[1];
    *(float *)(param_1 + 0x38) = param_3[2];
    *(float *)(param_1 + 0x3c) = param_3[3];
LAB_006ce771:
    if ((DAT_0081fe04 != 0) && (*(int *)(param_1 + 0x40) != 0)) {
      FUN_006c7480();
      return;
    }
    break;
  default:
    piVar6 = (int *)(*(int *)(in_ECX + 0x14) + param_1);
    uVar5 = FUN_006c6010(param_2,param_4);
    if (piVar6 != (int *)0x0) {
      if ((*(uint *)(in_ECX + 0x1c) & 0x40000000) != 0) {
        piVar6 = (int *)*piVar6;
      }
      FUN_004ef660(param_3,piVar6,uVar5);
    }
  }
  return;
}

