/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b4270; label: FUN_006b4270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_006b4270(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_5) {
    puVar1 = param_3;
    do {
      if (*(int *)((param_4 - (int)param_3) + (int)puVar1) != 0) {
        param_3[iVar3] = *puVar1;
        iVar3 = iVar3 + 1;
      }
      puVar1 = puVar1 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    if (iVar3 != 0) {
      uVar2 = FUN_006b4080();
      return uVar2;
    }
  }
  return 0;
}

