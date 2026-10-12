/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44e860; label: FUN_0044e860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044e860(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5,
            int param_6)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) &&
     (((iVar2 = *piVar1, param_6 != 0 && (param_5 == 1)) &&
      (sVar3 = FUN_0062e000(*(undefined4 *)(iVar2 + 0x54),*param_4), sVar3 != -1)))) {
    FUN_0062e650(iVar2 + 8,(int)sVar3);
  }
  return 1;
}

