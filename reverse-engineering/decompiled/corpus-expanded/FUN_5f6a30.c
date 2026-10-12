/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f6a30; label: FUN_005f6a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f6a30(int param_1)

{
  if ((*(int *)(param_1 + 0x40) != 0) && (0 < *(int *)(param_1 + 0x44))) {
    FUN_005f5830(*(undefined4 *)
                  (*(int *)(*(int *)(param_1 + 0x40) + -4 + *(int *)(param_1 + 0x44) * 4) + 0x110));
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
    return;
  }
  FUN_005f5830(*(undefined4 *)(param_1 + 0x110));
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
  return;
}

