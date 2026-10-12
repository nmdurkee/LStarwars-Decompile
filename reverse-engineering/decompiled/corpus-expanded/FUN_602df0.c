/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x602df0; label: FUN_00602df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00602df0(int param_1)

{
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_004ef280(*(int *)(param_1 + 0x20),
                 "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x25d);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}

