/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c9bf0; label: FUN_006c9bf0
 */

undefined4 FUN_006c9bf0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 local_4;
  
  local_4 = 0;
  if (param_2 == 1) {
    if (param_1[1] == 0) goto LAB_006c9dcc;
    for (puVar3 = *(undefined4 **)(in_ECX + 0x24); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      if ((puVar3[3] == param_1[1]) && (puVar3[4] == param_1[2])) {
        if (puVar3 != (undefined4 *)0x0) {
          FUN_006c14b0(puVar3);
          FUN_006334d0(puVar3,0x14);
          goto LAB_006c9dcc;
        }
        break;
      }
    }
    puVar3 = (undefined4 *)FUN_00633440(0x14,1);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[2] = *param_1;
      puVar3[3] = param_1[1];
      puVar3[4] = param_1[2];
      *puVar3 = 0;
      puVar3[1] = *(undefined4 *)(in_ECX + 0x28);
      if (*(undefined4 **)(in_ECX + 0x28) != (undefined4 *)0x0) {
        **(undefined4 **)(in_ECX + 0x28) = puVar3;
      }
      *(undefined4 **)(in_ECX + 0x28) = puVar3;
      if (*(int *)(in_ECX + 0x24) == 0) {
        *(int *)(in_ECX + 0x24) = (int)puVar3;
      }
      *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
    }
  }
  else {
    piVar1 = *(int **)(in_ECX + 0x24);
    if (param_2 == 2) {
      while (piVar2 = piVar1, piVar2 != (int *)0x0) {
        piVar1 = (int *)*piVar2;
        if (piVar2[3] == param_1[1]) {
          if (piVar1 == (int *)0x0) {
            *(int *)(in_ECX + 0x28) = piVar2[1];
          }
          else {
            piVar1[1] = piVar2[1];
          }
          if ((int *)piVar2[1] == (int *)0x0) {
            *(int *)(in_ECX + 0x24) = *piVar2;
          }
          else {
            *(int *)piVar2[1] = *piVar2;
          }
          *piVar2 = 0;
          piVar2[1] = 0;
          *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
          FUN_006334d0(piVar2,0x14);
        }
      }
    }
    else {
      while (piVar1 != (int *)0x0) {
        if (*piVar1 == 0) {
          *(int *)(in_ECX + 0x28) = piVar1[1];
        }
        else {
          *(int *)(*piVar1 + 4) = piVar1[1];
        }
        if ((int *)piVar1[1] == (int *)0x0) {
          *(int *)(in_ECX + 0x24) = *piVar1;
        }
        else {
          *(int *)piVar1[1] = *piVar1;
        }
        *piVar1 = 0;
        piVar1[1] = 0;
        *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
        FUN_006334d0(piVar1,0x14);
        piVar1 = *(int **)(in_ECX + 0x24);
      }
    }
    if ((param_1[1] != 0) &&
       (puVar3 = (undefined4 *)FUN_00633440(0x14,1), puVar3 != (undefined4 *)0x0)) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[2] = *param_1;
      puVar3[3] = param_1[1];
      puVar3[4] = param_1[2];
      *puVar3 = 0;
      puVar3[1] = *(undefined4 *)(in_ECX + 0x28);
      if (*(undefined4 **)(in_ECX + 0x28) != (undefined4 *)0x0) {
        **(undefined4 **)(in_ECX + 0x28) = puVar3;
      }
      *(undefined4 **)(in_ECX + 0x28) = puVar3;
      if (*(int *)(in_ECX + 0x24) == 0) {
        *(undefined4 **)(in_ECX + 0x24) = puVar3;
      }
      *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
    }
  }
  local_4 = 1;
LAB_006c9dcc:
  FUN_006c58a0(*(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x10));
  return local_4;
}

