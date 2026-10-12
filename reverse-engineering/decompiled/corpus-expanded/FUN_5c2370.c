/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2370; label: FUN_005c2370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2370(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(param_1 + 0x10);
  return;
}

