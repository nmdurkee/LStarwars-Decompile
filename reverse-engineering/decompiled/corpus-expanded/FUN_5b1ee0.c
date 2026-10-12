/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b1ee0; label: FUN_005b1ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005b1ee0(undefined4 param_1,uint *param_2,uint *param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  float10 fVar15;
  uint local_18;
  int local_c;
  
  DAT_0095e41c = *param_2;
  local_18 = DAT_0095e41c + 3 & 0xfffffffc;
  bVar3 = 0;
  *param_2 = local_18;
  FUN_006211c0(1);
  iVar7 = FUN_00621270(param_1,0);
  if (iVar7 == 0) {
    DAT_0095e41c = 0;
    return 0;
  }
  iVar7 = FUN_004f1ff0(PTR_s_EDSPLINE_v__00806424);
  iVar14 = 0;
  if (0 < iVar7) {
    do {
      cVar4 = FUN_006218c0();
      if (PTR_s_EDSPLINE_v__00806424[iVar14] != cVar4) {
        FUN_006213e0();
        DAT_0095e41c = 0;
        return 0;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < iVar7);
  }
  FUN_006217e0();
  uVar8 = FUN_006217e0();
  iVar7 = FUN_006217e0();
  local_18 = local_18 + uVar8 * 0xc;
  iVar14 = FUN_006217e0();
  uVar11 = local_18 + iVar14;
  uVar10 = uVar11 + 3 & 0xfffffffc;
  uVar2 = uVar10 + iVar7 * 0xc;
  if (*param_3 < uVar2) {
    FUN_006213e0();
    DAT_0095e41c = 0;
    return 0;
  }
  iVar7 = 0;
  local_c = 0;
  if (0 < (int)uVar8) {
    do {
      FUN_006218c0();
      iVar14 = FUN_006217e0();
      uVar9 = DAT_0095e41c;
      *(undefined2 *)(iVar7 + 2 + DAT_0095e41c) = 0xc;
      *(uint *)(iVar7 + 4 + uVar9) = local_18;
      puVar1 = (undefined2 *)(iVar7 + uVar9);
      uVar6 = FUN_006217e0();
      *puVar1 = uVar6;
      *(uint *)(puVar1 + 4) = uVar10;
      iVar12 = 0;
      uVar9 = DAT_0095e41c;
      if (0 < iVar14) {
        do {
          uVar5 = FUN_006218c0();
          uVar9 = DAT_0095e41c;
          *(undefined1 *)(iVar12 + *(int *)(iVar7 + 4 + DAT_0095e41c)) = uVar5;
          iVar12 = iVar12 + 1;
        } while (iVar12 < iVar14);
      }
      local_18 = local_18 + iVar14;
      if (uVar11 < local_18) {
LAB_005b20b4:
        FUN_006213e0();
        bVar3 = 1;
        DAT_0095e41c = 0;
        break;
      }
      iVar14 = 0;
      if (0 < *(short *)(iVar7 + uVar9)) {
        iVar12 = 0;
        do {
          pfVar13 = (float *)(*(int *)(iVar7 + 8 + uVar9) + iVar12);
          fVar15 = (float10)FUN_006217a0();
          *pfVar13 = (float)fVar15;
          fVar15 = (float10)FUN_006217a0();
          pfVar13[1] = (float)fVar15;
          fVar15 = (float10)FUN_006217a0();
          pfVar13[2] = (float)fVar15;
          iVar14 = iVar14 + 1;
          iVar12 = iVar12 + 0xc;
          uVar9 = DAT_0095e41c;
        } while (iVar14 < *(short *)(iVar7 + DAT_0095e41c));
      }
      uVar10 = uVar10 + *(short *)(iVar7 + uVar9) * 0xc;
      if (uVar2 < uVar10) goto LAB_005b20b4;
      local_c = local_c + 1;
      iVar7 = iVar7 + 0xc;
    } while (local_c < (int)uVar8);
  }
  FUN_006213e0();
  *param_2 = uVar2;
  DAT_0095e420 = uVar8;
  return ~-(uint)bVar3 & uVar8;
}

