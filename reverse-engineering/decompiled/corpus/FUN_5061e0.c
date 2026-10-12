/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x5061e0; label: FUN_005061e0
 */

void FUN_005061e0(int param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffffeffd;
  *(undefined4 *)(param_1 + 0x94) = 0x3f800000;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xffffffbf;
  iVar2 = *(int *)(param_1 + 0x58);
  if ((*(uint *)(param_1 + 0x88) & 0x40000) == 0) {
    if (*(int *)(iVar2 + 0x14) != 0) {
      FUN_00502740(param_1,0x3f800000);
    }
    if (*(int *)(param_1 + 0xa4) == 0) goto LAB_0050628d;
    fVar1 = *(float *)(param_1 + 0x90);
  }
  else {
    if (*(int *)(iVar2 + 0x14) != 0) {
      FUN_00502740(param_1,*(float *)(iVar2 + 8) - 1.0);
    }
    if (*(int *)(param_1 + 0xa4) == 0) goto LAB_0050628d;
    fVar1 = *(float *)(*(int *)(param_1 + 0x58) + 8) - *(float *)(param_1 + 0x90);
  }
  FUN_00502cb0(param_1,fVar1);
LAB_0050628d:
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_00501760(*(int *)(param_1 + 0xa8));
  }
  if ((*(int *)(param_1 + 0x9c) != 0) && (-1 < *(char *)(*(int *)(param_1 + 0x9c) + 9))) {
    DAT_00921359 = 0;
  }
  return;
}

