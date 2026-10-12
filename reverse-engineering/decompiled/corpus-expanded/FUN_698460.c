/* Ghidra pseudocode, not original source.
 * ev_d64f82d79bd9036ef98f897f1d4209ad19800693bd01752bbb2d417690313147
 * Entry: 0x698460; label: FUN_00698460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00698460(void)

{
  int iVar1;
  
  iVar1 = FUN_006e6b90();
  iVar1 = iVar1 + _DAT_00810dbc;
  if (iVar1 < -10000) {
    iVar1 = -10000;
  }
  FUN_00699710(iVar1);
  return;
}

