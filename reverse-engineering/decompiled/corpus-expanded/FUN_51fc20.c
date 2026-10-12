/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51fc20; label: FUN_0051fc20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051fc20(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    for (iVar1 = FUN_004f1440(param_1 + 0x10); iVar1 != 0;
        iVar1 = FUN_004f1460(param_1 + 0x10,iVar1)) {
      *(undefined4 *)(iVar1 + 0x28) = 0;
    }
  }
  return;
}

