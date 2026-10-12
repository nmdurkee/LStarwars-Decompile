/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4ce220; label: FUN_004ce220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004ce220(int param_1,float param_2)

{
  float fVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int local_10;
  float local_8;
  
  if (*(int *)(PTR_DAT_00802c54 + 0x4680) == 0) {
    return 0;
  }
  fVar3 = *(float *)(param_1 + 0xac) + *(float *)(param_1 + 0xac);
  iVar6 = 0;
  local_10 = -1;
  fVar3 = fVar3 * fVar3;
  local_8 = 1e+08;
  if (0 < *(int *)(PTR_DAT_00802c54 + 0x4684)) {
    iVar7 = *(int *)(PTR_DAT_00802c54 + 0x4680) + 0x50;
    do {
      if ((*(char *)(iVar7 + -1) != '\0') || (*(char *)(iVar7 + -2) == '\0')) goto LAB_004ce3d5;
      iVar5 = FUN_005cfac0(iVar7);
      if (iVar5 == 0) {
LAB_004ce2da:
        bVar2 = *(byte *)(iVar7 + -4);
        fVar8 = (float10)FUN_005b3c50(param_1 + 0x80,*(undefined4 *)(*(int *)(iVar7 + -0x10) + 8),0)
        ;
        fVar1 = (float)fVar8;
        if ((param_2 == 0.0) || (param_2 <= fVar1)) {
          fVar4 = fVar3;
          if ((bVar2 & 2) != 0) {
            fVar4 = *(float *)(iVar7 + -8);
          }
          if (fVar1 < fVar4) goto LAB_004ce396;
        }
        else {
LAB_004ce396:
          if ((local_10 == -1) || (fVar1 < local_8)) {
            DAT_0088060c = 0;
            local_10 = iVar6;
            local_8 = fVar1;
          }
        }
        if ((*(byte *)(iVar7 + -4) & 1) == 0) {
          fVar8 = (float10)FUN_005b3c50(param_1 + 0x80,
                                        *(int *)(*(short **)(iVar7 + -0x10) + 4) + -0xc +
                                        **(short **)(iVar7 + -0x10) * 0xc,0);
          fVar1 = (float)fVar8;
          if ((param_2 == 0.0) || (param_2 <= fVar1)) {
            fVar4 = fVar3;
            if ((bVar2 & 2) != 0) {
              fVar4 = *(float *)(iVar7 + -8);
            }
            if (fVar4 <= fVar1) goto LAB_004ce3d5;
          }
          if ((local_10 == -1) || (fVar1 < local_8)) {
            DAT_0088060c = 1;
            local_10 = iVar6;
            local_8 = fVar1;
          }
        }
      }
      else {
        iVar5 = FUN_005d0420(iVar7);
        if (iVar5 == 0) {
          iVar5 = FUN_005cfd60(iVar7);
          if (iVar5 == 0) goto LAB_004ce2da;
        }
        else if (((*(byte *)(iVar5 + 0x50) & 1) == 0) && (*(float *)(iVar5 + 0x4c) != 1.0))
        goto LAB_004ce2da;
      }
LAB_004ce3d5:
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0xfc;
    } while (iVar6 < *(int *)(PTR_DAT_00802c54 + 0x4684));
    if (local_10 != -1) {
      return local_10 * 0xfc + *(int *)(PTR_DAT_00802c54 + 0x4680);
    }
  }
  return 0;
}

