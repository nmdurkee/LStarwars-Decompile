/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64afd0; label: FUN_0064afd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0064afd0(char *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    iVar3 = 0;
    puVar2 = &DAT_02913a58;
    do {
      iVar1 = FUN_004f8b80(param_1,puVar2,0x10);
      if (iVar1 == 0) {
        return iVar3;
      }
      puVar2 = puVar2 + 0x178;
      iVar3 = iVar3 + 1;
    } while ((int)puVar2 < 0x291f658);
    return -1;
  }
  return -1;
}

