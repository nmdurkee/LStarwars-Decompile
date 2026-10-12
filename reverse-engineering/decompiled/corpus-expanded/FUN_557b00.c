/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x557b00; label: FUN_00557b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00557b00(void)

{
  undefined4 *puVar1;
  int in_EAX;
  int in_EDX;
  
  if (*(char *)(in_EDX + 0x92) < '\0') {
    if ((*(byte *)(in_EDX + 0x68) & 0x10) == 0) {
      return 1;
    }
    if ((*(char *)(in_EAX + 0x281) != '\0') || ((*(uint *)(in_EAX + 0xef4) & 0x20000000) != 0)) {
      if ((-1 < *(short *)(in_EAX + 0x27e)) &&
         ((*(int *)(in_EDX + 0x34) != 0 && ((*(byte *)(in_EDX + 0x9c) & 0x10) != 0)))) {
        for (puVar1 = *(undefined4 **)(*(int *)(in_EDX + 0x34) + 0x18); puVar1 != (undefined4 *)0x0;
            puVar1 = (undefined4 *)*puVar1) {
          if (*(short *)(puVar1[9] + 2) == *(short *)(in_EAX + 0x27e)) {
            return 1;
          }
        }
      }
      return 0;
    }
  }
  else if (((*(char *)(in_EAX + 0x281) != '\0') || ((*(uint *)(in_EAX + 0xef4) & 0x20000000) != 0))
          && (*(char *)(in_EAX + 0x285) == *(char *)(in_EDX + 0x92))) {
    return 1;
  }
  return 0;
}

