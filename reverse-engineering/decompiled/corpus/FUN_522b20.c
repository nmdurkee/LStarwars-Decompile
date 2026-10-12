/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x522b20; label: FUN_00522b20
 */

void FUN_00522b20(int param_1)

{
  undefined4 *in_EAX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 != 0) {
    FUN_00620f10();
    return;
  }
  local_c = *in_EAX;
  local_8 = *(undefined4 *)(DAT_009238e4 + 0x14);
  local_4 = in_EAX[2];
  FUN_00620f10(&local_c);
  return;
}

