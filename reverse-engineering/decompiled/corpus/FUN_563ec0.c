/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x563ec0; label: FUN_00563ec0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00563ec0(int param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  float10 fVar4;
  float10 extraout_ST0;
  undefined1 auStack_c [12];
  
  if ((_DAT_0080283c != -1) && (*(char *)(param_1 + 0x7b5) == _DAT_0080283c)) {
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    if ((*(char *)(param_1 + 0x7b4) != '\0') && (*(char *)(param_1 + 0x1078) != '\0')) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      return;
    }
    if (*(char *)(param_1 + 0x7b3) == '\x02') {
      fVar1 = _DAT_00925018 + *(float *)(param_1 + 0x77c);
      *(float *)(param_1 + 0x77c) = fVar1;
      if ((*(float *)(param_1 + 0x784) < fVar1 != (*(float *)(param_1 + 0x784) == fVar1)) &&
         (*(undefined1 *)(param_1 + 0x7b5) = 0xff, DAT_009505dc != (code *)0x0)) {
        (*DAT_009505dc)(param_1);
      }
    }
    else if (*(char *)(param_1 + 0x7b3) == '\x01') {
      fVar1 = _DAT_00925018 + *(float *)(param_1 + 0x77c);
      *(float *)(param_1 + 0x77c) = fVar1;
      if (*(float *)(param_1 + 0x784) < fVar1 == (*(float *)(param_1 + 0x784) == fVar1)) {
        fVar1 = fVar1 / *(float *)(param_1 + 0x784);
        *(float *)(param_1 + 0x5c) =
             *(float *)(param_1 + 0x748) +
             fVar1 * (*(float *)(param_1 + 0x754) - *(float *)(param_1 + 0x748));
        *(float *)(param_1 + 0x60) =
             (*(float *)(param_1 + 0x758) - *(float *)(param_1 + 0x74c)) * fVar1 +
             *(float *)(param_1 + 0x74c);
        *(float *)(param_1 + 100) =
             (*(float *)(param_1 + 0x75c) - *(float *)(param_1 + 0x750)) * fVar1 +
             *(float *)(param_1 + 0x750);
        iVar3 = FUN_006e6b90();
        fVar4 = (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] *
                (float10)*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x40);
        iVar3 = param_1 + 0x68;
        *(float *)(param_1 + 0x60) =
             (float)((fVar4 + fVar4) * (float10)*(float *)(param_1 + 0xf0c) + extraout_ST0);
        FUN_005b3800(iVar3,(float *)(param_1 + 0x5c),param_1 + 0x8c);
        FUN_005b3830(iVar3,iVar3,1.0 / _DAT_00925018);
      }
      else if ((DAT_00804c0c == -1) || (*(short *)(param_1 + 0x7aa) != DAT_00804c0c)) {
        iVar3 = FUN_0055f450();
        if ((DAT_00804c04 != -1) && (*(short *)(param_1 + 0x7aa) == DAT_00804c04)) {
          *(short *)(param_1 + 0x58) = *(short *)(param_1 + 0x58) + -0x8000;
          *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + -0x8000;
          *(short *)(param_1 + 0x27a) = *(short *)(param_1 + 0x27a) + -0x8000;
          FUN_0062e650(param_1 + 8,0xffffffff);
        }
        if (((*(uint *)(param_1 + 0x7bc) & 0x100) != 0) && (*(char *)(param_1 + 0x281) == '\0')) {
          fVar4 = (float10)FUN_005506f0(0,param_1 + 0x754,0x40a00000,0xffffffff);
          if (((float)fVar4 != 2e+06) && (0.1 <= *(float *)(param_1 + 0x758) - (float)fVar4)) {
            FUN_00561d20(param_1);
            return;
          }
        }
        FUN_0062e650(param_1 + 8,0xffffffff);
        *(undefined1 *)(param_1 + 0x7b3) = 2;
        sVar2 = (*(code *)PTR_FUN_00802d9c)(param_1);
        *(short *)(param_1 + 0x7aa) = sVar2;
        fVar4 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar2,0,0,1);
        *(float *)(param_1 + 0x784) = (float)fVar4;
        if ((float)fVar4 == 0.0) {
          *(undefined4 *)(param_1 + 0x784) = 0x3f800000;
        }
        *(undefined4 *)(param_1 + 0x77c) = 0;
        if (((*(uint *)(param_1 + 0xeec) & 0x8000000) == 0) &&
           ((*(uint *)(param_1 + 0xef0) & 0x2000) == 0)) {
          if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) {
            FUN_00548020(param_1,0,0);
          }
          else {
            FUN_00549de0(PTR_DAT_008021b4,0xbe4ccccd,0,param_1 + 0x80);
            FUN_00548020(param_1,3,0);
          }
        }
        else {
          FUN_00549de0(PTR_DAT_008021b4,0xbe99999a,0,param_1 + 0x80);
          FUN_00548020(param_1,3,0);
          FUN_0054a910(0x3f19999a,0,0,0);
        }
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x748) = *(undefined4 *)(param_1 + 0x5c);
        *(undefined4 *)(param_1 + 0x74c) = *(undefined4 *)(param_1 + 0x60);
        *(undefined4 *)(param_1 + 0x750) = *(undefined4 *)(param_1 + 100);
        if ((*(uint *)(param_1 + 0xef0) & 0x2000) != 0) {
          FUN_00562010(param_1,auStack_c,0);
          FUN_0056e5f0(auStack_c,0x40000000,0x3ecccccd,param_1,(int)*(char *)(param_1 + 0xe40),0x19)
          ;
        }
        FUN_0052f800(*(undefined4 *)(iVar3 + 0x2ae8),param_1,param_1 + 0x2c8,0xff,1);
      }
      else {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      }
    }
    if (*(char *)(param_1 + 0x7b5) != -1) {
      *(uint *)(param_1 + 0x4b0) = *(uint *)(param_1 + 0x4b0) | 0x2000000;
    }
  }
  return;
}

