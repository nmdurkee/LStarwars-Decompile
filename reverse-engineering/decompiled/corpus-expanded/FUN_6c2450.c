/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2450; label: FUN_006c2450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2450(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX + 1 != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_0076fa4c;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  *(undefined2 *)(in_ECX + 0x11) = DAT_02973aa0;
  return;
}

