/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x605a10; label: FUN_00605a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_00605a10(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  iVar2 = 0;
  while ((&DAT_028490b0)[iVar2] != '\0') {
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x20) {
      FUN_005f7490();
      return (undefined *)0x0;
    }
  }
  (&DAT_028490b0)[iVar2] = 1;
  iVar2 = iVar2 * 0xa4;
  if (&DAT_02855358 + iVar2 == (undefined *)0x0) {
    FUN_005f7490();
    return (undefined *)0x0;
  }
  puVar5 = (undefined4 *)(iVar2 + 0x28553e4);
  piVar4 = (int *)(iVar2 + 0x2855360);
  iVar3 = 5;
  do {
    if ((piVar4[-2] == 0) || (*(int *)(piVar4[-2] + 0x28) == 0)) {
      piVar1 = (int *)*piVar4;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        goto LAB_00605a7d;
      }
    }
    else {
LAB_00605a7d:
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
    *puVar5 = 0xffffffff;
    puVar5 = puVar5 + 1;
    piVar4 = piVar4 + 7;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      *(undefined4 *)(iVar2 + 0x28553f8) = 1;
      return &DAT_02855358 + iVar2;
    }
  } while( true );
}

