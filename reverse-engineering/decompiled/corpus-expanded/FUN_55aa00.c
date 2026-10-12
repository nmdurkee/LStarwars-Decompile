/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55aa00; label: FUN_0055aa00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

