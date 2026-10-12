/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f7830; label: FUN_004f7830
 */

void FUN_004f7830(char param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *extraout_ECX;
  char *pcVar6;
  char *unaff_EDI;
  
  iVar2 = DAT_0088ab38;
  if (0x3f < DAT_0088ab38) {
    FUN_004ef790();
  }
  iVar4 = iVar2 * 0x10;
  iVar3 = 0;
  pcVar5 = &DAT_0090fba8 + iVar4;
  cVar1 = *unaff_EDI;
  while (cVar1 != '\0') {
    iVar3 = iVar3 + 1;
    cVar1 = unaff_EDI[iVar3];
  }
  (&DAT_0090fbb7)[iVar4] = (char)iVar3;
  pcVar6 = pcVar5;
  if (0xc < iVar3) {
    iVar3 = FUN_004ef790(0xd);
    pcVar5 = extraout_ECX;
    pcVar6 = extraout_ECX;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar5 = unaff_EDI[iVar3 + -1];
    pcVar5 = pcVar5 + 1;
  }
  *pcVar5 = '\0';
  DAT_0088ab38 = iVar2 + 1;
  pcVar6[0xd] = param_1;
  pcVar6[0xe] = param_2;
  return;
}

