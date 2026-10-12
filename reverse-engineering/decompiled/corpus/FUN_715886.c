/* Ghidra analysis pseudocode, not original source.
 * ev_184ff99a51593b5727527cffebd3a7fadc537097cd097c26104c250d652dc9a5
 * Entry: 0x715886; label: FUN_00715886
 */

undefined4 FUN_00715886(char *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = param_2;
  if (param_2 != 0) {
    do {
      if (*param_1 == '\0') break;
      param_1 = param_1 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (iVar1 != 0) {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      *param_3 = param_2 - iVar1;
      return 0;
    }
  }
  return 0x80070057;
}

