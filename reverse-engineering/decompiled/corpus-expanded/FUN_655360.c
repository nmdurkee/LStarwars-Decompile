/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x655360; label: FUN_00655360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00655360(int param_1)

{
  if (param_1 != -1) {
    *(undefined1 *)(*(int *)(DAT_0296209c + param_1 * 4) + 0x2f) = 1;
  }
  return;
}

