/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51fdc0; label: FUN_0051fdc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0051fdc0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc4);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = FUN_004f8b10(iVar1 + 8,param_2);
    if (iVar2 == 0) break;
    iVar1 = *(int *)(iVar1 + 0x2c);
  }
  return iVar1;
}

