/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74c530; label: FUN_0074c530
 */

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0074c530(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  char *pcVar9;
  byte *pbVar10;
  byte *pbVar11;
  char *pcVar12;
  bool bVar13;
  int local_1a8;
  int *local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  byte *local_198;
  int local_194;
  undefined4 local_190 [100];
  
  local_1a8 = 0;
  local_1a0 = 0;
  local_19c = 0;
  local_194 = in_ECX;
  cVar2 = FUN_0074aac0(param_1,param_2,&local_1a0);
  piVar7 = (int *)0x0;
  do {
    if (cVar2 == '\0') {
      return local_190[0];
    }
    pbVar3 = (byte *)FUN_0074aa40(*(undefined4 *)(in_ECX + 0x11c));
    local_1a4 = *(int **)(*(int *)(in_ECX + 0x11c) + 4);
    *(int **)(*(int *)(in_ECX + 0x11c) + 4) = local_1a4 + 3;
    if (local_1a4 == (int *)0x0) {
      local_1a4 = (int *)0x0;
    }
    else {
      *local_1a4 = 0;
      local_1a4[1] = 0;
      local_1a4[2] = (int)pbVar3;
    }
    piVar5 = local_1a4;
    local_198 = pbVar3;
    if (piVar7 != (int *)0x0) {
      iVar6 = 2;
      bVar13 = true;
      pbVar10 = pbVar3;
      pbVar8 = &DAT_00755d74;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar13 = *pbVar10 == *pbVar8;
        pbVar10 = pbVar10 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar13);
      if (bVar13) {
LAB_0074c78c:
        *(int **)((int)local_190 + local_1a8 * 4) = piVar7;
        local_1a8 = local_1a8 + 1;
        if (*piVar7 == 0) {
          *piVar7 = (int)local_1a4;
          piVar5 = local_1a4;
        }
        else if (piVar7[1] == 0) {
          piVar7[1] = (int)local_1a4;
          piVar5 = local_1a4;
        }
        else {
          piVar5 = (int *)0x0;
        }
      }
      else {
        iVar6 = 2;
        bVar13 = true;
        pbVar10 = pbVar3;
        pbVar8 = &DAT_00755d70;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar13 = *pbVar10 == *pbVar8;
          pbVar10 = pbVar10 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar13);
        if (bVar13) {
          do {
            iVar6 = 2;
            bVar13 = true;
            pcVar9 = (char *)piVar7[2];
            pcVar12 = "(";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar13 = *pcVar9 == *pcVar12;
              pcVar9 = pcVar9 + 1;
              pcVar12 = pcVar12 + 1;
            } while (bVar13);
            if (bVar13) {
LAB_0074c630:
              *(undefined1 *)piVar7[2] = 0x80;
              piVar5 = piVar7;
              goto LAB_0074c7b4;
            }
            if (local_1a8 == 0) {
              piVar7 = (int *)0x0;
              goto LAB_0074c630;
            }
            piVar7 = (int *)(&local_194)[local_1a8];
            local_1a8 = local_1a8 + -1;
          } while (piVar7 != (int *)0x0);
          *puRam00000008 = 0x80;
          piVar5 = piVar7;
        }
        else {
          if (((&DAT_0297daa0)[*pbVar3] & 4) == 0) {
            iVar6 = 8;
            bVar13 = true;
            pbVar10 = pbVar3;
            pbVar8 = (byte *)"defined";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar13 = *pbVar10 == *pbVar8;
              pbVar10 = pbVar10 + 1;
              pbVar8 = pbVar8 + 1;
            } while (bVar13);
            if (!bVar13) {
              pbVar3 = (byte *)piVar7[2];
              iVar6 = 2;
              bVar13 = true;
              pbVar10 = pbVar3;
              pbVar8 = &DAT_00755d74;
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar13 = *pbVar10 == *pbVar8;
                pbVar10 = pbVar10 + 1;
                pbVar8 = pbVar8 + 1;
              } while (bVar13);
              if ((!bVar13) && (((&DAT_0297daa0)[*pbVar3] & 4) == 0)) {
                iVar6 = 8;
                bVar13 = true;
                pbVar10 = (byte *)"defined";
                do {
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  bVar13 = *pbVar3 == *pbVar10;
                  pbVar3 = pbVar3 + 1;
                  pbVar10 = pbVar10 + 1;
                } while (bVar13);
                piVar5 = piVar7;
                if (!bVar13) goto LAB_0074c7b4;
              }
              goto LAB_0074c78c;
            }
          }
          pbVar10 = (byte *)piVar7[2];
          iVar6 = 2;
          bVar13 = true;
          pbVar8 = pbVar10;
          pbVar11 = &DAT_00755d74;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar13 = *pbVar8 == *pbVar11;
            pbVar8 = pbVar8 + 1;
            pbVar11 = pbVar11 + 1;
          } while (bVar13);
          if (bVar13) {
            *(int **)((int)local_190 + local_1a8 * 4) = piVar7;
            local_1a8 = local_1a8 + 1;
            piVar5 = piVar7;
          }
          else {
            if (((&DAT_0297daa0)[*pbVar10] & 4) == 0) {
              iVar6 = 8;
              bVar13 = true;
              pbVar8 = pbVar10;
              pbVar11 = (byte *)"defined";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar13 = *pbVar8 == *pbVar11;
                pbVar8 = pbVar8 + 1;
                pbVar11 = pbVar11 + 1;
              } while (bVar13);
              if (bVar13) goto LAB_0074c6a4;
            }
            else {
LAB_0074c6a4:
              iVar6 = FUN_0074b2a0(pbVar10);
              iVar4 = FUN_0074b2a0(pbVar3);
              if (iVar6 < iVar4) {
                *(int **)((int)local_190 + local_1a8 * 4) = piVar7;
                local_1a8 = local_1a8 + 1;
                piVar5 = (int *)FUN_0074b010(local_1a4);
                goto LAB_0074c7b4;
              }
            }
            if (local_1a8 != 0) {
              iVar6 = (int)local_190 + local_1a8 * 4;
              do {
                puVar1 = *(undefined4 **)(iVar6 + -4);
                iVar6 = 2;
                bVar13 = true;
                pcVar9 = (char *)puVar1[2];
                pcVar12 = "(";
                do {
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  bVar13 = *pcVar9 == *pcVar12;
                  pcVar9 = pcVar9 + 1;
                  pcVar12 = pcVar12 + 1;
                } while (bVar13);
                if (bVar13) {
                  *local_1a4 = (int)piVar7;
                  *puVar1 = local_1a4;
                  goto LAB_0074c7b4;
                }
                iVar6 = FUN_0074b2a0((char *)puVar1[2]);
                iVar4 = FUN_0074b2a0(local_198);
                if (iVar6 < iVar4) {
                  *local_1a4 = (int)piVar7;
                  puVar1[1] = local_1a4;
                  goto LAB_0074c7b4;
                }
                local_1a8 = local_1a8 + -1;
                piVar7 = *(int **)((int)local_190 + local_1a8 * 4);
                iVar6 = (int)local_190 + local_1a8 * 4;
              } while (local_1a8 != 0);
            }
            *local_1a4 = (int)piVar7;
          }
        }
      }
    }
LAB_0074c7b4:
    in_ECX = local_194;
    cVar2 = FUN_0074aac0(param_1,param_2,&local_1a0);
    piVar7 = piVar5;
  } while( true );
}

