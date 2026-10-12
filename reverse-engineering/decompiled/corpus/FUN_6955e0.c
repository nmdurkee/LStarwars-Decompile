/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x6955e0; label: FUN_006955e0
 */

undefined4 FUN_006955e0(int param_1,int param_2)

{
  int *in_ECX;
  
  if (param_1 == in_ECX[in_ECX[5] + 1]) {
    return 0;
  }
  in_ECX[5] = (uint)(*(int *)(param_1 + 0x14) == 8);
  FUN_00698400(*in_ECX * 2);
  in_ECX[in_ECX[5] + 1] = param_1;
  in_ECX[in_ECX[5] + 3] = param_2;
  in_ECX[0xc] = in_ECX[0xc] & 0xfffffffd;
  if (in_ECX[6] != 1) {
    in_ECX[6] = 1;
    in_ECX[0xb] = 0;
  }
  return 1;
}

