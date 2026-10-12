/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x6030f0; label: FUN_006030f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006030f0(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  if (piVar2 != (int *)0x0) {
    do {
      iVar1 = piVar2[1];
      *(uint *)(iVar1 + 0x44) =
           *(uint *)(iVar1 + 0x44) & 0xffffff9f | (param_2 & 1) << 5 | (param_3 & 1) << 6;
      FUN_005e4b00(iVar1);
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
  }
  return;
}

