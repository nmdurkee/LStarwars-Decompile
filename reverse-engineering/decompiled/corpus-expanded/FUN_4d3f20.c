/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d3f20; label: FUN_004d3f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d3f20(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float10 extraout_ST0;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(byte **)(param_1 + 0xcc4) != (byte *)0x0) {
    uVar5 = (uint)**(byte **)(param_1 + 0xcc4);
    iVar7 = 0;
    if (uVar5 != 0) {
      local_48 = 0x3c;
      iVar6 = 0x14;
      do {
        uVar4 = (uint)(ushort)(0xc000 - *(short *)(iVar6 + 0x14 + *(int *)(param_1 + 0xcc4)));
        if ((*(float *)(*(int *)(param_1 + 0xcc4) + 8) < 0.8) && (iVar7 == uVar5 - 1)) {
          FUN_00550040(0,uVar4);
          iVar3 = FUN_006e6b90();
          uVar4 = (int)ROUND(extraout_ST0 * (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff]) &
                  0xffff;
        }
        local_40 = _DAT_008065c0;
        local_3c = _DAT_008065c4;
        local_38 = _DAT_008065c8;
        local_34 = _DAT_008065cc;
        local_30 = _DAT_008065d0;
        local_2c = _DAT_008065d4;
        local_28 = _DAT_008065d8;
        local_24 = _DAT_008065dc;
        local_20 = _DAT_008065e0;
        local_1c = _DAT_008065e4;
        local_18 = _DAT_008065e8;
        local_14 = _DAT_008065ec;
        local_10 = _DAT_008065f0;
        local_c = _DAT_008065f4;
        local_8 = _DAT_008065f8;
        local_4 = _DAT_008065fc;
        FUN_005b4dd0(&local_40,uVar4);
        iVar3 = *(int *)(param_1 + 0xcc4);
        FUN_004d21b0();
        FUN_005b4900(&local_40,local_48 + iVar3);
        if (((*(byte **)(param_1 + 0xcc4))[3] == 0) &&
           (iVar7 + 1U == (uint)**(byte **)(param_1 + 0xcc4))) {
          iVar3 = FUN_006e6b90();
          fVar1 = 1.0 - ((float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] + 1.0) * 0.5;
        }
        else {
          fVar1 = 1.0;
        }
        fVar2 = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x5100) + 8) * 4.0;
        FUN_005b4b30(&local_40,
                     ((*(float *)(param_1 + 0x1dc) + *(float *)(param_1 + 0x1dc)) - fVar2) * fVar1 +
                     fVar2);
        if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x79e) != '\0') {
          FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x790,&local_40);
        }
        if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x7ae) != '\0') {
          FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x7a0,&local_40);
        }
        uVar5 = (uint)**(byte **)(param_1 + 0xcc4);
        local_48 = local_48 + 0xc;
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar7 < (int)uVar5);
    }
  }
  return;
}

