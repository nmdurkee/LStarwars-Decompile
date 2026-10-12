/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59b360; label: FUN_0059b360
 */

undefined2 *
FUN_0059b360(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int *param_5)

{
  char *pcVar1;
  bool bVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int *extraout_ECX;
  uint uVar6;
  int iVar7;
  short *psVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined2 *puVar11;
  int local_20;
  byte *local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined2 *local_c;
  uint local_8;
  int local_4;
  
  iVar4 = FUN_004fc860(param_1);
  local_10 = iVar4;
  if (iVar4 == 0) {
    FUN_0059b330(param_1);
    if (param_5 != extraout_ECX) {
      *param_5 = (int)extraout_ECX;
    }
    return (undefined2 *)0x0;
  }
  puVar9 = (undefined2 *)(*param_2 + 3U & 0xfffffffc);
  *param_2 = (int)puVar9;
  local_20 = 0;
  local_14 = 0;
  local_c = puVar9;
  iVar5 = FUN_004fc5b0(iVar4);
  puVar11 = puVar9;
  do {
    if (iVar5 == 0) {
      FUN_004fa300(iVar4);
      if (0 < local_20) {
        *param_2 = (int)puVar11;
        if (param_5 != (int *)0x0) {
          *param_5 = local_20;
        }
        return puVar9;
      }
      FUN_0059b330(param_1);
      return (undefined2 *)0x0;
    }
    FUN_004f7fb0(iVar4);
    pcVar1 = *(char **)(iVar4 + 0x510);
    if (*pcVar1 != '\0') {
      if (local_14 == 0) {
        iVar5 = FUN_004f8b10(pcVar1,"episode_start");
        if ((iVar5 == 0) && (local_20 < param_4)) {
          *(undefined1 *)(puVar11 + 0xc) = 0;
          local_14 = 1;
          *puVar11 = 0xffff;
          puVar11[1] = 0xffff;
          *(char *)(puVar11 + 0xd) = (char)local_20;
        }
      }
      else {
        iVar5 = FUN_004f8b10(pcVar1,"episode_end");
        if (iVar5 == 0) {
          local_14 = 0;
          if (*(char *)(puVar11 + 0xc) != '\0') {
            local_20 = local_20 + 1;
            puVar11 = puVar11 + 0xe;
          }
        }
        else {
          iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),&DAT_007626f0);
          if (iVar5 == 0) {
            if (((*(byte *)(puVar11 + 0xc) < 10) && (iVar5 = FUN_004f7fb0(iVar4), iVar5 != 0)) &&
               (local_4 = FUN_00573430(*(undefined4 *)(iVar4 + 0x510),&local_18), local_18 != -1)) {
              uVar6 = 0;
              if (*(char *)(puVar11 + 0xc) != '\0') {
                psVar8 = puVar11 + 2;
                do {
                  if (*psVar8 == local_18) break;
                  uVar6 = uVar6 + 1;
                  psVar8 = psVar8 + 1;
                } while ((int)uVar6 < (int)(uint)*(byte *)(puVar11 + 0xc));
              }
              if (uVar6 == *(byte *)(puVar11 + 0xc)) {
                local_1c = (byte *)(puVar9 + 0xc);
                bVar2 = false;
                iVar10 = 0;
                iVar5 = 0;
                do {
                  iVar4 = local_10;
                  if (local_20 <= iVar10) {
                    if (!bVar2) {
                      puVar11[*(byte *)(puVar11 + 0xc) + 2] = (undefined2)local_18;
                      *(char *)(puVar11 + 0xc) = *(char *)(puVar11 + 0xc) + '\x01';
                      if ((*(byte *)(local_4 + 0x7a) & 6) == 0) {
                        *(char *)((int)puVar11 + 0x19) = *(char *)((int)puVar11 + 0x19) + '\x01';
                      }
                    }
                    break;
                  }
                  if (!bVar2) {
                    local_8 = (uint)*local_1c;
                    for (iVar7 = 0; iVar7 < (int)local_8; iVar7 = iVar7 + 1) {
                      if ((short)puVar9[iVar5 + iVar7 + 2] == local_18) {
                        bVar2 = true;
                        puVar9 = local_c;
                        break;
                      }
                      puVar9 = local_c;
                    }
                  }
                  local_1c = local_1c + 0x1c;
                  iVar10 = iVar10 + 1;
                  iVar5 = iVar5 + 0xe;
                } while (!bVar2);
              }
            }
          }
          else {
            iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"name_id");
            if (iVar5 == 0) {
              uVar3 = FUN_004f9e70(iVar4);
              *puVar11 = uVar3;
            }
            else {
              iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"text_id");
              if (iVar5 == 0) {
                uVar3 = FUN_004f9e70(iVar4);
                puVar11[1] = uVar3;
              }
            }
          }
        }
      }
    }
    iVar5 = FUN_004fc5b0(iVar4);
  } while( true );
}

