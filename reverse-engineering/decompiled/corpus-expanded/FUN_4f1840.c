/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1840; label: FUN_004f1840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1840(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  undefined1 *puVar3;
  undefined1 *in_ECX;
  
  iVar1 = *(int *)(in_EAX + 0x24);
  iVar2 = *(int *)(in_EAX + 0x20);
  for (puVar3 = in_ECX + *(int *)(in_EAX + 0x2c) * param_1; puVar3 < (undefined1 *)(iVar1 + iVar2);
      puVar3 = puVar3 + 1) {
    *in_ECX = *puVar3;
    in_ECX = in_ECX + 1;
  }
  return;
}

