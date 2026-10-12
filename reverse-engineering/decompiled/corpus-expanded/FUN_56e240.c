/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e240; label: FUN_0056e240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056e240(int param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = PTR_DAT_008032c4;
  uVar2 = 0;
  if (0 < param_2) {
    iVar3 = 0;
    do {
      if ((*(uint *)(param_1 + (uVar2 >> 5) * 4) & 1 << ((byte)uVar2 & 0x1f)) == 0) {
        *(undefined1 *)(iVar3 + 8 + *(int *)puVar1) = 0;
      }
      else {
        *(undefined1 *)(iVar3 + 8 + *(int *)puVar1) = 1;
      }
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while ((int)uVar2 < param_2);
  }
  return;
}

