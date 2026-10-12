/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x48fc80; label: FUN_0048fc80
 */

void FUN_0048fc80(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = *(char *)(in_ECX + 0x96);
  if (cVar1 == 'r') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x22;
    return;
  }
  if (cVar1 == 'o') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x21;
    return;
  }
  if (cVar1 == 'y') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x20;
    return;
  }
  if (cVar1 == 'b') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x23;
    return;
  }
  if (cVar1 == 'g') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x24;
    return;
  }
  if (cVar1 == 'p') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x25;
    return;
  }
  if (cVar1 == 'w') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x26;
    return;
  }
  if (cVar1 == 'u') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x27;
    return;
  }
  if (cVar1 == 'l') {
    *(undefined2 *)(in_ECX + 0x8a) = 0x28;
  }
  return;
}

