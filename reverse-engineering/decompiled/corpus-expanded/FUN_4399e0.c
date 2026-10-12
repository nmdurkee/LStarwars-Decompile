/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x4399e0; label: FUN_004399e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004399e0(int param_1,undefined4 *param_2)

{
  if ((param_1 == 0) ||
     (((((*(uint *)(param_1 + 0x1fc) & 1) != 0 && ((*(uint *)(param_1 + 0x1fc) & 0x1000) != 0)) &&
       ((*(byte *)(param_1 + 0x1f8) & 5) == 0)) &&
      ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8000) == 0)))) {
    DAT_00876cd8 = param_1;
    _DAT_00876cb8 = *param_2;
    _DAT_00876cbc = param_2[1];
    _DAT_00876cc0 = param_2[2];
    _DAT_00876cdc = _DAT_007f6728;
  }
  return;
}

