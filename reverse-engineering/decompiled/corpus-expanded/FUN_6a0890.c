/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x6a0890; label: FUN_006a0890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a0890(int param_1,int param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  byte *pbVar8;
  byte local_1c [28];
  
  if (param_3 == (undefined4 *)0x0) {
    return 0xffffff7b;
  }
  FUN_006a3940(local_1c + 8,*param_3,param_3[1]);
  iVar2 = FUN_006a3bb0(local_1c + 8,8);
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = 0;
  local_1c[3] = 0;
  local_1c[4] = 0;
  local_1c[5] = 0;
  iVar7 = 6;
  pbVar8 = local_1c;
  do {
    iVar7 = iVar7 + -1;
    bVar1 = FUN_006a3bb0(local_1c + 8,8);
    *pbVar8 = bVar1;
    pbVar8 = pbVar8 + 1;
  } while (iVar7 != 0);
  uVar3 = 6;
  pcVar6 = "vorbis";
  pbVar8 = local_1c;
  do {
    if (*(int *)pbVar8 != *(int *)pcVar6) goto LAB_006a0928;
    uVar3 = uVar3 - 4;
    pcVar6 = pcVar6 + 4;
    pbVar8 = pbVar8 + 4;
  } while (3 < uVar3);
  if (uVar3 == 0) {
LAB_006a0985:
    iVar4 = 0;
  }
  else {
LAB_006a0928:
    iVar7 = (uint)*pbVar8 - (uint)(byte)*pcVar6;
    if (iVar7 == 0) {
      if (uVar3 == 1) goto LAB_006a0985;
      iVar7 = (uint)pbVar8[1] - (uint)(byte)pcVar6[1];
      if (iVar7 == 0) {
        if (uVar3 == 2) goto LAB_006a0985;
        iVar7 = (uint)pbVar8[2] - (uint)(byte)pcVar6[2];
        if (iVar7 == 0) {
          if ((uVar3 == 3) || (iVar7 = (uint)pbVar8[3] - (uint)(byte)pcVar6[3], iVar7 == 0))
          goto LAB_006a0985;
        }
      }
    }
    iVar4 = 1;
    if (iVar7 < 1) {
      iVar4 = -1;
    }
  }
  if (iVar4 != 0) {
    return 0xffffff7c;
  }
  if (iVar2 == 1) {
    if ((param_3[2] != 0) && (*(int *)(param_1 + 8) == 0)) {
      uVar5 = FUN_006a0310();
      return uVar5;
    }
  }
  else if (iVar2 == 3) {
    if (*(int *)(param_1 + 8) != 0) {
      uVar5 = FUN_006a03e0(local_1c + 8);
      return uVar5;
    }
  }
  else if (((iVar2 == 5) && (*(int *)(param_1 + 8) != 0)) && (*(int *)(param_2 + 0xc) != 0)) {
    uVar5 = FUN_006a04e0(param_1);
    return uVar5;
  }
  return 0xffffff7b;
}

