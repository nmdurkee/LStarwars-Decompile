/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c2e40; label: FUN_005c2e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2e40(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[0x27] = 0x3f800000;
  *in_ECX = &PTR_FUN_007643b4;
  return;
}

