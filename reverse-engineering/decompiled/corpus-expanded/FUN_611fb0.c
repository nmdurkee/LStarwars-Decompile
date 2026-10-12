/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611fb0; label: FUN_00611fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611fb0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,int param_5,
                 int param_6)

{
  undefined4 *puVar1;
  int in_ECX;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (3 < param_6) {
    puVar3 = (undefined4 *)(param_5 + 0xc);
    iVar5 = (param_6 - 4U >> 2) + 1;
    piVar2 = (int *)(param_4 + 4);
    iVar4 = iVar5 * 4;
    do {
      puVar1 = (undefined4 *)piVar2[-1];
      *puVar1 = puVar1[1];
      puVar1[1] = puVar1[2];
      puVar1[2] = puVar3[-3];
      if ((0.0 < *(float *)(in_ECX + 0x1c)) &&
         (*(float *)(in_ECX + 0x1c) < *(float *)(piVar2[-1] + 8) - *(float *)(piVar2[-1] + 4))) {
        *param_3 = 0;
      }
      puVar1 = (undefined4 *)*piVar2;
      *puVar1 = puVar1[1];
      puVar1[1] = puVar1[2];
      puVar1[2] = *(undefined4 *)((int)piVar2 + (param_5 - param_4));
      if ((0.0 < *(float *)(in_ECX + 0x1c)) &&
         (*(float *)(in_ECX + 0x1c) < *(float *)(*piVar2 + 8) - *(float *)(*piVar2 + 4))) {
        *param_3 = 0;
      }
      puVar1 = (undefined4 *)piVar2[1];
      *puVar1 = puVar1[1];
      puVar1[1] = puVar1[2];
      puVar1[2] = puVar3[-1];
      if ((0.0 < *(float *)(in_ECX + 0x1c)) &&
         (*(float *)(in_ECX + 0x1c) < *(float *)(piVar2[1] + 8) - *(float *)(piVar2[1] + 4))) {
        *param_3 = 0;
      }
      puVar1 = (undefined4 *)piVar2[2];
      *puVar1 = puVar1[1];
      puVar1[1] = puVar1[2];
      puVar1[2] = *puVar3;
      if ((0.0 < *(float *)(in_ECX + 0x1c)) &&
         (*(float *)(in_ECX + 0x1c) < *(float *)(piVar2[2] + 8) - *(float *)(piVar2[2] + 4))) {
        *param_3 = 0;
      }
      piVar2 = piVar2 + 4;
      puVar3 = puVar3 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (iVar4 < param_6) {
    param_6 = param_6 - iVar4;
    piVar2 = (int *)(param_4 + iVar4 * 4);
    do {
      puVar3 = (undefined4 *)*piVar2;
      *puVar3 = puVar3[1];
      puVar3[1] = puVar3[2];
      puVar3[2] = *(undefined4 *)((int)piVar2 + (param_5 - param_4));
      if ((0.0 < *(float *)(in_ECX + 0x1c)) &&
         (*(float *)(in_ECX + 0x1c) < *(float *)(*piVar2 + 8) - *(float *)(*piVar2 + 4))) {
        *param_3 = 0;
      }
      piVar2 = piVar2 + 1;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}

