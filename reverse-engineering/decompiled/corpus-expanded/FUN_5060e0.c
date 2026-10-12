/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x5060e0; label: FUN_005060e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005060e0(int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x58);
  FUN_005003b0(param_1);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(iVar2 + 8);
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xffffffbf;
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xfffffffd | 0x1000;
  DAT_009737dd = 1;
  if ((*(uint *)(param_1 + 0x88) & 0x40000) == 0) {
    if (*(int *)(iVar2 + 0x14) != 0) {
      FUN_00502740(param_1,*(undefined4 *)(param_1 + 0x90));
    }
    if (*(int *)(param_1 + 0xa4) == 0) goto LAB_005061a4;
    fVar1 = *(float *)(param_1 + 0x90);
  }
  else {
    if (*(int *)(iVar2 + 0x14) != 0) {
      FUN_00502740(param_1,*(float *)(*(int *)(param_1 + 0x58) + 8) - *(float *)(param_1 + 0x90));
    }
    if (*(int *)(param_1 + 0xa4) == 0) goto LAB_005061a4;
    fVar1 = *(float *)(*(int *)(param_1 + 0x58) + 8) - *(float *)(param_1 + 0x90);
  }
  FUN_00502cb0(param_1,fVar1);
LAB_005061a4:
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_00501760(*(int *)(param_1 + 0xa8));
  }
  DAT_009737dd = 0;
  if ((*(int *)(param_1 + 0x9c) != 0) && (-1 < *(char *)(*(int *)(param_1 + 0x9c) + 9))) {
    DAT_00921359 = 0;
  }
  return;
}

