/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49d9f0; label: FUN_0049d9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049d9f0(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffff7f;
  *(undefined4 *)(param_1 + 0x77c) = 0;
  *(undefined1 *)(param_1 + 0x7b5) = 0;
  *(undefined1 *)(param_1 + 0x7b8) = 3;
  *(undefined2 *)(param_1 + 0x7aa) = 0x1f;
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    *(uint *)(param_1 + 0xeec) = *(uint *)(param_1 + 0xeec) | 0x800;
  }
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x10000;
  *(undefined1 *)(param_1 + 0x7b9) = 0;
  if (0.0 < param_3) {
    FUN_00561ca0(param_1,param_3,0);
  }
  FUN_00547f30(param_1,3);
  FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0) {
    fVar3 = (float10)1.5;
  }
  else {
    fVar3 = (float10)FUN_0062f1c0(*(int *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa));
  }
  *(float *)(param_1 + 0x778) = (float)fVar3;
  *(undefined4 *)(param_1 + 0x790) = 0;
  *(undefined4 *)(param_1 + 0x794) = 0;
  iVar1 = FUN_0049ca80(param_1,0x40000000,0x3f800000,1,2,1);
  *(int *)(param_1 + 0x790) = iVar1;
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      uVar2 = FUN_00569980(param_1,0x40000000,0x3f800000,0,4,0,0,0);
      *(undefined4 *)(param_1 + 0x794) = uVar2;
    }
    if (*(int *)(param_1 + 0x794) == 0) {
      uVar2 = FUN_0049ca80(param_1,0x40000000,0x3f800000,1,2,2);
      *(undefined4 *)(param_1 + 0x790) = uVar2;
    }
  }
  *(undefined4 *)(param_1 + 0x790) = 0;
  *(undefined4 *)(param_1 + 0x794) = 0;
  iVar1 = FUN_0049ca80(param_1,0x40000000,0x3f800000,1,2,1);
  *(int *)(param_1 + 0x790) = iVar1;
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      uVar2 = FUN_00569980(param_1,0x40000000,0x3f800000,0,4,0,0,0);
      *(undefined4 *)(param_1 + 0x794) = uVar2;
    }
    if (*(int *)(param_1 + 0x794) == 0) {
      uVar2 = FUN_0049ca80(param_1,0x40000000,0x3f800000,1,2,2);
      *(undefined4 *)(param_1 + 0x790) = uVar2;
    }
  }
  if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) != 0) {
    FUN_0058d430(param_1);
  }
  return;
}

