/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cdab0; label: FUN_004cdab0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cdab0(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float local_8;
  float local_4;
  
  if (*(char *)(param_2 + 0x7b5) == 'Q') {
    pbVar1 = (byte *)(*(int *)(param_2 + 0x798) + 0x3c);
    *pbVar1 = *pbVar1 | 4;
    if ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(param_2 + 0x7aa) * 4) == 0)
       || (iVar4 = FUN_0062f150(param_2 + 8,(int)*(short *)(param_2 + 0x7aa),1,0), iVar4 != 0)) {
      *(float *)(param_2 + 0x77c) = _DAT_00925018 + *(float *)(param_2 + 0x77c);
      if (((*(uint *)(*(int *)(param_2 + 0xca4) + 8) & DAT_00802284) == 0) &&
         (((*(byte *)(param_2 + 0x1fc) & 0x80) != 0 || (*(char *)(param_2 + 0xf00) == '\x02')))) {
        FUN_004ccc60(*(undefined4 *)(param_2 + 0x798),param_2);
        return;
      }
      FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
      *(byte *)(param_2 + 0x7c5) = *(byte *)(param_2 + 0x7c5) | 1;
      *(short *)(param_2 + 0x5a) = *(short *)(param_2 + 0x5a) + -0x8000;
      *(undefined1 *)(param_2 + 0x7b5) = 0xff;
      FUN_004ccc60(*(undefined4 *)(param_2 + 0x798),0);
      return;
    }
  }
  else if (((((((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) || (*(char *)(param_2 + 0xf00) == '\x02'))
             && (*(int *)(param_2 + 0xcbc) != 0)) &&
            ((*(byte *)(*(int *)(param_2 + 0xcbc) + 0xc) & 0x20) != 0)) ||
           ((DAT_007f39e4 != 0 && (DAT_00876580 != 0)))) &&
          (iVar4 = FUN_004cd120(param_1,param_2 + 0x19c,param_2,&local_8), iVar4 != 0)) {
    fVar3 = *(float *)(param_2 + 0x1dc) + 0.25;
    local_4 = fVar3 * 2.5;
    if (local_8 < local_4 * local_4) {
      *(byte *)(iVar4 + 0x3c) = *(byte *)(iVar4 + 0x3c) | 4;
    }
    if (((*(char *)(param_2 + 0x281) != '\0') && (iVar5 = FUN_005620f0(param_2), iVar5 != 0)) &&
       ((local_8 < fVar3 * fVar3 &&
        (((*(uint *)(*(int *)(param_2 + 0xca4) + 8) & DAT_00802280) != 0 ||
         (*(char *)(param_2 + 0xf00) == '\x02')))))) {
      iVar5 = FUN_004cd920(iVar4);
      if (iVar5 == 0) {
        FUN_00547930(0x32,iVar4 + 0x10,0,0);
      }
      else {
        *(undefined1 *)(param_2 + 0x7b5) = 0x51;
        *(undefined4 *)(param_2 + 0x77c) = 0;
        *(int *)(param_2 + 0x798) = iVar4;
        *(undefined2 *)(param_2 + 0x7aa) = 0x99;
        *(short *)(param_2 + 0x5a) = *(short *)(iVar4 + 0x30) + -0x8000;
        FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
        cVar2 = *(char *)(param_2 + 0x280);
        if ((cVar2 == '\0') || (cVar2 == '\x01')) {
          *(undefined4 *)(&DAT_00880584 + cVar2 * 4) = 0;
          return;
        }
      }
    }
  }
  return;
}

