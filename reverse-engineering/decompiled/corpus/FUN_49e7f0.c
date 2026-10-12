/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49e7f0; label: FUN_0049e7f0
 */

void FUN_0049e7f0(void)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  int unaff_ESI;
  float10 fVar4;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  uVar1 = *(undefined2 *)(unaff_ESI + 0x7aa);
  iVar3 = *(int *)(unaff_ESI + 0xd04);
  local_c = *(float *)(iVar3 + 0xac);
  local_8 = *(undefined4 *)(iVar3 + 0xb0);
  local_4 = *(float *)(iVar3 + 0xb4);
  FUN_005b3620(&local_c,&local_c,0x4000);
  if ((*(uint *)(unaff_ESI + 0xe20) & 0x2000) == 0) {
    if (0.0 <= (*(float *)(unaff_ESI + 0x80) - *(float *)(iVar3 + 0x88)) * local_c +
               (*(float *)(unaff_ESI + 0x88) - *(float *)(iVar3 + 0x90)) * local_4) {
      *(undefined2 *)(unaff_ESI + 0x7aa) = 0x26;
    }
    else {
      *(undefined2 *)(unaff_ESI + 0x7aa) = 0x4f;
    }
  }
  else {
    *(ushort *)(unaff_ESI + 0x7aa) =
         (-(ushort)(*(short *)(unaff_ESI + 0xe12) != 0x26) & 0xffd7) + 0x4f;
  }
  sVar2 = *(short *)(unaff_ESI + 0x7aa);
  *(short *)(unaff_ESI + 0xe12) = sVar2;
  if (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + sVar2 * 4) != 0) {
    fVar4 = (float10)FUN_0062e040((int)*(short *)(unaff_ESI + 0x1064),(int)sVar2,0,0,0);
    *(float *)(unaff_ESI + 0x77c) = (float)fVar4;
    if (0.0 < (float)fVar4) {
      *(undefined1 *)(unaff_ESI + 0x7b5) = 0x25;
      *(undefined4 *)(unaff_ESI + 0x794) = 0;
      *(undefined1 *)(unaff_ESI + 0x7b1) = 0;
      FUN_0062e650(unaff_ESI + 8,0xffffffff);
      if ((*(short *)(unaff_ESI + 0x7aa) != 0x58) ||
         (*(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28) <= 0.0)) {
        *(undefined4 *)(unaff_ESI + 0x790) = *(undefined4 *)(iVar3 + 4);
        iVar3 = FUN_00499500();
        if (iVar3 != 0) {
          *(undefined2 *)(unaff_ESI + 0x27a) = *(undefined2 *)(unaff_ESI + 0x5a);
          *(undefined2 *)(unaff_ESI + 0x58) = *(undefined2 *)(unaff_ESI + 0x5a);
        }
      }
      else {
        *(undefined4 *)(unaff_ESI + 0x790) = 0;
      }
    }
  }
  if (*(char *)(unaff_ESI + 0x7b5) != '%') {
    *(undefined2 *)(unaff_ESI + 0x7aa) = uVar1;
  }
  return;
}

