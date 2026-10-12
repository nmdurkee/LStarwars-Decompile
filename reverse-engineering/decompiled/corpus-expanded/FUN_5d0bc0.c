/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0bc0; label: FUN_005d0bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0bc0(int param_1,char *param_2,short *param_3)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  
  iVar5 = param_1;
  if ((param_1 != 0) || (iVar5 = DAT_009738b8, DAT_009738b8 != 0)) {
    cVar1 = *param_2;
    psVar6 = param_3;
    pcVar3 = param_2;
    while (cVar1 != '\0') {
      pcVar3 = (char *)FUN_004f2fd0(&param_1,pcVar3);
      iVar4 = iVar5;
      if ((iVar5 == 0) && (iVar4 = DAT_009738b8, DAT_009738b8 == 0)) {
        sVar2 = -1;
      }
      else {
        sVar2 = FUN_005d0aa0(*(undefined4 *)(iVar4 + 0x38),*(undefined4 *)(iVar4 + 0x10),param_1);
      }
      *psVar6 = sVar2;
      if (sVar2 == -1) {
        sVar2 = FUN_005d0b40(iVar5,0x3f);
        *psVar6 = sVar2;
      }
      psVar6 = psVar6 + 1;
      cVar1 = *pcVar3;
    }
    *psVar6 = 0;
  }
  return;
}

