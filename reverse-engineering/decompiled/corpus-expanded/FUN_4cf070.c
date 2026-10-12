/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cf070; label: FUN_004cf070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cf070(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if (((param_3 & 1) == 0) || (*(byte *)(iVar1 + 0x4e) == param_2)) {
      if (param_2 != 0) {
        *(undefined1 *)(iVar1 + 0x4e) = 0;
        return 1;
      }
      if (*(char *)(iVar1 + 0x4e) == '\0') {
        *(undefined1 *)(iVar1 + 0x4e) = 1;
      }
      return 1;
    }
  }
  return 0;
}

