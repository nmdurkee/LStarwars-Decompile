/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bcb10; label: FUN_004bcb10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bcb10(void)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float *pfVar7;
  undefined4 *puVar8;
  int local_14;
  float local_c;
  float local_8;
  float local_4;
  
  if (DAT_0087b9d0 != 0) {
    DAT_0087b9d0 = 0;
    pfVar7 = (float *)&DAT_0087b9e8;
    local_14 = 8;
    do {
      if (0.0 < *pfVar7) {
        fVar2 = *pfVar7 - _DAT_00925018;
        *pfVar7 = fVar2;
        if (0.0 <= fVar2) {
          DAT_0087b9d0 = 1;
        }
        else {
          *pfVar7 = 0.0;
        }
        FUN_005b7d30(*pfVar7,_DAT_007fc4c8);
        iVar3 = FUN_006e6b90();
        if (pfVar7[-4] == 0.0) {
          pfVar1 = pfVar7 + -3;
          iVar4 = FUN_005cfac0(pfVar1);
          if (iVar4 != 0) {
            puVar5 = (undefined4 *)FUN_005cfa20(pfVar1);
            puVar6 = (undefined4 *)FUN_005d0330(pfVar1);
            puVar8 = puVar6;
            for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar8 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar8 = puVar8 + 1;
            }
            if (iVar3 != 0) {
              local_c = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * _DAT_007fc4cc + 1.0;
              local_8 = local_c;
              local_4 = local_c;
              FUN_005b4c30(puVar6,&local_c);
              FUN_005ea660(pfVar7 + -3);
            }
            FUN_00681f40("swdisco",puVar6 + 0xc);
          }
        }
        else {
          FUN_005687f0(pfVar7[-4]);
          local_c = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * _DAT_007fc4cc + 1.0;
          local_8 = local_c;
          local_4 = local_c;
          FUN_005b4c30(pfVar7[-4],&local_c);
          *(uint *)((int)pfVar7[-4] + 0x94) = *(uint *)((int)pfVar7[-4] + 0x94) | 0x10000;
          FUN_00681f40("swdisco",(int)pfVar7[-4] + 0x30);
        }
      }
      pfVar7 = pfVar7 + 5;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  return;
}

