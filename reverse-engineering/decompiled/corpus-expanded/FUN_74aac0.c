/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x74aac0; label: FUN_0074aac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0074aac0(int *param_1,int *param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)(*param_1 + *param_2);
  if (*param_2 < param_1[1]) {
    do {
      if ((&DAT_0297daa0)[*pbVar3] != '\b') break;
      *param_2 = *param_2 + 1;
      pbVar3 = pbVar3 + 1;
    } while (*param_2 < param_1[1]);
  }
  if (param_1[1] <= *param_2) {
    return 0;
  }
  *param_3 = pbVar3;
  param_3[1] = 0;
  iVar2 = *param_2;
  if (((&DAT_0297daa0)[*(byte *)(*param_1 + iVar2)] & 1) != 0) {
    do {
      *param_2 = *param_2 + 1;
      pbVar3 = pbVar3 + 1;
      if (param_1[1] <= *param_2) break;
    } while (((&DAT_0297daa0)[*pbVar3] & 3) != 0);
    param_3[1] = *param_2 - iVar2;
    return 1;
  }
  bVar1 = *pbVar3;
  if (((byte)(&DAT_0297daa0)[bVar1] >> 1 & 1) != 0) {
    do {
      *param_2 = *param_2 + 1;
      pbVar3 = pbVar3 + 1;
      if (param_1[1] <= *param_2) break;
    } while (((byte)(&DAT_0297daa0)[*pbVar3] >> 1 & 1) != 0);
    param_3[1] = *param_2 - iVar2;
    return 1;
  }
  if ((bVar1 == 0x28) || (bVar1 == 0x29)) goto LAB_0074ad10;
  if (bVar1 == 0x26) {
    *param_2 = iVar2 + 1;
    if ((iVar2 + 1 < param_1[1]) && (pbVar3[1] == 0x26)) {
      *param_2 = iVar2 + 2;
      param_3[1] = (iVar2 + 2) - iVar2;
      return 1;
    }
  }
  else {
    if (bVar1 == 0x7c) {
      *param_2 = iVar2 + 1;
      if ((iVar2 + 1 < param_1[1]) && (pbVar3[1] == 0x7c)) {
        *param_2 = iVar2 + 2;
      }
      param_3[1] = *param_2 - iVar2;
      return 1;
    }
    if (bVar1 == 0x3c) {
      *param_2 = iVar2 + 1;
      if ((iVar2 + 1 < param_1[1]) && (pbVar3[1] == 0x3d)) {
        *param_2 = iVar2 + 2;
      }
      param_3[1] = *param_2 - iVar2;
      return 1;
    }
    if (bVar1 != 0x3e) {
      if (bVar1 == 0x3d) {
        *param_2 = iVar2 + 1;
        if ((iVar2 + 1 < param_1[1]) && (pbVar3[1] == 0x3d)) {
          *param_2 = iVar2 + 2;
        }
        param_3[1] = *param_2 - iVar2;
        return 1;
      }
      if (bVar1 == 0x2c) {
LAB_0074ad10:
        *param_2 = iVar2 + 1;
        param_3[1] = 1;
        return 1;
      }
      if (bVar1 == 0x21) {
        *param_2 = iVar2 + 1;
        if ((iVar2 + 1 < param_1[1]) && (pbVar3[1] == 0x3d)) {
          *param_2 = iVar2 + 2;
        }
        param_3[1] = *param_2 - iVar2;
        return 1;
      }
      if (bVar1 == 0x22) {
        do {
          *param_2 = *param_2 + 1;
          pbVar3 = pbVar3 + 1;
          if (param_1[1] <= *param_2) break;
        } while (*pbVar3 != 0x22);
        param_3[1] = *param_2 - iVar2;
        return 1;
      }
      if (bVar1 != 0x2a) {
        if (bVar1 == 0x5b) goto LAB_0074ad10;
        if (bVar1 != 0x5d) {
          return 0;
        }
      }
      *param_2 = iVar2 + 1;
      param_3[1] = 1;
      return 1;
    }
    *param_2 = iVar2 + 1;
    if ((iVar2 + 1 < param_1[1]) && (pbVar3[1] == 0x3d)) {
      *param_2 = iVar2 + 2;
    }
  }
  param_3[1] = *param_2 - iVar2;
  return 1;
}

