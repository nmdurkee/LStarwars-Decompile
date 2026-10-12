/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74bdd0; label: FUN_0074bdd0
 */

undefined4 FUN_0074bdd0(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == 0) || (*in_ECX != *param_1)) {
    FUN_006e9fe6();
  }
  return CONCAT31((int3)((uint)in_ECX[1] >> 8),in_ECX[1] != param_1[1]);
}

