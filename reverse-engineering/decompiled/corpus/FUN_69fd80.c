/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69fd80; label: FUN_0069fd80
 */

void FUN_0069fd80(void)

{
  undefined1 uVar1;
  int in_EAX;
  undefined1 *in_ECX;
  
  for (; in_EAX != 0; in_EAX = in_EAX + -1) {
    uVar1 = FUN_006a3bb0();
    *in_ECX = uVar1;
    in_ECX = in_ECX + 1;
  }
  return;
}

