/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c9a90; label: FUN_006c9a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c9a90(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_006c99a0();
  }
  FUN_0061e5d0(1);
  if (DAT_02973a7c != 0) {
    if (*(int *)(DAT_02973a7c + 0x40) != 0) {
      *(undefined4 *)(*(int *)(DAT_02973a7c + 0x40) + 0x3c) = 0;
    }
    if (*(int *)(DAT_02973a7c + 0x3c) != 0) {
      *(undefined4 *)(*(int *)(DAT_02973a7c + 0x3c) + 0x40) = 0;
    }
  }
  DAT_02973a88 = 1;
  return;
}

