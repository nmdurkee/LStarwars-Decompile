/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x593810; label: FUN_00593810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00593810(int param_1,int param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  
  if ((param_1 != 0) && ((param_2 != 0 || (param_2 = *(int *)(param_1 + 0x174), param_2 != 0)))) {
    puVar2 = (undefined2 *)(param_2 + 4);
    puVar1 = (undefined2 *)(param_1 + 0xc2a);
    iVar3 = 2;
    do {
      puVar2[-2] = puVar1[-1];
      puVar2[-1] = *puVar1;
      *puVar2 = puVar1[1];
      puVar2[1] = puVar1[2];
      puVar2[2] = puVar1[3];
      puVar2[3] = puVar1[4];
      puVar2[4] = puVar1[5];
      puVar2[5] = puVar1[6];
      puVar2[6] = puVar1[7];
      puVar1 = puVar1 + 10;
      puVar2 = puVar2 + 0x1c;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

