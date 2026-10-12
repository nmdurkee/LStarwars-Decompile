/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c8f70; label: FUN_005c8f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c8f70(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(in_ECX + 0x2dc);
  iVar2 = 6;
  do {
    FUN_00605ad0(*puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00605ad0(*(undefined4 *)(in_ECX + 0x2f4));
  FUN_00605ad0(*(undefined4 *)(in_ECX + 8));
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}

