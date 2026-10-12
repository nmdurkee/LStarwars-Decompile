/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64b020; label: FUN_0064b020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0064b020(char *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    return -1;
  }
  if (param_2 - 1U < 7) {
    iVar3 = 0;
    puVar2 = &DAT_02913a58;
    do {
      if (((char)puVar2[0xb2] == param_2) && (iVar1 = FUN_004f8b80(param_1,puVar2,0x10), iVar1 == 0)
         ) {
        return iVar3;
      }
      puVar2 = puVar2 + 0x178;
      iVar3 = iVar3 + 1;
    } while ((int)puVar2 < 0x291f658);
  }
  iVar3 = 0;
  puVar2 = &DAT_02913a58;
  while ((puVar2[0xb2] != '\0' || (iVar1 = FUN_004f2130(param_1,puVar2,0x10), iVar1 != 0))) {
    puVar2 = puVar2 + 0x178;
    iVar3 = iVar3 + 1;
    if (0x291f657 < (int)puVar2) {
      return -1;
    }
  }
  return iVar3;
}

