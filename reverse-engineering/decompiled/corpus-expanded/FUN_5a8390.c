/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8390; label: FUN_005a8390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8390(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  DAT_0095df20 = param_1;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    while (iVar1 != 0) {
      uVar2 = FUN_0055b1c0(*param_1);
      *(undefined2 *)(param_1 + 4) = uVar2;
      param_1 = param_1 + 5;
      iVar1 = *param_1;
    }
  }
  return;
}

