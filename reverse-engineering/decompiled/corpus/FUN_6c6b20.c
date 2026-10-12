/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6b20; label: FUN_006c6b20
 */

void FUN_006c6b20(void)

{
  char *pcVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076fa04;
  pcVar1 = (char *)in_ECX[4];
  if (pcVar1 != (char *)0x0) {
    FUN_006334d0(pcVar1,(int)*pcVar1);
  }
  pcVar1 = (char *)in_ECX[3];
  if (pcVar1 != (char *)0x0) {
    FUN_006334d0(pcVar1,(int)*pcVar1);
  }
  return;
}

