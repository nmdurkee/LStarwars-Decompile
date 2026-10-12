/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9120; label: FUN_006d9120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006d9120(uint param_1,byte param_2,int *param_3,int *param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = DAT_02975144;
  *(undefined4 *)(DAT_02975144 + 0x4e08) = 0xffffffff;
  iVar2 = 0;
  pcVar4 = (char *)(iVar5 + 0x6576);
  while (((param_5 != 0 && (*(char *)(iVar5 + 0x6345 + iVar2) != '\0')) ||
         ((param_1 & 1 << ((byte)iVar2 & 0x1f)) != 0))) {
LAB_006d9199:
    iVar2 = iVar2 + 1;
    pcVar4 = pcVar4 + 10;
    if (0xd < iVar2) {
      return -1;
    }
  }
  if (iVar2 - 10U < 4) {
    if (((param_2 & 0x10) == 0) || (*pcVar4 == '\0')) {
      if (((param_2 & 8) != 0) && (pcVar4[1] != '\0')) {
        iVar3 = (int)*(char *)(iVar5 + 0x6577 + iVar2 * 10);
        iVar5 = (int)*(short *)(iVar5 + (iVar2 * 5 + 0x32be) * 2);
        goto LAB_006d91ef;
      }
      bVar1 = param_2 & 4;
      goto LAB_006d9191;
    }
  }
  else if (((param_2 & 2) == 0) || (*pcVar4 == '\0')) {
    bVar1 = param_2 & 1;
LAB_006d9191:
    if ((bVar1 != 0) && (pcVar4[2] != '\0')) {
      iVar5 = iVar5 + iVar2 * 10;
      iVar3 = (int)*(char *)(iVar5 + 0x6578);
      iVar5 = (int)*(short *)(iVar5 + 0x657e);
      goto LAB_006d91ef;
    }
    goto LAB_006d9199;
  }
  iVar3 = (int)*(char *)(iVar5 + 0x6576 + iVar2 * 10);
  iVar5 = (int)*(short *)(iVar5 + iVar2 * 10 + 0x657a);
LAB_006d91ef:
  if (iVar3 == 0) {
    return -1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar3;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar5;
    return iVar2;
  }
  return iVar2;
}

