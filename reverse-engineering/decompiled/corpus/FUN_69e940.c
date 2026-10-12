/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69e940; label: FUN_0069e940
 */

int FUN_0069e940(void)

{
  undefined4 *in_EAX;
  int iVar1;
  
  if (in_EAX[0x16] != 1) {
    return -0x83;
  }
  in_EAX[0x16] = 2;
  if (in_EAX[1] != 0) {
    iVar1 = FUN_0069e700();
    if (iVar1 != 0) {
      *in_EAX = 0;
      FUN_0069c3c0();
    }
    return iVar1;
  }
  in_EAX[0x16] = 3;
  return 0;
}

