/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x6a0760; label: FUN_006a0760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006a0760(undefined4 *param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  byte *pbVar6;
  byte local_1c [28];
  
  if (param_1 == (undefined4 *)0x0) {
    return false;
  }
  FUN_006a3940(local_1c + 8,*param_1,param_1[1]);
  if (param_1[2] == 0) {
    return false;
  }
  iVar3 = FUN_006a3bb0(local_1c + 8,8);
  if (iVar3 != 1) {
    return false;
  }
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = 0;
  local_1c[3] = 0;
  local_1c[4] = 0;
  local_1c[5] = 0;
  iVar3 = 6;
  pbVar6 = local_1c;
  do {
    iVar3 = iVar3 + -1;
    bVar2 = FUN_006a3bb0(local_1c + 8,8);
    *pbVar6 = bVar2;
    pbVar6 = pbVar6 + 1;
  } while (iVar3 != 0);
  uVar4 = 6;
  pcVar5 = "vorbis";
  pbVar6 = local_1c;
  do {
    if (*(int *)pbVar6 != *(int *)pcVar5) goto LAB_006a0808;
    uVar4 = uVar4 - 4;
    pcVar5 = pcVar5 + 4;
    pbVar6 = pbVar6 + 4;
  } while (3 < uVar4);
  if (uVar4 == 0) {
LAB_006a0872:
    bVar1 = false;
  }
  else {
LAB_006a0808:
    iVar3 = (uint)*pbVar6 - (uint)(byte)*pcVar5;
    if (iVar3 == 0) {
      if (uVar4 == 1) goto LAB_006a0872;
      iVar3 = (uint)pbVar6[1] - (uint)(byte)pcVar5[1];
      if (iVar3 == 0) {
        if (uVar4 == 2) goto LAB_006a0872;
        iVar3 = (uint)pbVar6[2] - (uint)(byte)pcVar5[2];
        if (iVar3 == 0) {
          if ((uVar4 == 3) || (iVar3 = (uint)pbVar6[3] - (uint)(byte)pcVar5[3], iVar3 == 0))
          goto LAB_006a0872;
        }
      }
    }
    bVar1 = true;
    if (iVar3 < 1) {
      return false;
    }
  }
  return !bVar1;
}

