/* Ghidra analysis pseudocode, not original source.
 * ev_32b79db0f23450a9ff94a1f71da0489d6fe83df38c9fcaa5c40c5fee2e58dea2
 * Entry: 0x698460; label: FUN_00698460
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

