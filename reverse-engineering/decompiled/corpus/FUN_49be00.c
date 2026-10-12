/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49be00; label: FUN_0049be00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049be00(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  undefined1 local_c [4];
  undefined4 local_8;
  
  iVar3 = (int)param_1;
  iVar4 = 0;
  if (*(char *)((int)param_1 + 0x7b5) == '=') {
    iVar5 = 0;
    param_1 = 1e+09;
    iVar6 = DAT_0093d504;
    if (0 < DAT_0093d500) {
      do {
        if (((((*(uint *)(iVar6 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar6 + 0x1fc) & 0x1000) != 0))
            && (*(char *)(iVar6 + 0x28b) == '\0')) &&
           (((*(uint *)(*(int *)(*(int *)(iVar6 + 0x54) + 0x24) + 0x90) & 0x1000) != 0 &&
            ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar6 + 0x7b5) * 0x10 + 8) & 0x8000) == 0)))) {
          fVar2 = *(float *)(iVar6 + 0x1dc) + *(float *)(iVar3 + 0x1dc) + 0.1;
          fVar7 = (float10)FUN_005b3c50(iVar3 + 0x80,iVar6 + 0x80,0);
          fVar1 = (float)fVar7;
          if ((fVar1 < fVar2 * fVar2) && ((*(byte *)(iVar3 + 0x1fc) & 0x80) == 0)) {
            *(undefined4 *)(iVar3 + 0x77c) = 0;
            return;
          }
          if ((fVar1 < param_1) && (iVar6 != iVar3)) {
            iVar4 = iVar6;
            param_1 = fVar1;
          }
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x10d8;
      } while (iVar5 < DAT_0093d500);
    }
    fVar1 = *(float *)(iVar3 + 0x77c) + _DAT_00925018;
    *(float *)(iVar3 + 0x77c) = fVar1;
    if (*(float *)(iVar3 + 0x784) < fVar1 == (*(float *)(iVar3 + 0x784) == fVar1)) {
      iVar4 = FUN_0054fa60(0);
      FUN_0054a850(**(undefined4 **)(iVar3 + 0xca4),(float)iVar4 * 1.5259022e-05 * 0.4);
    }
    else {
      *(undefined1 *)(iVar3 + 0x7b5) = 0xff;
      if (((*(int *)(*(int *)(*(int *)(iVar3 + 0x50) + 0xc) + 0x18) != 0) &&
          (FUN_00561ba0(iVar3,0), iVar4 != 0)) && ((*(byte *)(iVar3 + 0x1fc) & 0x80) != 0)) {
        FUN_005b3800(local_c,iVar3 + 0x5c,iVar4 + 0x5c);
        local_8 = 0;
        FUN_005b3b30(local_c,local_c);
        FUN_005b3830(local_c,local_c,0x41400000);
        FUN_005b37d0(iVar3 + 0x68,iVar3 + 0x68,local_c);
        return;
      }
    }
  }
  return;
}

