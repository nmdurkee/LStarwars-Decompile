/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4efc00; label: FUN_004efc00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004efc00(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = *param_1 + 0x10; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

