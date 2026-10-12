/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x605ad0; label: FUN_00605ad0
 */

void FUN_00605ad0(undefined *param_1)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(param_1 + 8);
  iVar5 = 5;
  do {
    iVar3 = iVar5;
    if ((piVar4[-2] == 0) || (*(int *)(piVar4[-2] + 0x28) == 0)) {
      piVar1 = (int *)*piVar4;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        goto LAB_00605afc;
      }
    }
    else {
LAB_00605afc:
      *piVar4 = 0;
    }
    if ((piVar4[-2] != 0) && ((char)piVar4[-1] != '\0')) {
      FUN_005f7b40(piVar4[-2]);
    }
    piVar4[-2] = 0;
    *(undefined1 *)(piVar4 + -1) = 0;
    *(undefined2 *)(piVar4 + 1) = 0;
    piVar4[2] = 0;
    *(undefined2 *)(piVar4 + 3) = 0;
    *(undefined2 *)((int)piVar4 + 0xe) = 0;
    piVar4 = piVar4 + 7;
    iVar5 = iVar3 + -1;
    if (iVar5 == 0) {
      iVar5 = 0;
      puVar2 = &DAT_02855358;
      iVar3 = iVar3 + 0x1f;
      do {
        if (puVar2 == param_1) {
          (&DAT_028490b0)[iVar5] = 0;
        }
        iVar5 = iVar5 + 1;
        puVar2 = puVar2 + 0xa4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      return;
    }
  } while( true );
}

