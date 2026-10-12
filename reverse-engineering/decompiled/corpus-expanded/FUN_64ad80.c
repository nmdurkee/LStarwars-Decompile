/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64ad80; label: FUN_0064ad80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0064ad80(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_8;
  
  if (DAT_0291f664 == 0) {
    return 0;
  }
  local_8 = 1e+06;
  iVar1 = 0;
  iVar3 = 0;
  iVar2 = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if ((((*(byte *)(iVar2 + 0x144) & 1) != 0) &&
          ((param_2 == -1 || (*(char *)(iVar2 + 0x206) == param_2)))) &&
         ((param_3 == 0 || (*(int *)(iVar2 + 0xd4) == param_3)))) {
        if (param_1 == 0) {
          return iVar2;
        }
        fVar4 = (float10)FUN_005b3c50(param_1,iVar2 + 0x30,0);
        if ((float)fVar4 < local_8) {
          iVar1 = iVar2;
          local_8 = (float)fVar4;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x220;
    } while (iVar3 < DAT_0081020c);
  }
  return iVar1;
}

