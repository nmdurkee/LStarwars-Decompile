/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63cff0; label: FUN_0063cff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063cff0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char local_204 [512];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_204;
  FUN_005d0fb0(DAT_009738b8);
  FUN_005d0fe0(DAT_009738b8,_DAT_0080fe00,_DAT_0080fe00);
  FUN_005d1060(DAT_009738b8,0x80ffffff);
  pcVar4 = *(char **)(&DAT_0080ff08 + (DAT_029139d4 + DAT_0080fea4 * 6) * 4);
  iVar5 = DAT_0080ff44 << 4;
  if (pcVar4 != (char *)0x0) {
    cVar1 = *pcVar4;
    while (cVar1 != '\0') {
      pcVar3 = local_204;
      while (cVar1 != '\0') {
        if (cVar1 == '\n') {
          if (*pcVar4 != '\0') {
            pcVar4 = pcVar4 + 1;
          }
          break;
        }
        pcVar4 = pcVar4 + 1;
        *pcVar3 = cVar1;
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar4;
      }
      *pcVar3 = '\0';
      FUN_005f35e0(DAT_009738b8,0x280,iVar5,0x10,local_204);
      FUN_005d0e80(DAT_009738b8);
      iVar2 = FUN_006e6b90();
      iVar5 = iVar5 + iVar2;
      cVar1 = *pcVar4;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_204);
  return;
}

