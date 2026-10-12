/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a5b00; label: FUN_004a5b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a5b00(int param_1)

{
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xffffbfff | 0x80;
  FUN_0064a740();
  return;
}

