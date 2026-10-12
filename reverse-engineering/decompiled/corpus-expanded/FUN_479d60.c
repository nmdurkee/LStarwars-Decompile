/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x479d60; label: FUN_00479d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00479d60(void)

{
  char cVar1;
  int in_ECX;
  int in_EDX;
  
  if (((*(char *)(in_ECX + 0x281) != '\0') &&
      (((cVar1 = *(char *)(in_ECX + 0x7b5), cVar1 == -1 || (cVar1 == '1')) || (cVar1 == '2')))) &&
     ((in_EDX == -1 || (*(char *)(in_ECX + 0x285) == in_EDX)))) {
    return 1;
  }
  return 0;
}

