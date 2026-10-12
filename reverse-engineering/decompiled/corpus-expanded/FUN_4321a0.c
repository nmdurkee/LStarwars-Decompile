/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x4321a0; label: FUN_004321a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004321a0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  float10 fVar4;
  
  if (*(char *)(param_1 + 0x280) != -1) {
    return;
  }
  cVar1 = *(char *)(param_1 + 0xe32);
  if (cVar1 == '\x01') {
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xf8) == 0) {
LAB_004322fb:
      if ((*(uint *)(param_1 + 0xeec) & 0x8000000) == 0) {
        return;
      }
      FUN_0062e650(param_1 + 8,0xffffffff);
      FUN_0055e4a0(param_1,1);
      FUN_0055e4e0(param_1 + 0x6c4);
      return;
    }
    uVar3 = 0x3e;
  }
  else {
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xf4) == 0) goto LAB_004322fb;
    uVar3 = 0x3d;
  }
  if (((*(char *)(param_1 + 0x7b5) == '\x1b') && (iVar2 = *(int *)(param_1 + 0x790), iVar2 != 0)) &&
     (*(char *)(iVar2 + 0x7b5) == '\x1c')) {
    *(undefined1 *)(iVar2 + 0x7b5) = 0xff;
  }
  *(undefined2 *)(param_1 + 0x7aa) = uVar3;
  FUN_0062e650(param_1 + 8,0xffffffff);
  FUN_0055e4a0(param_1,1);
  FUN_0055e4e0(param_1 + 0x6c4);
  *(undefined1 *)(param_1 + 0x7b5) = 0x15;
  fVar4 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)*(short *)(param_1 + 0x7aa),0
                                ,0,1);
  *(float *)(param_1 + 0x77c) = (float)fVar4;
  if ((float)fVar4 <= 0.0) {
    *(undefined4 *)(param_1 + 0x77c) = 0x3f800000;
  }
  *(char *)(param_1 + 0xe32) = cVar1;
  FUN_00414ab0(param_1,0x3ecccccd);
  if (param_2 == 0) {
    return;
  }
  uVar3 = FUN_005be2d0(*(float *)(param_2 + 0x80) - *(float *)(param_1 + 0x80),
                       *(float *)(param_2 + 0x88) - *(float *)(param_1 + 0x88));
  *(undefined2 *)(param_1 + 0x27a) = uVar3;
  *(undefined2 *)(param_1 + 0x5a) = uVar3;
  *(undefined2 *)(param_1 + 0x58) = uVar3;
  return;
}

