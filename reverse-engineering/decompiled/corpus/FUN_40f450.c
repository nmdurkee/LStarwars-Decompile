/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40f450; label: FUN_0040f450
 */

void FUN_0040f450(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  
  if (*(float *)(param_1 + 0x410) < param_3 != (*(float *)(param_1 + 0x410) == param_3)) {
    FUN_0040eff0(param_1,param_2,0x3f800000);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x400);
  iVar3 = 0;
  if (0 < iVar2) {
    pfVar4 = (float *)(param_1 + 0x414);
    do {
      if (param_3 < *pfVar4) {
        if (iVar3 == 0) {
          fVar1 = 0.0;
        }
        else {
          fVar1 = *(float *)(param_1 + 0x410 + iVar3 * 4);
        }
        param_3 = ((param_3 - fVar1) / (*(float *)(param_1 + 0x414 + iVar3 * 4) - fVar1) +
                  (float)iVar3) / (float)iVar2;
        break;
      }
      iVar3 = iVar3 + 1;
      pfVar4 = pfVar4 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_0040eff0(param_1,param_2,param_3);
  return;
}

