/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x432860; label: FUN_00432860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00432860(int param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if ((DAT_00925068 == 0) ||
     ((float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xca) <= *(float *)(param_1 + 0x101c)))
  {
    fVar2 = 0.0;
  }
  else if (*(float *)(param_1 + 0x101c) <=
           (float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc9)) {
    fVar2 = 1.0;
  }
  else {
    uVar5 = (uint)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc9);
    fVar2 = 1.0 - (*(float *)(param_1 + 0x101c) - (float)uVar5) /
                  (float)(int)(*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xca) - uVar5);
  }
  *(float *)(param_1 + 0x1020) = fVar2;
  if (DAT_00925068 == 0) {
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  if ((*(byte *)(iVar1 + 0x94) & 0x10) != 0) {
    return;
  }
  if ((*(char *)(param_1 + 0x28b) == '\0') ||
     (iVar3 = *(int *)(*(int *)(**(short **)(param_1 + 0x50) * 0x4c + 0x24 +
                               *(int *)(DAT_029130e4 + 0x20)) + 0xac), iVar3 == 0)) {
    if (*(float *)(iVar1 + 0xb8) < *(float *)(param_1 + 0x101c)) {
      *(undefined4 *)(param_1 + 0x1048) = *(undefined4 *)(iVar1 + 0xa8);
      goto LAB_00432990;
    }
    if (*(float *)(iVar1 + 0xb4) < *(float *)(param_1 + 0x101c)) {
      *(undefined4 *)(param_1 + 0x1048) = *(undefined4 *)(iVar1 + 0xa4);
      goto LAB_00432990;
    }
    iVar3 = *(int *)(iVar1 + 0xa0);
  }
  *(int *)(param_1 + 0x1048) = iVar3;
LAB_00432990:
  *(uint *)(param_1 + 0x1048) = *(uint *)(param_1 + 0x1048) | *(uint *)(param_1 + 0x104c);
  uVar4 = FUN_0041a5b0(*(undefined4 *)(param_1 + 0x1048),param_1);
  *(undefined4 *)(param_1 + 0x1048) = uVar4;
  return;
}

