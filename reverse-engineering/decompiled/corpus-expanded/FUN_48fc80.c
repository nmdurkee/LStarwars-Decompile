/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48fc80; label: FUN_0048fc80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

