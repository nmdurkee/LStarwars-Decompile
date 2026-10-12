/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746810; label: FUN_00746810
 */

void FUN_00746810(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined1 *puVar3;
  
  piVar1 = in_ECX + in_ECX[300];
  for (; in_ECX != piVar1; in_ECX = in_ECX + 1) {
    puVar2 = (undefined4 *)*in_ECX;
    if (*(char *)(puVar2 + 2) != '\0') {
      puVar3 = (undefined1 *)puVar2[1];
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_007516c0;
      }
      FUN_007486b0("#define ");
      FUN_007486b0(*puVar2);
      FUN_007486b0(&DAT_007596f8);
      FUN_007486b0(puVar3);
      FUN_007486b0(&DAT_0076aa4c);
    }
  }
  return;
}

