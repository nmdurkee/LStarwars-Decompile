/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x479e80; label: FUN_00479e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00479e80(int param_1)

{
  if ((((*(char *)(param_1 + 0x14) == '\0') && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94))
      && (_DAT_00950780 == 0.0)) && (DAT_0086e4e5 != '\0')) {
    *(undefined1 *)(param_1 + 3) = 4;
    return 1;
  }
  return 0;
}

