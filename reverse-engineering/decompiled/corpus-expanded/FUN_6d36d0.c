/* Ghidra pseudocode, not original source.
 * ev_5667e5448bcdd65d51b4846c6b703f5dc39afd73914fbe1d2cb4bfca537c9b4f
 * Entry: 0x6d36d0; label: FUN_006d36d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d36d0(void)

{
  undefined2 *puVar1;
  int in_ECX;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  
  puVar3 = (undefined2 *)(in_ECX + 0x4f24);
  iVar4 = 0xe;
  do {
    iVar2 = 0x20;
    puVar1 = puVar3;
    do {
      puVar1[-1] = 0;
      *puVar1 = 0;
      puVar1 = puVar1 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar3 = puVar3 + 0xbe;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

