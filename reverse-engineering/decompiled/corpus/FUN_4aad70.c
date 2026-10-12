/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4aad70; label: FUN_004aad70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004aad70(void)

{
  float fVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  int unaff_ESI;
  
  cVar2 = *(char *)(unaff_ESI + 0x7b5);
  if (cVar2 == '2') {
    fVar1 = *(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28);
    fVar3 = *(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x1c) - 0.1;
    if (fVar3 < fVar1 != (fVar3 == fVar1)) {
LAB_004aae7a:
      *(undefined1 *)(unaff_ESI + 0x7b5) = 0x31;
      *(undefined2 *)(unaff_ESI + 0x7aa) = 3;
      return;
    }
    fVar1 = *(float *)(unaff_ESI + 0x77c) - _DAT_00925018;
    *(float *)(unaff_ESI + 0x77c) = fVar1;
    if (fVar1 <= 0.0) {
      *(undefined1 *)(unaff_ESI + 0x7b5) = 0xff;
      return;
    }
  }
  else if (cVar2 == '1') {
    FUN_00681f40("DDekaRoll",unaff_ESI + 0x80);
    iVar4 = FUN_0062f150(unaff_ESI + 8,(int)*(short *)(unaff_ESI + 0x7aa),0,0);
    if (((iVar4 != 0) && (*(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28) == 0.0)) &&
       (*(char *)(unaff_ESI + 0x281) != '\0')) {
      FUN_0062e650(unaff_ESI + 8,0xffffffff);
      if (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x8c) != 0) {
        FUN_004aad20();
        return;
      }
      *(undefined1 *)(unaff_ESI + 0x7b5) = 0xff;
    }
  }
  else if ((cVar2 == -1) && (*(char *)(unaff_ESI + 0x281) != '\0')) {
    fVar1 = *(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28);
    fVar3 = *(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x1c) - 0.1;
    if (fVar3 < fVar1 != (fVar3 == fVar1)) goto LAB_004aae7a;
    iVar4 = FUN_0062f1a0(unaff_ESI + 8);
    if ((iVar4 == 5) && (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x8c) != 0)) {
      FUN_004aad20();
      return;
    }
  }
  return;
}

