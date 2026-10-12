/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61aa10; label: FUN_0061aa10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

