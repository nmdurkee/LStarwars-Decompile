/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x491bd0; label: FUN_00491bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00491bd0(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  short *psVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_78;
  undefined4 local_68 [14];
  undefined4 local_30;
  undefined4 local_24 [6];
  undefined4 local_c;
  
  local_68[0] = 0xffffffff;
  local_68[1] = 0xffffffff;
  local_68[2] = 0xffffffff;
  local_68[3] = 0xffffffff;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  if (param_1 != 0) {
    iVar5 = *(int *)(param_1 + 0x30);
    DAT_0087b564 = DAT_0087b564 + -1;
    bVar1 = 1 < DAT_0087b560;
    if (iVar5 != 0) {
      iVar3 = iVar5 * 0xc;
      do {
        uVar2 = DAT_0087b564 * (uint)bVar1;
        iVar3 = iVar3 + -0xc;
        puVar6 = *(undefined4 **)(*(int *)(param_1 + 0x34) + 8 + iVar3);
        psVar7 = (short *)(*(int *)(param_1 + 0x34) + iVar3);
        local_68[8] = *puVar6;
        local_68[9] = puVar6[1];
        iVar5 = iVar5 + -1;
        local_68[10] = puVar6[2];
        local_30 = 0xffff0000;
        local_78 = 1;
        if (1 < *psVar7) {
          do {
            puVar8 = (undefined4 *)((int)puVar6 + (int)psVar7[1]);
            uVar2 = uVar2 + bVar1;
            puVar6 = (undefined4 *)((int)puVar6 + (int)psVar7[1]);
            local_24[0] = *puVar8;
            local_24[1] = puVar6[1];
            local_c = local_68[uVar2 & 7];
            local_24[2] = puVar6[2];
            FUN_005dbed0(local_68 + 8,0,0);
            puVar8 = local_24;
            puVar9 = local_68 + 8;
            for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar9 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            local_78 = local_78 + 1;
          } while (local_78 < *psVar7);
        }
      } while (iVar5 != 0);
    }
  }
  return;
}

