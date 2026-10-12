/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x453180; label: FUN_00453180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00453180(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  undefined4 *puVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  float10 fVar8;
  
  iVar7 = 0;
  bVar3 = false;
  if ((param_6 != 0) && (0 < param_5)) {
    do {
      iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"lever=");
      if (iVar4 == 0) {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar7 * 4),"instant");
        if (iVar4 == 0) {
          bVar3 = true;
        }
      }
      else {
        piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_007faaa4,
                                     iVar4 + 6);
        if (((piVar5 != (int *)0x0) && (iVar4 = *piVar5, iVar4 != 0)) &&
           (*(int *)(param_2 + 0x6c) = iVar4, (*(byte *)(iVar4 + 0x94) & 2) == 0)) {
          puVar1 = (undefined4 *)(param_2 + 0x78);
          *puVar1 = *(undefined4 *)(iVar4 + 0x40);
          *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(iVar4 + 0x44);
          *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(iVar4 + 0x48);
          fVar8 = (float10)FUN_005506f0(0,puVar1,0x40a00000,0xffffffff);
          if ((float)fVar8 != 2e+06) {
            *(float *)(param_2 + 0x7c) = (float)fVar8;
          }
          FUN_0043e040(param_1,puVar1,param_2 + 0x84,puVar1,0,0xff);
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_5);
  }
  iVar7 = *(int *)(param_2 + 0x6c);
  if (iVar7 == 0) {
    return 1;
  }
  if (bVar3) {
    *(ushort *)(iVar7 + 0x94) = *(ushort *)(iVar7 + 0x94) | 2;
    *(undefined4 *)(iVar7 + 0x78) = 0x3f800000;
    *(undefined2 *)(iVar7 + 0x8e) = 0x8000;
    return 1;
  }
  if (param_3 == 0) {
    return 1;
  }
  piVar5 = *(int **)(param_3 + 0xd0);
  if (piVar5 == (int *)0x0) {
    return 1;
  }
  if (*piVar5 == 0) {
    return 1;
  }
  iVar4 = *piVar5;
  FUN_0052fcb0(param_3,param_2 + 0x78,0,param_2 + 0x84,1,0);
  if ((*(uint *)(iVar4 + 0xef0) & 0x800000) == 0) {
    if ((DAT_0093b2a4 == 0) ||
       (param_7 = *(float *)(param_2 + 0x9c) - param_7, *(float *)(param_2 + 0x9c) = param_7,
       0.0 <= param_7)) goto LAB_00453397;
    *(undefined4 *)(param_2 + 0x9c) = 0x3f000000;
    uVar6 = DAT_0080228c;
  }
  else {
    fVar8 = (float10)FUN_005b3c50(param_3 + 0x14c,param_2 + 0x78,0);
    if (_DAT_00801c6c * _DAT_00801c6c <= (float)fVar8) goto LAB_00453397;
    *(int *)(param_3 + 0x1e4) = iVar7 + 0x68;
    uVar6 = DAT_00802280;
  }
  puVar2 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
  *puVar2 = *puVar2 | uVar6;
LAB_00453397:
  if ((*(char *)(iVar4 + 0x7b5) == 'J') && (*(int *)(iVar4 + 0x798) == iVar7)) {
    return 1;
  }
  return 0;
}

