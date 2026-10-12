/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e4480; label: FUN_004e4480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e4480(undefined4 param_1)

{
  uint *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  
  iVar3 = DAT_0093d810;
  iVar4 = DAT_008894d4;
  if (DAT_00951b50 == 0) {
    if (((((DAT_008894d0 == 0) || (DAT_00856c08 != 0)) || (*(float *)(DAT_008894d0 + 0x28) != 0.0))
        || ((DAT_008894d4 == 0 || (DAT_0093d810 == 0)))) || (*(short *)(DAT_0093d810 + 0x27e) == -1)
       ) goto LAB_004e4927;
    *(undefined4 *)(DAT_008894d4 + 0x10) = *(undefined4 *)(DAT_0093d810 + 0x19c);
    *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar3 + 0x1a0);
    *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar3 + 0x1a4);
    psVar6 = &DAT_00889552;
    do {
      if (((DAT_0093d7f0 != 0) && (psVar6[-1] != -1)) &&
         ((*(char *)(DAT_0093d7f0 + 0x281) != '\0' &&
          ((*(short *)(DAT_0093d7f0 + 0x27e) == psVar6[-1] &&
           (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f0 + 0x27e) * 0x6c + 0x40 +
                                       *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
           fVar2 < *(float *)(DAT_0093d7f0 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f0 + 0x60))))))
         )) {
        DAT_00889564 = DAT_00889564 | 1;
      }
      if ((((DAT_0093d7f4 != 0) && (psVar6[-1] != -1)) && (*(char *)(DAT_0093d7f4 + 0x281) != '\0'))
         && ((*(short *)(DAT_0093d7f4 + 0x27e) == psVar6[-1] &&
             (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f4 + 0x27e) * 0x6c + 0x40 +
                                         *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
             fVar2 < *(float *)(DAT_0093d7f4 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f4 + 0x60))))
            )) {
        DAT_00889564 = DAT_00889564 | 2;
      }
      if (((DAT_0093d7f0 != 0) && (*psVar6 != -1)) &&
         ((*(char *)(DAT_0093d7f0 + 0x281) != '\0' &&
          ((*(short *)(DAT_0093d7f0 + 0x27e) == *psVar6 &&
           (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f0 + 0x27e) * 0x6c + 0x40 +
                                       *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
           fVar2 < *(float *)(DAT_0093d7f0 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f0 + 0x60))))))
         )) {
        DAT_00889564 = DAT_00889564 | 1;
      }
      if ((((DAT_0093d7f4 != 0) && (*psVar6 != -1)) && (*(char *)(DAT_0093d7f4 + 0x281) != '\0')) &&
         ((*(short *)(DAT_0093d7f4 + 0x27e) == *psVar6 &&
          (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f4 + 0x27e) * 0x6c + 0x40 +
                                      *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
          fVar2 < *(float *)(DAT_0093d7f4 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f4 + 0x60))))))
      {
        DAT_00889564 = DAT_00889564 | 2;
      }
      if (((DAT_0093d7f0 != 0) && (psVar6[1] != -1)) &&
         ((*(char *)(DAT_0093d7f0 + 0x281) != '\0' &&
          ((*(short *)(DAT_0093d7f0 + 0x27e) == psVar6[1] &&
           (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f0 + 0x27e) * 0x6c + 0x40 +
                                       *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
           fVar2 < *(float *)(DAT_0093d7f0 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f0 + 0x60))))))
         )) {
        DAT_00889564 = DAT_00889564 | 1;
      }
      if ((((DAT_0093d7f4 != 0) && (psVar6[1] != -1)) && (*(char *)(DAT_0093d7f4 + 0x281) != '\0'))
         && ((*(short *)(DAT_0093d7f4 + 0x27e) == psVar6[1] &&
             (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f4 + 0x27e) * 0x6c + 0x40 +
                                         *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
             fVar2 < *(float *)(DAT_0093d7f4 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f4 + 0x60))))
            )) {
        DAT_00889564 = DAT_00889564 | 2;
      }
      if (((DAT_0093d7f0 != 0) && (psVar6[2] != -1)) &&
         ((*(char *)(DAT_0093d7f0 + 0x281) != '\0' &&
          ((*(short *)(DAT_0093d7f0 + 0x27e) == psVar6[2] &&
           (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f0 + 0x27e) * 0x6c + 0x40 +
                                       *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
           fVar2 < *(float *)(DAT_0093d7f0 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f0 + 0x60))))))
         )) {
        DAT_00889564 = DAT_00889564 | 1;
      }
      if ((((DAT_0093d7f4 != 0) && (psVar6[2] != -1)) && (*(char *)(DAT_0093d7f4 + 0x281) != '\0'))
         && ((*(short *)(DAT_0093d7f4 + 0x27e) == psVar6[2] &&
             (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f4 + 0x27e) * 0x6c + 0x40 +
                                         *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
             fVar2 < *(float *)(DAT_0093d7f4 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f4 + 0x60))))
            )) {
        DAT_00889564 = DAT_00889564 | 2;
      }
      if (((DAT_0093d7f0 != 0) && (psVar6[3] != -1)) &&
         ((*(char *)(DAT_0093d7f0 + 0x281) != '\0' &&
          ((*(short *)(DAT_0093d7f0 + 0x27e) == psVar6[3] &&
           (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f0 + 0x27e) * 0x6c + 0x40 +
                                       *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
           fVar2 < *(float *)(DAT_0093d7f0 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f0 + 0x60))))))
         )) {
        DAT_00889564 = DAT_00889564 | 1;
      }
      if ((((DAT_0093d7f4 != 0) && (psVar6[3] != -1)) && (*(char *)(DAT_0093d7f4 + 0x281) != '\0'))
         && ((*(short *)(DAT_0093d7f4 + 0x27e) == psVar6[3] &&
             (fVar2 = *(float *)(*(int *)(*(short *)(DAT_0093d7f4 + 0x27e) * 0x6c + 0x40 +
                                         *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
             fVar2 < *(float *)(DAT_0093d7f4 + 0x60) != (fVar2 == *(float *)(DAT_0093d7f4 + 0x60))))
            )) {
        DAT_00889564 = DAT_00889564 | 2;
      }
      psVar6 = psVar6 + 5;
    } while ((int)psVar6 < 0x889566);
    if (DAT_00889564 == 3) {
      *(undefined4 *)(DAT_008894d0 + 0x28) = 0x3f800000;
      iVar4 = FUN_005756c0(param_1,"door_fight");
      if (iVar4 != 0) {
        FUN_00575c20(param_1,iVar4,1);
      }
    }
    if (DAT_00951b50 == 0) goto LAB_004e4927;
  }
  if (_DAT_0092505c < 5.0) {
    piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,
                                 "obstacle20");
    if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
      puVar1 = (uint *)(*piVar5 + 0x94);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
    piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,
                                 "obstacle21");
    if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
      puVar1 = (uint *)(*piVar5 + 0x94);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
    piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,
                                 "obstacle22");
    if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
      puVar1 = (uint *)(*piVar5 + 0x94);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
    piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,
                                 "obstacle23");
    if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
      puVar1 = (uint *)(*piVar5 + 0x94);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
  }
LAB_004e4927:
  if ((((DAT_00889565 == '\0') &&
       (((((DAT_0093d7f0 != 0 && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
          (*(char *)(DAT_0093d7f0 + 0x28b) != '\0')) &&
         ((*(uint *)(DAT_0093d7f0 + 0x1f8) & 0x40000) == 0)) ||
        (((DAT_0093d7f4 != 0 && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
         ((*(char *)(DAT_0093d7f4 + 0x28b) != '\0' &&
          ((*(uint *)(DAT_0093d7f4 + 0x1f8) & 0x40000) == 0)))))))) &&
      ((((*DAT_00889568 == '\0' || (DAT_0093d7f0 == 0)) ||
        ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) ||
       ((DAT_0093d7f4 == 0 || ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)))))) &&
     ((DAT_00856c08 == 0 || (DAT_00951240 < 10)))) {
    DAT_00889565 = '\x01';
    FUN_0057a620(0,0,1);
  }
  return;
}

