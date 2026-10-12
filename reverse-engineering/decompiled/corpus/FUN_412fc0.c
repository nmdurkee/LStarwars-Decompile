/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x412fc0; label: FUN_00412fc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00412fc0(void)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *local_8;
  int local_4;
  
  iVar9 = 0;
  local_8 = DAT_00855e6c;
  local_4 = 0;
  puVar6 = &DAT_007f1310;
  puVar7 = DAT_00855e6c + 0x22;
  do {
    if (*(int *)(puVar6 + -0x10) == 0) {
      if (iVar9 < 0xc) {
        local_8 = local_8 + 0x4e;
        iVar9 = 0xc - iVar9;
        do {
          *(undefined1 *)local_8 = 0;
          local_8 = local_8 + 0x50;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      return;
    }
    puVar4 = puVar7 + 0x22;
    iVar3 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),puVar4,*(int *)(puVar6 + -0x10),1
                        );
    puVar8 = puVar7;
    if (iVar3 != 0) {
      iVar3 = FUN_005cfac0(puVar4);
      if (iVar3 != 0) {
        iVar9 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),puVar7 + 0x25,
                             *(undefined4 *)(puVar6 + -0xc),1);
        if (iVar9 != 0) {
          uVar2 = FUN_005cfac0(puVar7 + 0x25);
          *(undefined2 *)((int)puVar7 + 0xb2) = uVar2;
        }
        puVar7[-2] = _DAT_008065c0;
        puVar7[-1] = _DAT_008065c4;
        *puVar7 = _DAT_008065c8;
        puVar7[1] = _DAT_008065cc;
        puVar7[2] = _DAT_008065d0;
        puVar7[3] = _DAT_008065d4;
        puVar7[4] = _DAT_008065d8;
        puVar7[5] = _DAT_008065dc;
        puVar7[6] = _DAT_008065e0;
        puVar7[7] = _DAT_008065e4;
        puVar7[8] = _DAT_008065e8;
        puVar7[9] = _DAT_008065ec;
        puVar7[10] = _DAT_008065f0;
        puVar7[0xb] = _DAT_008065f4;
        puVar7[0xc] = _DAT_008065f8;
        puVar7[0xd] = _DAT_008065fc;
        puVar4 = (undefined4 *)FUN_005cfa20(puVar4);
        puVar8 = puVar7 + -2;
        for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar8 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar8 = puVar8 + 1;
        }
        sVar1 = *(short *)((int)puVar7 + 0xb2);
        puVar4 = puVar7 + -2;
        puVar8 = local_8;
        for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar8 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar8 = puVar8 + 1;
        }
        if (sVar1 != 0) {
          FUN_0040e870();
          puVar4 = (undefined4 *)FUN_005cfa20(puVar7 + 0x25);
          puVar8 = puVar4;
          puVar10 = puVar7 + 0xe;
          for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          puVar8 = puVar7 + -0x12;
          for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar8 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        uVar5 = FUN_005cffb0(puVar7 + 0x22);
        uVar2 = FUN_0067c760(uVar5);
        iVar9 = local_4 + 1;
        *(undefined2 *)(puVar7 + 0x2d) = uVar2;
        *(undefined1 *)(puVar7 + 0x2c) = 1;
        local_8 = local_8 + 0x50;
        *(undefined1 *)((int)puVar7 + 0xb1) = *puVar6;
        puVar7[0x1e] = *(undefined4 *)(puVar6 + 4);
        puVar7[0x1f] = *(undefined4 *)(puVar6 + 8);
        puVar7[0x20] = *(undefined4 *)(puVar6 + 0xc);
        puVar7[0x29] = *(undefined4 *)(puVar6 + -8);
        puVar8 = puVar7 + 0x50;
        puVar7[0x2a] = *(undefined4 *)(puVar6 + -4);
        puVar7[0x28] = *(undefined4 *)(puVar6 + 0x14);
        puVar7[0x2b] = *(undefined4 *)(puVar6 + 0x10);
        local_4 = iVar9;
      }
    }
    puVar6 = puVar6 + 0x28;
    puVar7 = puVar8;
  } while (iVar9 < 0xc);
  return;
}

