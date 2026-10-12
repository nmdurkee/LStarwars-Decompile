/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612990; label: FUN_00612990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612990(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined2 *puVar3;
  
  iVar2 = 0x800;
  puVar3 = (undefined2 *)(in_ECX + 0x30);
  do {
    if (puVar3[1] != 0) {
      (**(code **)(**(int **)(*(int *)(puVar3 + 8) + 0x14) + 0x28))(*(undefined4 *)(puVar3 + 6),0);
      iVar1 = FUN_006be780(*(undefined4 *)(puVar3 + 8));
      if (0 < *(int *)(&DAT_02867f1c + iVar1 * 4)) {
        FUN_006334d0(*(undefined4 *)(puVar3 + 10),*(int *)(&DAT_02867f1c + iVar1 * 4));
        *(undefined4 *)(puVar3 + 10) = 0;
      }
      puVar3[1] = 0;
      *(undefined4 *)(puVar3 + 6) = 0;
      *(undefined4 *)(puVar3 + 8) = 0;
      *(undefined4 *)(puVar3 + 4) = 0;
      *puVar3 = 0;
    }
    puVar3 = puVar3 + 0xc;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _memset((void *)(in_ECX + 0xc034),0,0x1000);
  *(undefined4 *)(in_ECX + 0xc030) = 0;
  _memset((undefined2 *)(in_ECX + 0x30),0,0xc000);
  if (param_1 != 0) {
    FUN_006c4470();
  }
  return;
}

