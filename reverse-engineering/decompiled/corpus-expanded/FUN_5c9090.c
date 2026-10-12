/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9090; label: FUN_005c9090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c9090(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(in_ECX + 0x2dc);
  iVar1 = 2;
  do {
    iVar3 = iVar1;
    FUN_00605b60(*puVar2,0,0,0);
    FUN_00605b60(*puVar2,4,0,0);
    puVar2 = puVar2 + 1;
    iVar1 = iVar3 + -1;
  } while (iVar1 != 0);
  FUN_00605b60(*(undefined4 *)(in_ECX + 0x2f4),0,0,0);
  FUN_005f7b40(*(undefined4 *)(in_ECX + 0x30));
  FUN_005f7b40(*(undefined4 *)(in_ECX + 0x34));
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  FUN_005f7b40(*(undefined4 *)(in_ECX + 0x2c));
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  puVar2 = (undefined4 *)(in_ECX + 0x38);
  iVar3 = iVar3 + 1;
  do {
    FUN_005f7b40(*puVar2);
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

