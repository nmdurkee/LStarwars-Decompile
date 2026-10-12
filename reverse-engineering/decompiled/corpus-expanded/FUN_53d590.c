/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d590; label: FUN_0053d590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0053d590(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = in_ECX + 0x96800;
  while( true ) {
    if (in_ECX == iVar1) {
      return 0;
    }
    if (*(int *)(in_ECX + 0x4b0) == 0) break;
    in_ECX = in_ECX + 0x4b4;
  }
  *(undefined4 *)(in_ECX + 0x4b0) = 1;
  return in_ECX;
}

