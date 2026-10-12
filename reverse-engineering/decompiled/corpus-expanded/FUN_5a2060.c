/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2060; label: FUN_005a2060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2060(int param_1,undefined4 param_2)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar5 = 0;
  *(undefined4 *)(param_1 + 0x46f4) = 0;
  *(undefined4 *)(param_1 + 0x46f8) = 0;
  iVar3 = FUN_004fc900("rippleeffects",param_2,0xffff);
  if (iVar3 != 0) {
    puVar6 = (undefined1 *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    *(undefined1 **)(param_1 + 0x104) = puVar6;
    *(undefined1 **)(param_1 + 0x46f4) = puVar6;
    FUN_004f10e0(iVar3,&PTR_s_texture_name_00805870);
    bVar2 = false;
    iVar4 = FUN_004fc5b0(iVar3);
    while (iVar4 != 0) {
      FUN_004f7fb0(iVar3);
      pcVar1 = *(char **)(iVar3 + 0x510);
      if (*pcVar1 != '\0') {
        if (bVar2) {
          iVar4 = FUN_004f8b10(pcVar1,"rippleeffects_end");
          if (iVar4 == 0) {
            bVar2 = false;
            if (puVar6[0x14] != '\0') {
              puVar6 = puVar6 + 0x28;
              *(int *)(param_1 + 0x46f8) = *(int *)(param_1 + 0x46f8) + 1;
            }
          }
          else {
            FUN_004fa020(iVar3);
          }
        }
        else if ((*(int *)(param_1 + 0x46f8) < 2) &&
                (iVar4 = FUN_004f8b10(pcVar1,"rippleeffects_start"), iVar4 == 0)) {
          bVar2 = true;
          *(undefined4 *)(puVar6 + 8) = 0x40000000;
          DAT_00956620 = param_1;
          DAT_00956624 = puVar6;
          *(undefined4 *)(puVar6 + 0xc) = 0;
          puVar6[0x14] = 0;
          *puVar6 = 0x40;
          *(undefined4 *)(puVar6 + 0x10) = 0x3f800000;
          puVar6[1] = 0x40;
          puVar6[2] = 0x40;
          puVar6[3] = 0xff;
          puVar6[4] = 0;
          puVar6[5] = 0;
          puVar6[6] = 0;
          puVar6[7] = 0;
          *(undefined4 *)(puVar6 + 0x24) = 0;
        }
      }
      iVar4 = FUN_004fc5b0(iVar3);
    }
    FUN_004fa300(iVar3);
    iVar3 = *(int *)(param_1 + 0x46f8);
    if (iVar3 < 1) {
      *(undefined4 *)(param_1 + 0x46f4) = 0;
    }
    else {
      *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x46f4) + 0xf + iVar3 * 0x28 & 0xfffffff0;
      if (0 < iVar3) {
        iVar3 = 0;
        do {
          iVar4 = iVar3 + *(int *)(param_1 + 0x46f4);
          FUN_0042fa70(iVar4 + 0x14,iVar4 + 0x24,param_1 + 0x104,param_1 + 0x108);
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 0x28;
        } while (iVar5 < *(int *)(param_1 + 0x46f8));
        return;
      }
    }
  }
  return;
}

