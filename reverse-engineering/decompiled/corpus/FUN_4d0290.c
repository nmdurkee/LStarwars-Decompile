/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d0290; label: FUN_004d0290
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d0290(int param_1)

{
  char cVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float10 fVar5;
  
  if (*(char *)(param_1 + 0x7b5) == '.') {
    pfVar4 = (float *)0x0;
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0)
       || (pfVar4 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0),
          pfVar4 != (float *)0x0)) {
      fVar2 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
      *(float *)(param_1 + 0x77c) = fVar2;
      if (0.0 < fVar2) {
        if ((*(byte *)(param_1 + 0x7bc) & 0x40) == 0) {
          if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4)
              == 0) {
            if (fVar2 < 0.5) {
              *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x4000;
            }
          }
          else {
            fVar5 = (float10)FUN_0062f1f0(*(int *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),
                                          2);
            if (((pfVar4 != (float *)0x0) && (0.0 < *pfVar4)) &&
               ((float)fVar5 < *pfVar4 != ((float)fVar5 == *pfVar4))) {
              *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x4000;
            }
          }
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        if ((*(byte *)(param_1 + 0x7bc) & 0x40) == 0) {
          *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x4000;
        }
      }
      if ((*(uint *)(param_1 + 0xe24) & 0x4000) != 0) {
        *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x40;
        return 0;
      }
    }
  }
  else if ((((((*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe9e) != '\0') &&
              ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) &&
             ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802280) != 0)) &&
            ((((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x1000000) != 0 ||
              (*(char *)(param_1 + 0x1082) == '\x06')) ||
             (iVar3 = FUN_0041aef0(param_1), iVar3 != 0)))) &&
           ((*(char *)(param_1 + 0x281) != '\0' || (*(char *)(param_1 + 0xe32) == '\x01')))) &&
          ((cVar1 = *(char *)(param_1 + 0x7b5), cVar1 == -1 ||
           (((cVar1 == '\x06' || (cVar1 == '\a')) ||
            ((*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 4) != 0)))))) {
    iVar3 = FUN_0064ad80(0,0,param_1);
    if (iVar3 == 0) {
      *(undefined1 *)(param_1 + 0x7b5) = 0x2e;
      if (*(char *)(param_1 + 0xe32) == '\x01') {
        *(undefined2 *)(param_1 + 0x7aa) = 0x6f;
      }
      else if ((*(byte *)(param_1 + 0xe22) & 1) == 0) {
        *(undefined2 *)(param_1 + 0x7aa) = 0x65;
      }
      else {
        *(undefined2 *)(param_1 + 0x7aa) = 0x6e;
      }
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0)
      {
        *(undefined2 *)(param_1 + 0x7aa) = 0x65;
      }
      iVar3 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,1);
      if (iVar3 != 0) {
        FUN_0062e650(param_1 + 8,0xffffffff);
      }
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) != 0)
      {
        fVar5 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),
                                      (int)*(short *)(param_1 + 0x7aa),0,0,1);
        *(float *)(param_1 + 0x77c) = (float)fVar5;
        return 0;
      }
      *(undefined4 *)(param_1 + 0x77c) = 0x3f800000;
    }
    else if (((*(byte *)(iVar3 + 0x144) & 2) == 0) || (1.0 < *(float *)(iVar3 + 0x100))) {
      FUN_0064ac90(iVar3,0);
      return 1;
    }
  }
  return 0;
}

