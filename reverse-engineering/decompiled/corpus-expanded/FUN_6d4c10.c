/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4c10; label: FUN_006d4c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d4c10(void)

{
  undefined4 *puVar1;
  int in_ECX;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)(in_ECX + 0x6345);
  puVar1 = (undefined4 *)(in_ECX + 0x660c);
  iVar3 = 0xe;
  do {
    *(undefined4 *)((int)puVar1 + -0x96) = *puVar1;
    *(undefined4 *)((int)puVar1 + -0x92) = puVar1[1];
    *(undefined2 *)((int)puVar1 + -0x8e) = *(undefined2 *)(puVar1 + 2);
    *(undefined1 *)((int)puVar1 + 2) = 0;
    *(undefined1 *)puVar1 = 0;
    *(undefined1 *)((int)puVar1 + 1) = 0;
    if ((*pcVar2 != '\0') &&
       (((*pcVar2 = *pcVar2 + -1, *(char *)(puVar1 + -0x25) != '\0' ||
         (*(char *)((int)puVar1 + -0x96) != '\0')) || (*(char *)((int)puVar1 + -0x95) != '\0')))) {
      *pcVar2 = '\x05';
    }
    puVar1 = (undefined4 *)((int)puVar1 + 10);
    pcVar2 = pcVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(in_ECX + 0x4e0c) = 0;
  return;
}

