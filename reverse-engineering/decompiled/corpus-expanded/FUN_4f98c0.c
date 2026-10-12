/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f98c0; label: FUN_004f98c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_004f98c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar1 = DAT_0297e064;
  iVar2 = 0;
  while (*(char *)(iVar2 + param_1) != ':') {
    iVar2 = iVar2 + 1;
    if (7 < iVar2) {
      return (undefined4 *)0x0;
    }
  }
  if (7 < iVar2) {
    return (undefined4 *)0x0;
  }
  iVar2 = 0;
  if (0 < DAT_0297e064) {
    puVar4 = &DAT_02980414;
    do {
      iVar3 = FUN_004f8b80(param_1,puVar4,*(undefined4 *)(puVar4 + 0x10));
      if (iVar3 == 0) {
        return &DAT_029803e0 + iVar2 * 0x8d;
      }
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 0x234;
    } while (iVar2 < iVar1);
    return (undefined4 *)0x0;
  }
  return (undefined4 *)0x0;
}

