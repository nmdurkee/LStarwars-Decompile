/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7bc0; label: FUN_006c7bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c7bc0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar2 = param_2;
  piVar1 = param_1;
  if (param_1[2] == 2) {
    iVar4 = *param_1;
    param_1 = *(int **)(param_2 + 0x34);
    (**(code **)(iVar4 + 8))(&param_1,4,1);
    for (puVar3 = *(undefined4 **)(iVar2 + 0x2c); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      FUN_006c6540(piVar1,puVar3);
    }
  }
  if (piVar1[2] == 1) {
    (**(code **)(*piVar1 + 8))(&param_1,4,1);
    iVar4 = 0;
    if (0 < unaff_ESI) {
      do {
        puVar3 = (undefined4 *)FUN_00633440(0x50,1);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = 0;
          puVar3[1] = 0;
          *(undefined2 *)(puVar3 + 0x11) = DAT_02973aa0;
        }
        FUN_006c6540(piVar1,puVar3);
        if (puVar3 != (undefined4 *)0x0) {
          puVar3[0x10] = iVar2;
          *puVar3 = 0;
          puVar3[1] = *(undefined4 *)(iVar2 + 0x30);
          if (*(undefined4 **)(iVar2 + 0x30) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar2 + 0x30) = puVar3;
          }
          *(undefined4 **)(iVar2 + 0x30) = puVar3;
          if (*(int *)(iVar2 + 0x2c) == 0) {
            *(undefined4 **)(iVar2 + 0x2c) = puVar3;
          }
          *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x34) + 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < unaff_ESI);
    }
  }
  return;
}

