/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bdaf0; label: FUN_004bdaf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bdaf0(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  bool bVar4;
  float10 fVar5;
  float local_4;
  
  pfVar3 = (float *)0x0;
  if (*(char *)(param_2 + 0x7b5) == '\\') {
    if ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(param_2 + 0x7aa) * 4) == 0)
       || (pfVar3 = (float *)FUN_0062f150(param_2 + 8,(int)*(short *)(param_2 + 0x7aa),1,0),
          pfVar3 != (float *)0x0)) {
      fVar1 = *(float *)(param_2 + 0x77c) + _DAT_00925018;
      *(float *)(param_2 + 0x77c) = fVar1;
      if (*(float *)(param_2 + 0x784) < fVar1 == (*(float *)(param_2 + 0x784) == fVar1)) {
        if (pfVar3 == (float *)0x0) {
          return;
        }
        fVar5 = (float10)FUN_0062f1f0(*(undefined4 *)(param_2 + 0x50),
                                      (int)*(short *)(param_2 + 0x7aa),0);
        if ((float)fVar5 < 1.0) {
          return;
        }
        bVar4 = (float)fVar5 <= *pfVar3;
      }
      else {
        bVar4 = (*(byte *)(param_2 + 0x7bc) & 0x40) == 0;
        *(undefined1 *)(param_2 + 0x7b5) = 0xff;
      }
      if ((bVar4) && ((*(uint *)(param_2 + 0x7bc) & 0x20) != 0)) {
        *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) | 0x40;
        *(undefined1 *)(*(int *)(param_2 + 0x798) + 0xa3) = 2;
        FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f19999a,0);
        return;
      }
    }
  }
  else if (((((*(uint *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x90) & 0x2000000) != 0) &&
            ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0)) && (*(char *)(param_2 + 0x281) != '\0')) &&
          (iVar2 = FUN_005620f0(param_2), iVar2 != 0)) {
    fVar1 = *(float *)(param_2 + 0x1dc) + 0.25;
    iVar2 = FUN_004bd3d0(param_1,param_2 + 0x19c,param_2,&local_4);
    if (((iVar2 != 0) && (local_4 < fVar1 * fVar1)) &&
       ((*(uint *)(*(int *)(param_2 + 0xca4) + 8) & DAT_00802280) != 0)) {
      FUN_004bda50(1);
      return;
    }
  }
  return;
}

