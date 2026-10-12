/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60c3c0; label: FUN_0060c3c0
 */

void FUN_0060c3c0(byte param_1)

{
  undefined4 *in_ECX;
  
  FUN_005fb810();
  (&DAT_00986a88)[*(short *)(in_ECX + 0x50)] = 0;
  *in_ECX = &PTR_LAB_007642a4;
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

