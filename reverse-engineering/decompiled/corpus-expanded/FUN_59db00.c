/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59db00; label: FUN_0059db00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0059db00(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  ushort uVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  uint local_8;
  
  pbVar3 = param_2;
  pcVar2 = *(char **)(param_2 + 0xc);
  if (pcVar2 == (char *)0x0) {
    if (*param_2 == 0) {
      return 1;
    }
    piVar10 = *(int **)(param_2 + 0x10);
    puVar7 = *(undefined1 **)(param_2 + 0x18);
    iVar9 = 0;
    if (*param_2 != 0) {
      do {
        iVar5 = (*(code *)(&PTR_FUN_0080551c)[(uint)*(byte *)(*piVar10 + 3) * 3])
                          (param_1,*piVar10,*puVar7);
        if (iVar5 == 0) {
          return 0;
        }
        iVar9 = iVar9 + 1;
        piVar10 = piVar10 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar9 < (int)(uint)*param_2);
      return 1;
    }
    return 1;
  }
  local_8 = 0;
  switch(*pcVar2) {
  case '\0':
    if (*param_2 != 0) {
      piVar10 = *(int **)(param_2 + 0x10);
      puVar7 = *(undefined1 **)(param_2 + 0x18);
      iVar9 = 0;
      if (*param_2 != 0) {
        do {
          iVar5 = (*(code *)(&PTR_FUN_0080551c)[(uint)*(byte *)(*piVar10 + 3) * 3])
                            (param_1,*piVar10,*puVar7);
          if (iVar5 == 0) {
            return 0;
          }
          iVar9 = iVar9 + 1;
          piVar10 = piVar10 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar9 < (int)(uint)*param_2);
      }
    }
    break;
  case '\x01':
    param_2 = (byte *)0x1;
    goto LAB_0059dbe2;
  case '\x02':
    if (*param_2 != 0) {
      piVar10 = *(int **)(param_2 + 0x10);
      puVar7 = *(undefined1 **)(param_2 + 0x18);
      iVar9 = 0;
      if (*param_2 != 0) {
        do {
          iVar5 = (*(code *)(&PTR_FUN_0080551c)[(uint)*(byte *)(*piVar10 + 3) * 3])
                            (param_1,*piVar10,*puVar7);
          if (iVar5 != 0) {
            return 0;
          }
          iVar9 = iVar9 + 1;
          piVar10 = piVar10 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar9 < (int)(uint)*param_2);
      }
    }
    break;
  case '\x03':
  case '\x05':
    param_2 = (byte *)(uint)(byte)pcVar2[1];
LAB_0059dbe2:
    if (*pbVar3 == 0) {
      bVar11 = param_2 == (byte *)0x0;
    }
    else {
      piVar10 = *(int **)(pbVar3 + 0x10);
      puVar7 = *(undefined1 **)(pbVar3 + 0x18);
      iVar9 = 0;
      uVar6 = 0;
      if (*pbVar3 != 0) {
        do {
          iVar5 = (*(code *)(&PTR_FUN_0080551c)[(uint)*(byte *)(*piVar10 + 3) * 3])
                            (param_1,*piVar10,*puVar7);
          if (iVar5 != 0) {
            local_8 = local_8 + 1;
          }
          iVar9 = iVar9 + 1;
          piVar10 = piVar10 + 1;
          puVar7 = puVar7 + 1;
          uVar6 = local_8;
        } while (iVar9 < (int)(uint)*pbVar3);
      }
      if (*pcVar2 != '\x05') {
        if ((int)uVar6 < (int)param_2) {
          return 0;
        }
        break;
      }
      bVar11 = (byte *)uVar6 == param_2;
    }
    if (!bVar11) {
      return 0;
    }
    break;
  case '\x04':
    bVar1 = *param_2;
    uVar4 = (uint)bVar1;
    uVar8 = *(ushort *)(param_2 + 10) >> 10 & 1;
    uVar6 = uVar4;
    if (uVar8 != 0) {
      uVar6 = uVar4 - param_2[1];
    }
    param_2 = (byte *)uVar6;
    if ((uVar6 == 0) && (uVar8 == 0)) {
      param_2 = (byte *)uVar4;
    }
    if (bVar1 != 0) {
      piVar10 = *(int **)(pbVar3 + 0x10);
      puVar7 = *(undefined1 **)(pbVar3 + 0x18);
      iVar9 = 0;
      if (uVar4 != 0) {
        do {
          iVar5 = (*(code *)(&PTR_FUN_0080551c)[(uint)*(byte *)(*piVar10 + 3) * 3])
                            (param_1,*piVar10,*puVar7);
          if (iVar5 != 0) {
            local_8 = local_8 + 1;
          }
          iVar9 = iVar9 + 1;
          piVar10 = piVar10 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar9 < (int)(uint)*pbVar3);
      }
      if ((int)local_8 < (int)param_2) {
        return 0;
      }
    }
  }
  if ((*pcVar2 == '\x04') && (iVar9 = 0, pbVar3[2] != 0)) {
    do {
      DAT_00956434 = DAT_00956434 + '\x01';
      FUN_0059da60(param_1,pbVar3,*(undefined4 *)(*(int *)(pbVar3 + 0x14) + iVar9 * 4),DAT_00956434)
      ;
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(uint)pbVar3[2]);
  }
  return 1;
}

