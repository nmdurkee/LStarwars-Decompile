/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c21a0; label: FUN_006c21a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c21a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076fa04;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined2 *)((int)in_ECX + 6) = DAT_02973aa0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  return;
}

