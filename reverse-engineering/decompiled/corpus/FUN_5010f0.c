/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x5010f0; label: FUN_005010f0
 */

uint FUN_005010f0(int param_1,undefined4 param_2,undefined4 param_3,float *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  
  if (*(int **)(param_1 + 0x50) == (int *)0x0) {
    uVar4 = *(byte *)(param_1 + 0x58) & 8;
    if (((*(byte *)(param_1 + 0x58) & 8) != 0) && (param_4 != (float *)0x0)) {
      *param_4 = *(float *)(param_1 + 0x4c);
    }
  }
  else {
    iVar1 = **(int **)(param_1 + 0x50);
    if ((0x414e4933 < iVar1) && (iVar1 < 0x414e4936)) {
      uVar4 = FUN_00501030(param_1,param_2,param_4,param_5);
      return uVar4;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0x3f800000;
    }
    iVar1 = *(int *)(param_1 + 0x50);
    iVar2 = *(int *)(iVar1 + 0xc);
    iVar3 = *(int *)(iVar1 + 0x10);
    if (*(short *)(iVar1 + 6) == 4) {
      if (*(char *)(iVar3 + 3) != '\0') {
        FUN_005c9520(iVar2 + 0xc,param_3,(int)*(char *)(iVar3 + 3));
        uVar4 = FUN_006e6b90();
        return uVar4;
      }
      uVar4 = FUN_006e6b90();
      return uVar4;
    }
    if (*(char *)(iVar3 + 7) != '\0') {
      FUN_005c9520(iVar2 + 0x1c,param_3,(int)*(char *)(iVar3 + 7));
    }
    uVar4 = FUN_006e6b90();
    if ((uVar4 != 0) && (param_4 != (float *)0x0)) {
      if (*(char *)(iVar3 + 6) != '\0') {
        fVar5 = (float10)FUN_005c9520(iVar2 + 0x18,param_3,(int)*(char *)(iVar3 + 6));
        *param_4 = (float)fVar5;
        return uVar4;
      }
      *param_4 = *(float *)(iVar2 + 0x18);
      return uVar4;
    }
  }
  return uVar4;
}

