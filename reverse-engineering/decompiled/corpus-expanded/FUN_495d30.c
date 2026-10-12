/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x495d30; label: FUN_00495d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00495d30(int param_1)

{
  if (*(int *)(param_1 + 100) == 0) {
    if (*(int *)(param_1 + 0x68) == 0) {
      return;
    }
  }
  else if (*(int *)(param_1 + 0x34) == 0) {
    FUN_00575450();
    FUN_0055ddc0(PTR_DAT_00802c54);
    FUN_0055c5f0();
    _DAT_0093b2ac = _DAT_0093b2ac | 0x21;
    DAT_008765c4 = 1;
    DAT_00800940 = FUN_00547990(0x30);
    return;
  }
  FUN_00509ab0();
  DAT_00800940 = FUN_00547990(0x31);
  return;
}

