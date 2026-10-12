/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f6930; label: FUN_004f6930
 */

void FUN_004f6930(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  undefined4 in_ECX;
  char *pcVar5;
  undefined2 local_4;
  undefined2 uStack_2;
  
  cVar4 = *param_1;
  _local_4 = CONCAT22((short)((uint)in_ECX >> 0x10),0x5c);
  if (cVar4 == '\0') {
    PTR_DAT_00800478[0xac] = 0;
  }
  else {
    pcVar1 = PTR_DAT_00800478 + 0xac;
    pcVar2 = pcVar1;
    pcVar5 = param_1;
    do {
      pcVar5 = pcVar5 + 1;
      *pcVar2 = cVar4;
      cVar4 = *pcVar5;
      pcVar2 = pcVar2 + 1;
    } while (cVar4 != '\0');
    *pcVar2 = '\0';
    iVar3 = (int)pcVar2 - (int)pcVar1;
    if (((iVar3 != 0) && (param_1[iVar3 + -1] != '\\')) && (param_1[iVar3 + -1] != '/')) {
      _local_4 = CONCAT31(stack0xfffffffd,PTR_DAT_00800478[0x10]);
      FUN_004f1e80(PTR_DAT_00800478 + 0xac,&local_4);
      return;
    }
  }
  return;
}

