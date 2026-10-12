/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b2cb0; label: FUN_004b2cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b2cb0(int param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float10 fVar6;
  float local_18 [2];
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *(int *)(param_1 + 0xca4);
  FUN_00498a40(param_1);
  FUN_0058d8b0(param_1);
  FUN_00427b40(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    fVar6 = (float10)FUN_00498590(param_1,0);
    FUN_004abac0(param_1,0,(float)fVar6,0x41200000,0);
    iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
    if (((0.0 < *(float *)(iVar3 + 0x28)) && ((*(uint *)(iVar3 + 0x90) & 0x10000) == 0)) &&
       ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234 || (DAT_009253a4 == 0)))) {
      FUN_0049ad90(param_1,*(uint *)(iVar1 + 8) & DAT_00802278,*(uint *)(iVar1 + 4) & DAT_00802278,
                   iVar1,1);
      FUN_0049b330(param_1,0,iVar1);
    }
    FUN_004b0c80();
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x10000000) != 0) {
      FUN_004a6c30(*(uint *)(iVar1 + 8) & DAT_0080227c,*(uint *)(iVar1 + 4) & DAT_0080227c,
                   0x3e4ccccd,0);
    }
    FUN_0049b8b0();
    if ((((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
         ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 1) != 0)) &&
        (*(short *)(param_1 + 0x1064) == DAT_007f1ae0)) &&
       (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0 &&
        ((DAT_007f4140 != '\0' || (0.0 < *(float *)(param_1 + 0xdec))))))) {
      FUN_004a9450(param_1);
    }
    if (*(short *)(param_1 + 0x1064) == DAT_007f1948) {
      FUN_004a82a0(param_1,0);
    }
    if (*(short *)(param_1 + 0x1064) == DAT_007f1948) {
      if ((*(char *)(param_1 + 0x107f) < '\x03') &&
         (iVar1 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0xa78), iVar1 != -1))
      {
        iVar3 = FUN_0062c350(_DAT_007fc160,_DAT_00925018);
        for (iVar3 = iVar3 * (3 - *(char *)(param_1 + 0x107f)); 0 < iVar3; iVar3 = iVar3 + -1) {
          iVar4 = FUN_0054fa60();
          fVar2 = (float)iVar4 * 1.5259022e-05;
          local_c = *(float *)(param_1 + 0x80) +
                    fVar2 * (*(float *)(param_1 + 0x98) - *(float *)(param_1 + 0x80));
          local_8 = (*(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0x84)) * fVar2 +
                    *(float *)(param_1 + 0x84);
          local_4 = (*(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0x88)) * fVar2 +
                    *(float *)(param_1 + 0x88);
          FUN_00684c90(iVar1,&local_c,1,0,0);
        }
      }
      if (*(int *)(param_1 + 0xe64) != 0) {
        piVar5 = &DAT_0093d7f0;
        do {
          iVar1 = *piVar5;
          if ((((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) &&
              (*(int *)(iVar1 + 0xcd0) != 0)) &&
             (((*(uint *)(iVar1 + 0x1f0) & *(uint *)(param_1 + 0x1e8)) != 0 ||
               (*(uint *)(iVar1 + 500) & *(uint *)(param_1 + 0x1ec)) != 0 &&
              (*(float *)(param_1 + 0x1018) <= 0.0)))) {
            local_18[0] = *(float *)(iVar1 + 0x5c) - *(float *)(param_1 + 0x5c);
            local_10 = *(float *)(iVar1 + 100) - *(float *)(param_1 + 100);
            FUN_005b3620(local_18,local_18,-(uint)*(ushort *)(param_1 + 0x27a));
            if (0.0 <= local_18[0]) {
              fVar2 = *(float *)(param_1 + 0xe90) - _DAT_007fc154;
            }
            else {
              fVar2 = *(float *)(param_1 + 0xe90) + _DAT_007fc154;
            }
            *(float *)(param_1 + 0xe90) = fVar2;
          }
          piVar5 = piVar5 + 1;
        } while ((int)piVar5 < 0x93d7f8);
      }
    }
    FUN_00547dc0(param_1,0);
  }
  return;
}

