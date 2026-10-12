/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b4080; label: FUN_006b4080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006b4080(int param_1,int *param_2,int param_3,int param_4,code *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int aiStack_48 [3];
  int local_2c;
  undefined1 *local_28;
  int local_24;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = (int *)*param_2;
  iVar2 = *(int *)param_2[4];
  iVar3 = piVar1[2];
  iVar4 = *(int *)(param_1 + 0x24) >> 1;
  if (piVar1[1] < iVar4) {
    iVar4 = piVar1[1];
  }
  if (0 < iVar4 - *piVar1) {
    iVar5 = (iVar4 - *piVar1) / iVar3;
    aiStack_48[2] = 0x6b40d9;
    iVar4 = param_4 * -4;
    puVar9 = &stack0xffffffc4 + iVar4;
    iVar11 = 0;
    if (0 < param_4) {
      do {
        aiStack_48[2 - param_4] = ((iVar5 + -1 + iVar2) / iVar2) * 4;
        aiStack_48[1 - param_4] = param_1;
        aiStack_48[-param_4] = 0x6b40fa;
        uVar6 = FUN_006a1550();
        *(undefined4 *)(&stack0xffffffc4 + iVar11 * 4 + iVar4) = uVar6;
        iVar11 = iVar11 + 1;
      } while (iVar11 < param_4);
    }
    local_c = 0;
    if (0 < param_2[2]) {
      do {
        local_28 = &stack0xffffffc4 + iVar4;
        iVar11 = 0;
        local_2c = 0;
        if (0 < iVar5) {
          local_8 = 0;
          do {
            if ((local_c == 0) && (iVar12 = 0, 0 < param_4)) {
              do {
                *(int *)(puVar9 + -4) = param_1 + 4;
                *(int *)(puVar9 + -8) = param_2[4];
                *(undefined4 *)(puVar9 + -0xc) = 0x6b4148;
                iVar7 = FUN_006a99e0();
                if (iVar7 == -1) {
                  return 0;
                }
                iVar7 = *(int *)(param_2[7] + iVar7 * 4);
                *(int *)(local_8 + *(int *)(&stack0xffffffc4 + iVar12 * 4 + iVar4)) = iVar7;
                if (iVar7 == 0) {
                  return 0;
                }
                iVar12 = iVar12 + 1;
              } while (iVar12 < param_4);
            }
            local_10 = 0;
            if (0 < iVar2) {
              local_18 = iVar11 * iVar3;
              do {
                piVar10 = (int *)(&stack0xffffffc4 + iVar4);
                if (iVar5 <= iVar11) break;
                local_24 = 0;
                if (0 < param_4) {
                  do {
                    iVar11 = *piVar1;
                    iVar12 = *(int *)(*(int *)(local_8 + *piVar10) + local_10 * 4);
                    if (((piVar1[iVar12 + 5] & 1 << ((byte)local_c & 0x1f)) != 0) &&
                       (iVar12 = *(int *)(*(int *)(param_2[5] + iVar12 * 4) + local_c * 4),
                       iVar12 != 0)) {
                      *(int *)(puVar9 + -4) = iVar3;
                      *(int *)(puVar9 + -8) = param_1 + 4;
                      *(int *)(puVar9 + -0xc) =
                           *(int *)((param_3 - (int)local_28) + (int)piVar10) +
                           (iVar11 + local_18) * 4;
                      *(int *)(puVar9 + -0x10) = iVar12;
                      puVar8 = puVar9 + -0x14;
                      *(undefined4 *)(puVar9 + -0x14) = 0x6b41ff;
                      iVar11 = (*param_5)();
                      puVar9 = puVar8 + 0x10;
                      if (iVar11 == -1) {
                        return 0;
                      }
                    }
                    local_24 = local_24 + 1;
                    piVar10 = piVar10 + 1;
                    iVar11 = local_2c;
                  } while (local_24 < param_4);
                }
                local_18 = local_18 + iVar3;
                local_10 = local_10 + 1;
                iVar11 = iVar11 + 1;
                local_2c = iVar11;
              } while (local_10 < iVar2);
            }
            local_8 = local_8 + 4;
          } while (iVar11 < iVar5);
        }
        local_c = local_c + 1;
      } while (local_c < param_2[2]);
    }
  }
  return 0;
}

