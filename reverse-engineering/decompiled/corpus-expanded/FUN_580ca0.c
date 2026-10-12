/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x580ca0; label: FUN_00580ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580ca0(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < param_1[1]) {
    iVar4 = 0;
    do {
      *(undefined2 *)(iVar4 + 100 + *param_1) = 0xffff;
      iVar1 = *(int *)(iVar4 + 0x58 + *param_1);
      if (iVar1 != 0) {
        uVar2 = FUN_00650dc0(iVar1);
        *(undefined2 *)(iVar4 + 100 + *param_1) = uVar2;
      }
      *(undefined2 *)(iVar4 + 0x66 + *param_1) = 0xffff;
      iVar1 = *(int *)(iVar4 + 0x5c + *param_1);
      if (iVar1 != 0) {
        uVar2 = FUN_00650dc0(iVar1);
        *(undefined2 *)(iVar4 + 0x66 + *param_1) = uVar2;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xa4;
    } while (iVar3 < param_1[1]);
  }
  PTR_PTR_008040bc = (undefined *)param_1;
  if (param_1[3] == 0) {
    param_1[3] = (int)FUN_00580c00;
  }
  if (*(int *)(PTR_PTR_008040bc + 0x10) == 0) {
    *(code **)(PTR_PTR_008040bc + 0x10) = FUN_00580920;
  }
  if (*(int *)(PTR_PTR_008040bc + 0x14) == 0) {
    *(code **)(PTR_PTR_008040bc + 0x14) = FUN_00580950;
  }
  return;
}

