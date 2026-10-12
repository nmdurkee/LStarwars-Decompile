/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60c760; label: FUN_0060c760
 */

void FUN_0060c760(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    _free(*(void **)(in_ECX + 4));
  }
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}

