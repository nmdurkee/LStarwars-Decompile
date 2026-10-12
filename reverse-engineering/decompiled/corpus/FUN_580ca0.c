/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x580ca0; label: FUN_00580ca0
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

