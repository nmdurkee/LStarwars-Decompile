/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58d560; label: FUN_0058d560
 */

void FUN_0058d560(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float fStack_c;
  float fStack_8;
  
  if ((((DAT_00802868 != -1) && (DAT_00955590 != (code *)0x0)) &&
      (iVar3 = (*DAT_00955590)(param_1), iVar3 != -1)) &&
     (iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0xc), *(int *)(iVar2 + iVar3 * 4) != 0)) {
    fVar4 = (float10)FUN_005ca470(*(undefined4 *)(iVar2 + iVar3 * 4));
    fVar1 = (float)fVar4;
    fVar4 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),iVar3,0);
    fStack_c = (float)fVar4;
    if (1.0 <= fStack_c) {
      if (fStack_c < 1.0) goto LAB_0058d68b;
    }
    else {
      fStack_c = 1.0;
    }
    if (fStack_c < fVar1) {
      fVar4 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),iVar3,1);
      fStack_8 = (float)fVar4;
      if (fVar1 < fStack_8) {
        fStack_8 = fVar1;
      }
      if (fStack_c < fStack_8) {
        *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_00802868;
        *(short *)(param_1 + 0x7aa) = (short)iVar3;
        fVar4 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)(short)iVar3,0,0,1);
        *(float *)(param_1 + 0x77c) = (float)fVar4;
        *(undefined4 *)(param_1 + 0xd3c) = 0;
        return;
      }
    }
  }
LAB_0058d68b:
  FUN_0058d480(param_1,1);
  return;
}

