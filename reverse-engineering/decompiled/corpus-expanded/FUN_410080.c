/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x410080; label: FUN_00410080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00410080(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  
  if (0 < in_ECX) {
    puVar1 = (undefined4 *)(in_EAX + 0xd0);
    do {
      puVar1[0x10] = 0;
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1 = puVar1 + 0x4c;
      in_ECX = in_ECX + -1;
    } while (in_ECX != 0);
  }
  return;
}

