/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e1d0; label: FUN_0056e1d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056e1d0(void *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  _memset(param_1,0,((int)(param_2 + 0x1f + (param_2 + 0x1f >> 0x1f & 0x1fU)) >> 5) * 4);
  uVar2 = 0;
  if (0 < param_2) {
    iVar3 = 0;
    do {
      if (*(char *)(iVar3 + 8 + *(int *)PTR_DAT_008032c4) != '\0') {
        puVar1 = (uint *)((int)param_1 + (uVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)uVar2 & 0x1f);
      }
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while ((int)uVar2 < param_2);
  }
  return;
}

