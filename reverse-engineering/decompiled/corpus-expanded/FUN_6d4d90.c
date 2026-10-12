/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4d90; label: FUN_006d4d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d4d90(void)

{
  undefined1 *puVar1;
  int in_ECX;
  int iVar2;
  
  puVar1 = (undefined1 *)(in_ECX + 0x67f2);
  iVar2 = 0x20;
  do {
    puVar1[-2] = 0;
    *puVar1 = 0xff;
    puVar1[-1] = 0xff;
    *(undefined2 *)(puVar1 + 2) = 0;
    puVar1 = puVar1 + 6;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(in_ECX + 0x67e4) = 0;
  return;
}

