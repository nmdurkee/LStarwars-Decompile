/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b6530; label: FUN_006b6530
 */

undefined4 * FUN_006b6530(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  byte bVar12;
  int *piVar13;
  uint uVar14;
  int local_28;
  int local_24;
  int *local_20;
  int local_c;
  
  piVar1 = *(int **)(param_2 + 0x510);
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 4) + 0x1c) + 0xb20);
  iVar11 = param_1 + 4;
  iVar5 = FUN_006a3bb0(iVar11,1);
  if (iVar5 != 1) {
    return (undefined4 *)0x0;
  }
  puVar6 = (undefined4 *)FUN_006a1550(param_1,*(int *)(param_2 + 0x504) * 4);
  iVar5 = 0;
  for (uVar7 = *(int *)(param_2 + 0x50c) - 1; uVar7 != 0; uVar7 = uVar7 >> 1) {
    iVar5 = iVar5 + 1;
  }
  uVar8 = FUN_006a3bb0(iVar11,iVar5);
  *puVar6 = uVar8;
  iVar5 = 0;
  for (uVar7 = *(int *)(param_2 + 0x50c) - 1; uVar7 != 0; uVar7 = uVar7 >> 1) {
    iVar5 = iVar5 + 1;
  }
  uVar8 = FUN_006a3bb0(iVar11,iVar5);
  puVar6[1] = uVar8;
  local_28 = 0;
  local_24 = 2;
  local_20 = piVar1;
  if (0 < *piVar1) {
    do {
      local_20 = local_20 + 1;
      iVar5 = *local_20;
      iVar3 = piVar1[iVar5 + 0x20];
      bVar12 = (byte)piVar1[iVar5 + 0x30];
      uVar7 = 0;
      if ((piVar1[iVar5 + 0x30] != 0) &&
         (uVar7 = FUN_006a99e0(piVar1[iVar5 + 0x40] * 0x2c + iVar2,iVar11), uVar7 == 0xffffffff)) {
        return (undefined4 *)0x0;
      }
      local_c = 0;
      if (0 < iVar3) {
        piVar13 = puVar6 + local_24;
        do {
          uVar9 = (1 << (bVar12 & 0x1f)) - 1U & uVar7;
          uVar7 = (int)uVar7 >> (bVar12 & 0x1f);
          if (piVar1[uVar9 + iVar5 * 8 + 0x50] < 0) {
            *piVar13 = 0;
          }
          else {
            iVar10 = FUN_006a99e0(piVar1[uVar9 + iVar5 * 8 + 0x50] * 0x2c + iVar2,iVar11);
            *piVar13 = iVar10;
            if (iVar10 == -1) {
              return (undefined4 *)0x0;
            }
          }
          local_c = local_c + 1;
          piVar13 = piVar13 + 1;
        } while (local_c < iVar3);
      }
      local_24 = local_24 + iVar3;
      local_28 = local_28 + 1;
    } while (local_28 < *piVar1);
  }
  local_28 = 2;
  if (2 < *(int *)(param_2 + 0x504)) {
    local_20 = piVar1 + 0xd3;
    piVar13 = (int *)(param_2 + 0x30c);
    do {
      uVar7 = (puVar6[*piVar13] & 0x7fff) - (puVar6[piVar13[0x3f]] & 0x7fff);
      iVar11 = (int)(((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f)) *
                    (*local_20 - piVar1[piVar13[0x3f] + 0xd1])) /
               (piVar1[*piVar13 + 0xd1] - piVar1[piVar13[0x3f] + 0xd1]);
      if ((int)uVar7 < 0) {
        iVar11 = -iVar11;
      }
      uVar14 = (puVar6[piVar13[0x3f]] & 0x7fff) + iVar11;
      uVar9 = *(int *)(param_2 + 0x50c) - uVar14;
      uVar7 = uVar9;
      if ((int)uVar14 <= (int)uVar9) {
        uVar7 = uVar14;
      }
      uVar4 = puVar6[local_28];
      if (uVar4 == 0) {
        puVar6[local_28] = uVar14 | 0x8000;
      }
      else {
        if ((int)uVar4 < (int)(uVar7 * 2)) {
          if ((uVar4 & 1) == 0) {
            iVar11 = (int)uVar4 >> 1;
          }
          else {
            iVar11 = -((int)(uVar4 + 1) >> 1);
          }
        }
        else if ((int)uVar14 < (int)uVar9) {
          iVar11 = uVar4 - uVar14;
        }
        else {
          iVar11 = (uVar9 - uVar4) + -1;
        }
        puVar6[local_28] = iVar11 + uVar14;
        puVar6[piVar13[0x3f]] = puVar6[piVar13[0x3f]] & 0x7fff;
        puVar6[*piVar13] = puVar6[*piVar13] & 0x7fff;
      }
      local_20 = local_20 + 1;
      local_28 = local_28 + 1;
      piVar13 = piVar13 + 1;
    } while (local_28 < *(int *)(param_2 + 0x504));
  }
  return puVar6;
}

