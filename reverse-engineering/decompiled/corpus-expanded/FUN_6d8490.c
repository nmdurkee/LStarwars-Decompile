/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d8490; label: FUN_006d8490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d8490(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int *piVar7;
  short *psVar8;
  
  uVar2 = 1 << ((byte)param_1 & 0x1f);
  if ((uVar2 & *(uint *)(in_ECX + 0x4e08)) == 0) {
    return;
  }
  if ((uVar2 & *(uint *)(in_ECX + 0x4e0c)) != 0) {
    return;
  }
  *(uint *)(in_ECX + 0x4e08) = ~uVar2 & *(uint *)(in_ECX + 0x4e08);
  *(uint *)(in_ECX + 0x4e0c) = *(uint *)(in_ECX + 0x4e0c) | uVar2;
  if (3 < param_1 - 10U) {
    iVar5 = 0;
    psVar8 = (short *)(in_ECX + 0x671c);
    do {
      if (0x4000 < *psVar8) {
        iVar3 = in_ECX + param_1 * 10;
        *(undefined1 *)(iVar3 + 0x660e) = 2;
LAB_006d86cb:
        *(short *)(iVar3 + 0x6614) = (short)iVar5;
        break;
      }
      if (*psVar8 < -0x4000) {
        iVar3 = in_ECX + param_1 * 10;
        *(undefined1 *)(iVar3 + 0x660e) = 3;
        goto LAB_006d86cb;
      }
      iVar5 = iVar5 + 1;
      psVar8 = psVar8 + 1;
    } while (iVar5 < 0x20);
    iVar5 = 0;
    if (0 < *(short *)(param_1 * 0x17c + 0x4e4c + in_ECX)) {
      do {
        if (*(char *)(in_ECX + 0x675c + iVar5) != '\0') {
          iVar3 = in_ECX + param_1 * 10;
          *(undefined1 *)(iVar3 + 0x660c) = 1;
          *(short *)(iVar3 + 0x6610) = (short)iVar5;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(param_1 * 0x17c + 0x4e4c + in_ECX));
    }
    iVar5 = 0x80;
    do {
      if (*(char *)(in_ECX + 0x675c + iVar5) != '\0') {
        iVar3 = in_ECX + param_1 * 10;
        *(undefined1 *)(iVar3 + 0x660c) = 1;
        *(short *)(iVar3 + 0x6610) = (short)iVar5;
        return;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x84);
    return;
  }
  if (*(char *)(in_ECX + 0x6574) != '\0') {
    puVar1 = (undefined4 *)(in_ECX + 0x660c + param_1 * 10);
    *puVar1 = *(undefined4 *)(in_ECX + 0x6670);
    puVar1[1] = *(undefined4 *)(in_ECX + 0x6674);
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(in_ECX + 0x6678);
    return;
  }
  *(undefined1 *)(in_ECX + 0x6574) = 1;
  iVar3 = (int)(DAT_029765ac + 3 + (DAT_029765ac + 3 >> 0x1f & 3U)) >> 2;
  iVar5 = 0;
  if (0 < iVar3) {
    piVar7 = *(int **)(in_ECX + 0x68b0);
    do {
      if (*piVar7 != 0) {
        iVar5 = iVar5 * 4;
        iVar3 = 0;
        goto LAB_006d8550;
      }
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar5 < iVar3);
  }
  goto LAB_006d8575;
  while( true ) {
    if (*(char *)((int)*(int **)(in_ECX + 0x68b0) + iVar5) != '\0') {
      *(undefined1 *)(in_ECX + 0x6670) = 7;
      *(short *)(in_ECX + 0x6674) = (short)iVar5;
      break;
    }
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 1;
    if (3 < iVar3) break;
LAB_006d8550:
    if (DAT_029765ac <= iVar5) break;
  }
LAB_006d8575:
  if ((((DAT_029765b4 != 0) && (DAT_029765b8 != 0)) && (1 < DAT_029765b4)) && (1 < DAT_029765b8)) {
    iVar5 = 0;
    do {
      if (*(char *)(in_ECX + 0x6334 + iVar5) != '\0') {
        *(undefined1 *)(in_ECX + 0x6671) = 4;
        *(short *)(in_ECX + 0x6676) = (short)iVar5;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 8);
    uVar2 = FUN_006e6b90();
    uVar4 = FUN_006e6b90();
    iVar5 = FUN_006e6b90();
    iVar6 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
    iVar3 = (uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f);
    if (iVar6 < iVar3) {
      if (*(int *)(in_ECX + 0x656c) < iVar3) {
        if ((int)uVar2 < 1) {
          *(undefined1 *)(in_ECX + 0x6672) = 6;
          *(undefined2 *)(in_ECX + 0x6678) = 0;
        }
        else {
          *(undefined1 *)(in_ECX + 0x6672) = 5;
          *(undefined2 *)(in_ECX + 0x6678) = 0;
        }
      }
    }
    else if (*(int *)(in_ECX + 0x656c) < iVar6) {
      if ((int)uVar4 < 1) {
        *(undefined1 *)(in_ECX + 0x6672) = 6;
      }
      else {
        *(undefined1 *)(in_ECX + 0x6672) = 5;
      }
      *(undefined2 *)(in_ECX + 0x6678) = 1;
    }
    if (iVar5 != 0) {
      if (0 < iVar5) {
        *(undefined1 *)(in_ECX + 0x6672) = 5;
        *(undefined2 *)(in_ECX + 0x6678) = 2;
        return;
      }
      *(undefined1 *)(in_ECX + 0x6672) = 6;
      *(undefined2 *)(in_ECX + 0x6678) = 2;
    }
  }
  return;
}

