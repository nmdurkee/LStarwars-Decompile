/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619d10; label: FUN_00619d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619d10(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  bool bVar3;
  bool bVar4;
  
  *(int *)(in_EAX + 0x150) = *(int *)(in_EAX + 0x150) + 1;
  iVar1 = *(int *)(in_EAX + 0x150);
  if ((*(byte *)(in_EAX + 0x164) & 2) == 0) {
    bVar4 = SBORROW4(iVar1,3);
    iVar2 = -3;
    bVar3 = iVar1 == 3;
  }
  else {
    bVar4 = SBORROW4(iVar1,5);
    iVar2 = -5;
    bVar3 = iVar1 == 5;
  }
  if (!bVar3 && bVar4 == iVar1 + iVar2 < 0) {
    *(undefined4 *)(in_EAX + 0x150) = 0;
  }
  return;
}

