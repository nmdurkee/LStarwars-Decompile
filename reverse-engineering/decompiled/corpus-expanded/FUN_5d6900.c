/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d6900; label: FUN_005d6900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d6900(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((param_1 != DAT_0097394c) && (DAT_0097394c == 0)) {
    puVar2 = &DAT_009736e8;
    puVar3 = &DAT_00971b00;
    for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  if (param_1 != 0) {
    puVar2 = &DAT_009736e8;
    puVar3 = &DAT_00973760;
    for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_00603cc0(&DAT_00971b00);
  }
  DAT_0097394c = param_1;
  return;
}

