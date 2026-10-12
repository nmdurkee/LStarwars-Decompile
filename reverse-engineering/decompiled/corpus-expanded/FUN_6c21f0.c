/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c21f0; label: FUN_006c21f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_006c21f0(void)

{
  char *pcVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xc) == 0) ||
     (pcVar1 = (char *)(*(int *)(in_ECX + 0xc) + 1), pcVar1 == (char *)0x0)) {
    pcVar1 = "No Name";
  }
  return pcVar1;
}

