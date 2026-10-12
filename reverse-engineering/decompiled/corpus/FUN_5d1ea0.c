/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d1ea0; label: FUN_005d1ea0
 */

int FUN_005d1ea0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int extraout_ECX;
  int iVar4;
  undefined *puVar5;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0x14 < (uint)((int)pcVar2 - (int)(param_1 + 1))) {
    param_1[0x14] = '\0';
  }
  iVar4 = 0;
  if (0 < DAT_00963e04) {
    puVar5 = &DAT_0095e678;
    do {
      iVar3 = FUN_004f8b10(puVar5,param_1);
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 0x15;
    } while (iVar4 < DAT_00963e04);
  }
  if (0xff < DAT_00963e04) {
    FUN_005c12e0();
    DAT_00963e04 = extraout_ECX;
  }
  iVar4 = DAT_00963e04 * 0x15;
  DAT_00963e04 = DAT_00963e04 + 1;
  FUN_004f1f10(&DAT_0095e678 + iVar4,param_1);
  return DAT_00963e04 + -1;
}

