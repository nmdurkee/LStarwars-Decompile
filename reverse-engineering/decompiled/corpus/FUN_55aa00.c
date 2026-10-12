/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55aa00; label: FUN_0055aa00
 */

undefined4 FUN_0055aa00(char *param_1,undefined1 *param_2)

{
  char cVar1;
  char cVar2;
  
  if ((param_1 != (char *)0x0) && (param_2 != (undefined1 *)0x0)) {
    cVar1 = *param_1;
    while( true ) {
      if (cVar1 == '\0') {
        return 1;
      }
      cVar1 = FUN_004f2d80(cVar1);
      cVar2 = FUN_004f2d80(*param_2);
      if (cVar1 != cVar2) break;
      cVar1 = param_1[1];
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    return 0;
  }
  return 0;
}

