/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b2cf0; label: FUN_005b2cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b2cf0(int param_1)

{
  if (((_DAT_008028ac != -1) && (*(char *)(param_1 + 0x7b5) == _DAT_008028ac)) &&
     (*(int *)(param_1 + 0x798) != 0)) {
    *(undefined4 *)(param_1 + 0x748) = DAT_008024f4;
    *(undefined4 *)(param_1 + 0x74c) = DAT_008024f8;
    *(undefined4 *)(param_1 + 0x750) = DAT_008024fc;
    *(undefined4 *)(param_1 + 0x754) = DAT_00802500;
    *(undefined4 *)(param_1 + 0x758) = DAT_00802504;
    *(undefined4 *)(param_1 + 0x75c) = DAT_00802508;
    *(undefined4 *)(param_1 + 0x760) = DAT_0080250c;
    *(undefined4 *)(param_1 + 0x764) = DAT_00802510;
    *(undefined4 *)(param_1 + 0x768) = DAT_00802514;
    FUN_005980c0(param_1,1);
  }
  return;
}

