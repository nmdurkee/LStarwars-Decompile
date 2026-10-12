/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61aa10; label: FUN_0061aa10
 */

void FUN_0061aa10(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x4c);
  do {
    if (iVar2 == 0) {
      FUN_004ef280(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xa9b);
      return;
    }
    piVar1 = *(int **)(param_2 + 0x4c);
    if ((int *)piVar1[1] == (int *)0x0) {
      *(int *)(param_2 + 0x4c) = *piVar1;
    }
    else {
      *(int *)piVar1[1] = *piVar1;
    }
    if (*piVar1 == 0) {
LAB_0061aa47:
      iVar2 = piVar1[1];
    }
    else {
      *(int *)(*piVar1 + 4) = piVar1[1];
      iVar2 = *piVar1;
      if (iVar2 == 0) goto LAB_0061aa47;
    }
    *(int *)(param_2 + 0x50) = iVar2;
    FUN_004ef280(piVar1,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xa70);
    iVar2 = *(int *)(param_2 + 0x4c);
  } while( true );
}

